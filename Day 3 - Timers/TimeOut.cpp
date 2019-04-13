//Khóa học Lập trình STM32
//Bài: TimeOut
//MCU: STM32F103R8T6
//lpson @ Elec2PCB.com
//Email: elec2pcb@gmail.com
//Mobile: 0905-912-019

#include "mbed.h"
 
Timer t;
 
int main() {
    t.start();
    printf("Hello World!\n");
    t.stop();
    //in ra giá trị mà Timer đã trải qua
    printf("The time taken was %f seconds\n",t.read());
}
