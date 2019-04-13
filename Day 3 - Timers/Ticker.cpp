//Khóa học Lập trình STM32
//Bài: Ticker
//MCU: STM32F103R8T6
//lpson @ Elec2PCB.com
//Email: elec2pcb@gmail.com
//Mobile: 0905-912-019
#include "mbed.h"
Ticker flipper;
DigitalOut led1(PD_2);
DigitalOut led2(PA_8);
void flip() {
    led2 = !led2;
}
int main() {
    led2 = 1;
    flipper.attach(&flip, 2.0); //sau mỗi 2s gọi hàm flip một lần
    while(1) {
        led1 = !led1;
        wait(0.2);
    }
}
