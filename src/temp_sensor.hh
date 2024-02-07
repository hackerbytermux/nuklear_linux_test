#include <fcntl.h>
#include <errno.h>
#include <termios.h>
#include <unistd.h>
#include <pthread.h>
#include <iostream>

namespace temp_sensor{
    extern int cur_temp;
    extern int target_temp;
    void* temp_thread(void* thread_data);
    void start();
    int get_temp();
}