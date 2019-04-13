//Khóa học Lập trình STM32
//Bài: Dem 2 LED 7seg 
//MCU: STM32F103R8T6
//lpson @ Elec2PCB.com
//Email: elec2pcb@gmail.com
//Mobile: 0905-912-019
#include "mbed.h"

//4 7seg pin: 1     2     3     4     5     6     7     8     9     10     11     12
//            e     d     h     c     g     L1    b     L2    L3    f      a      L4  
//            PB_11 PB_1  PC_5  PA_7  PA_5  PA_3  PA_2  PA_4  PA_6  PC_4   PB_0   PB_10  

// 7seg LED - a, b, c, d, e, f, g, DP 
BusOut LED7seg(PB_0, PA_2, PA_7, PB_1, PB_11, PC_4, PA_5, PC_5); //h=>dot/DP
/*
DigitalOut EN_LED1(PA_3) ;
DigitalOut EN_LED2(PA_4) ;
DigitalOut EN_LED3(PA_6) ;
DigitalOut EN_LED4(PB_10) ;
*/
DigitalOut LED_D1(PD_2);
BusOut EN_LED(PA_3,PA_4,PA_6,PB_10);
 
int main() {
    //dễ dàng thay đổi các LED1,2,3,4 sáng
    EN_LED = 0b0001;
    //EN_LED = 0b0010;
    //EN_LED = 0b0100;
    //EN_LED = 0b1000;
    
    LED_D1 = 1;
    // 7seg LED bit pattern -  Dgfe dcba     
    const int n0 = 0x3F;    // 0011 1111
    const int n1 = 0x06;    // 0000 0110
    const int n2 = 0x5B;    // 0101 1011
    const int n3 = 0x4F;    // 0100 1111
    const int n4 = 0x66;    // 0110 0110
    const int n5 = 0x6D;    // 0110 1101
    const int n6 = 0x7D;    // 0111 1101
    const int n7 = 0x07;    // 0000 0111
    const int n8 = 0x7F;    // 0111 1111
    const int n9 = 0x6F;    // 0110 1111
 
    // convert: count -> 7seg number
    const int seg[] = {n0, n1, n2, n3, n4, n5, n6, n7, n8, n9};
    
    int nCntX = 0;          // 7seg LED1 counter

    
    // port init
    LED7seg = ~0;
  
    
    while(1) {

        for(int delay=0;delay<100;delay++){
            for(int i=0;i<70;i++){
                EN_LED = 0b0010;
                LED7seg =  ~seg[nCntX/10];    // Hàng chục
            }
            for(int i=0;i<70;i++){
                EN_LED = 0b0001;
                LED7seg =  ~seg[nCntX%10];    // Hàng đơn vị
            }
        }
                     
        nCntX++;
        // 7seg LED limit count 99
        if (100 == nCntX) {
            nCntX = 0;
        }
        
    }
}