//Khóa học Lập trình STM32
//Bài: Kiểm tra phím bấm
//MCU: STM32F103R8T6
//lpson @ Elec2PCB.com
//Email: elec2pcb@gmail.com
//Mobile: 0905-912-019

#include "mbed.h"

DigitalIn  KEY1(PC_13); // Khai báo chân PC_13 là ngõ vào số, gán tên là KEY1
DigitalOut LED01(PD_2); // Khai báo chân PD_2 là ngõ ra số, gán tên là LED01

int main()
{
    // Tùy chọn: các mode là PullUp/PullDown/PullNone/OpenDrain
    KEY1.mode(PullUp); 
    
    //Bấm phím và xem trạng thái LED thay đổi
    while(1) {
        LED01 = KEY1.read(); // Trạng thái LED thay đổi theo mức logic tại chân KEY1
        wait(0.25);          //Đợi 0.25s
    }
}

    