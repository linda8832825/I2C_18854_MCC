//#include "mcc_generated_files/mcc.h"
//
//void main(void){
//    SYSTEM_Initialize();
////    uint8_t I2C1_Read1ByteRegister(i2c1_address_t 0x4E, uint8_t 0x4E);//reg:SLAVE的站存器
//    while (1)
//    {
//        RA1=1;
//        __delay_ms(5000);
//        RA1=0;
//        __delay_ms(1000);
//    }
//}
///**
// End of File
//*/
//
//#define LCD_ADDRESS 0x27 // change this according to ur setup
//
//#define LCD_COLS 20
//#define LCD_ROWS 4

#include "mcc_generated_files/mcc.h"
#include "i2c.h"
#include "lcd.h"
#include <htc.h>

void main(void){
    SYSTEM_Initialize();
    RA1=0;
    __delay_ms(1000);
    RA1=1;
    __delay_ms(2000);
    RA1=0;
    
//    __delay_ms(1000);
//    RC4=0;
//    __delay_ms(1000);
//    RC4=1;
//    __delay_ms(2000);
//    RC4=0;
//    __delay_ms(1000);
    
    
    LCD_init(0x4E);
//    LCD_init(uint8_t LCD_ADDRESS, uint8_t LCD_COLS, uint8_t LCD_ROWS);
//    LCD_init(0x4E, 20, 4);
//    LCD_backlight(true);
//    __delay_ms(2000);
//    LCD_backlight(false);
//    __delay_ms(2000);
//    LCD_backlight(true);
//    LCD_send_string("|d|100|....................\0", 1);
//    LCD_send_string("|c|hello world\0", 3);
//
//    __delay_ms(1000);
//
//    LCD_backlight(false);
//
//    __delay_ms(500);
//    
//    LCD_send_string("|r|backlight off\0", 4);
//
//    __delay_ms(500);
//
//    LCD_backlight(true);
//    LCD_send_string("|r|backlight on\0", 4);
//
//    __delay_ms(1000);
//
//    LCD_clear();
//    LCD_send_string("|c|01234567890123456789012\n|l|abcdefghijklmnopqrstuvwxyz\n|r|abcdefghijklmnopqrstuvwxyz\n|r|01234567890123456789012\0", 1);
//
//    __delay_ms(1000);
//    
//    LCD_clear();
//    LCD_send_string("|c|center\n|l|left\n|r|right\nEND\0", 1);

    while (1){

    }
}