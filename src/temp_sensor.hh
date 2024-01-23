#include <fcntl.h>
#include <errno.h>
#include <termios.h>
#include <unistd.h>
#include <pthread.h>
#include <iostream>

namespace temp_sensor{
    static int target_temp = 30;
    void* temp_thread(void* thread_data);
    void start();
    int get_temp();
}