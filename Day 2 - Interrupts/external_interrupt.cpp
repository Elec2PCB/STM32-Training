//Khóa học Lập trình STM32
//Bài: Ngắt Ngoài
//MCU: STM32F103R8T6
//lpson @ Elec2PCB.com
//Email: elec2pcb@gmail.com
//Mobile: 0905-912-019

#include "mbed.h"

InterruptIn KEY1(PC_13); //Khai báo một ngõ vào ngắt tại chân PC_13 và gán là KEY1
DigitalOut LED01(PD_2);	 //Khai báo một ngõ ra tại chân PD_2 và gán tên LED01
DigitalOut flash(PA_8);	 //Khai báo một ngõ ra tại chân PA_8 và gán tên flash

void ISR1() { 			//Chương trình ngắt thực thi ở đây
    LED01 = !LED01;		//khi có sường lên tại chân KEY1, chương trình chính sẽ
}						//thực hiện xong câu lênh đang thực thi và tạm dừng để
						//nhảy tới đây và thực hiện, sau đó sẽ nhảy quay trở lại
						//đoạn chương trình chính để thực hiện tiếp

int main() {
    KEY1.mode(PullUp); 	//Cho phép trở kéo lên tại chân KEY1
    KEY1.rise(&ISR1); 	// Gán địa chỉ hàm ngắt ISR, khai báo ngắt sường lên 

    while(1) { // continuous loop, ready to be interrupted
        flash = !flash;	//Đảo trạng thái logic tại chân flash (nhấp nháy LED)
        wait(1);		//đợi 1s
    }
}
