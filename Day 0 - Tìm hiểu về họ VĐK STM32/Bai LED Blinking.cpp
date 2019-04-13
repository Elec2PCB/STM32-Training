//Khóa học Lập trình STM32
//Bài: Nhấp nháy LED đơn
//MCU: STM32F103R8T6
//lpson @ Elec2PCB.com
//Email: elec2pcb@gmail.com
//Mobile: 0905-912-019

#include <mbed.h>

#define LED_BUILTIN PD_2    //định nghĩa LED_BUILTIN tại chân PD_2
#define SERIAL1_TX PA_9     //định nghĩa SERIAL2_TX tại chân PA_9
#define SERIAL1_RX PA_10    //định nghĩa SERIAL2_RX tại chân PA_10

//Khai báo một cổng nối tiếp tại chân PA_9,PA_10, tốc đôk baud: 115200
Serial serial1(SERIAL1_TX, SERIAL1_RX, 115200);
//Khai báo gán chân LED_BUILTIN/PD_2 như là ngõ ra và đặt tên là led
DigitalOut led(LED_BUILTIN);

int main()
{
    
    serial1.printf("STM32 bluepill mbed test.\n");

    while (1)
    {
        led = 0;        //turn ON
        wait_ms(100);
        led = 1;
        wait_ms(500);   //turn OFF
        serial1.printf("Blinking...\n");
    }
}

