//Khóa học Lập trình STM32
//Bài: Giao tiếp với máy tính qua cổng COM
//lpson @ Elec2PCB.com
//Email: elec2pcb@gmail.com
//Mobile: 0905-912-019

#include <mbed.h>

#define LED_BUILTIN PD_2    //định nghĩa LED_BUILTIN tại chân PD_2
#define SERIAL2_TX  PA_2    //định nghĩa SERIAL2_TX tại chân PA_2  
#define SERIAL2_RX  PA_3    //định nghĩa SERIAL2_RX tại chân PA_3  

//Khai báo một cổng nối tiếp tại chân PA_2,PA_3, tốc đôk baud: 115200
Serial serial2(SERIAL2_TX, SERIAL2_RX, 115200);

int main()
{
    serial2.printf("Hello world...\n");

    while (1)
    {
        if(serial2.readable()) {				//Nếu nhận được data
            serial2.putc(serial2.getc());		//Gửi đi ký tự vừa nhận
            serial2.printf("Send by STM32\n");	//Gửi đi 1 dòng chữ 
        }
        
    }
}
