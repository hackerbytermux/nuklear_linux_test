#include "temp_sensor.hh"
#include <string.h>

namespace temp_sensor{
    int cur_temp = 25;
    void* temp_thread(void* thread_data){
        int fd = open("/dev/ttyS2", O_RDWR | O_NOCTTY | O_SYNC);
        printf("[TempSensor]: starting...\n");
        if (fd == -1) {
            printf("Error opening %s\n", strerror(errno));
            pthread_exit(0);
        }

        termios options;
        tcgetattr(fd, &options);
        options.c_cflag = B9600 | CS8 | CLOCAL | CREAD;
        options.c_iflag = IGNPAR;
        options.c_oflag = 0;
        options.c_lflag = 0;
        tcflush(fd, TCIFLUSH);
        tcsetattr(fd, TCSANOW, &options);
        printf("[TempSensor]: reading thread started\n");
        while (true) {
            struct timeval tv;
            tv.tv_sec = 1;
            tv.tv_usec = 0;
            select(fd+1, NULL, NULL, NULL, &tv);

            char buf[10];
            int n = read(fd, buf, sizeof(buf));
            if (n > 0) {
                buf[n] = '\0';
                temp_sensor::cur_temp = atoi(buf);
                printf("temp: %d\n", temp_sensor::cur_temp);
                printf("target temp: %d\n", target_temp);
            }
        }

        close(fd);
        pthread_exit(0);
    }

    void start(){
        void* thread_data = NULL;
        pthread_t thread;
        pthread_create(&thread, NULL, temp_thread, thread_data);
    }
    int get_temp(){
        return cur_temp;
    }
}