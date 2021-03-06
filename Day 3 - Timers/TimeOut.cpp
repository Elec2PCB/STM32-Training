//Khóa học Lập trình STM32
//Bài: TimeOut
//MCU: STM32F103R8T6
//lpson @ Elec2PCB.com
//Email: elec2pcb@gmail.com
//Mobile: 0905-912-019
#include "mbed.h"
Timeout flipper;
DigitalOut led1(PA_8);
DigitalOut led2(PD_2);
void flip() {
    led2 = !led2;
}
int main() {
    led2 = 1;
    flipper.attach(&flip, 2.0); // Gọi hàm flip sau 2s
    // spin in a main loop. flipper will interrupt it to call flip
    while(1) {
        led1 = !led1;
        wait(0.2);
    }
}
