#include "gps.h"
#include "hal.h"

static char sog[10];
static char cog[10];
static char lat[10];
static char lon[10];
static char time[10];
static char date[10];

double speed = 0;

static volatile size_t read_buf = 0, write_buf = 0;
static volatile char buffer[256] = {0};
static int buffer_size = 256;

static char msg[100] = {0};
static int msg_index = 0;

static bool newData = false;



void gps_update_buffer(void){
    while (uart_read_ready(USART1)){
        buffer[write_buf] = uart_read_byte(USART1);
        write_buf = (write_buf + 1) % 256;
    }
}

bool gps_is_new_data(void){
    bool temp = newData;
    newData = false;
    return temp;
}

char* gps_get_time(void){
    return time;
}


void update_gps_data(void) {
    if (read_buf != write_buf) {
        if (buffer[read_buf] != '\0') {
            msg[msg_index++] = buffer[read_buf];
            if (buffer[read_buf] == '\n') {
                if (strncmp(msg, "$GNRMC", 6) == 0) {
                    newData = true;

                    // Copy message to temp for parsing
                    char temp[msg_index];
                    strncpy(temp, msg, msg_index);
                    temp[msg_index] = '\0';  // Ensure null termination

                    int start = 0;
                    int token_count = 0;
                    char *token = NULL;

                    for (int i = 0; i <= msg_index; i++) {
                        if (temp[i] == ',' || temp[i] == '\0') {
                            int token_len = i - start;

                            if (token_len > 0) {
                                token = (char *)malloc(token_len + 1);
                                if (token == NULL) {
                                    printf("Memory allocation failed\n");
                                    return;  // Exit function on allocation failure
                                }
                                strncpy(token, &temp[start], token_len);
                                token[token_len] = '\0';

                                // Debugging output for each token
                                // printf("Token %d: '%s'\n", token_count, token);

                                switch (token_count) {
                                    case 1:
                                        strncpy(time, token, sizeof(time) - 1);
                                        // printf("Time: %s\n", time);
                                        break;
                                    case 3:
                                        strncpy(lat, token, sizeof(lat) - 1);
                                        // printf("Latitude: %s\n", lat);
                                        break;
                                    case 5:
                                        strncpy(lon, token, sizeof(lon) - 1);
                                        // printf("Longitude: %s\n", lon);
                                        break;
                                    case 7:
                                        strncpy(sog, token, sizeof(sog) - 1);
                                        // printf("Speed Over Ground: %s\n", sog);
                                        break;
                                    case 8:
                                        strncpy(cog, token, sizeof(cog) - 1);
                                        // printf("Course Over Ground: %s\n", cog);
                                        break;
                                    case 9:
                                        strncpy(date, token, sizeof(date) - 1);
                                        // printf("Date: %s\n", date);
                                        break;
                                }

                                free(token);  // Free after processing each token
                            }
                            token_count++;
                            start = i + 1;
                        }
                    }
                }
                msg_index = 0;  // Reset msg_index for the next message
            }
        }
        read_buf = (read_buf + 1) % buffer_size;
    }
}

