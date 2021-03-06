/*============================================================
工程：字符型液晶通用六线驱动（FOR STM32F103）

液晶指令说明：
0x01-------------->清除屏幕，置AC为0，光标回位。
0x02-------------->DDRAM 地址为0，显示回原位，DDRAM内容不变.
0x03-------------->DDRAM 地址为0，显示回原位，DDRAM内容不变.
0x04-------------->设置光标移动方向减量方式，并指定显示不移动。
0x05-------------->设置光标移动方向减量方式，并指定显示移动。
0x06-------------->设置光标移动方向增量方式，并指定显示不移动。
0x07-------------->设置光标移动方向增量方式，并指定显示移动。
0x08-------------->设置显示关、光标关、光标所在字符不闪烁.
0x0c-------------->显示开
0x0e-------------->显示开，光标开
0x0f-------------->显示开，光标开，光标闪烁
0x10-------------->光标移位，左移
0x14-------------->光标移位，右移
0x18-------------->显示移位，左移
0x1c-------------->显示移位，右移
0x20-------------->4BIT模式，显示一行，5x7字体
0x24-------------->4BIT模式，显示一行，5x10字体
0x28-------------->4BIT模式，显示两行，5x7字体
0x2c-------------->4BIT模式，显示两行，5x10字体
0x30-------------->8BIT模式，显示一行，5x7字体
0x34-------------->8BIT模式，显示一行，5x10字体
0x38-------------->8BIT模式，显示两行，5x7字体
0x3c-------------->8BIT模式，显示两行，5x10字体
0x30-------------->8BIT模式，显示一行，5x7字体
0x30-------------->8BIT模式，显示一行，5x7字体
0x30-------------->8BIT模式，显示一行，5x7字体
0x30-------------->8BIT模式，显示一行，5x7字体

显示地址：
===============================================================
=0x00 0x01 0x02 0x03 0x04 0x05 0x06 0x07 ................ 0x27=
=0x40 0x41 0x42 0x43 0x44 0x45 0x46 0x47 ................ 0x67=
===============================================================
每行可以显示40个字符，可以看到的只有16个字符，可以通过指令使字符
整体移动来显示所有字符。
四线控制的方式：先送字节的高四位，再送低四位。
值得注意的是当使用的I/O口为高四位时数据先给另一个变量，变量再将
数据高四位送到I/O口，接着是将变量左移四位，再送到I/O口上去。
当使用的I/O口为低四位时数据先给另一个变量，变量右移四位后送到I/O
口上去，接着将数据给变量直接送入I/O口。
使用时注意一下。
============================================================*/
#ifndef __Lcd_1602_6wires_h
#define __Lcd_1602_6wires_h 1

//定义MCU与LCD的接口
/*******************************
*D4---->PA4
*D5---->PA5
*D6---->PA6
*D7---->PA7
*RS---->PA13
*RW---->PA14
*EN---->PA15

LCD1602
VCC---->5V
GND---->GND
VO----->接对比度调节滑动变阻器
LED+ -->5v
LED- -->GND
*********************************/

#define SET_RS()	    GPIO_SetBits(GPIOA,GPIO_Pin_13)
#define CLR_RS()	    GPIO_ResetBits(GPIOA,GPIO_Pin_13)
#define SET_RW()	    GPIO_SetBits(GPIOA,GPIO_Pin_14)
#define CLR_RW()	    GPIO_ResetBits(GPIOA,GPIO_Pin_14)
#define SET_EN()	    GPIO_SetBits(GPIOA,GPIO_Pin_15)
#define CLR_EN()	    GPIO_ResetBits(GPIOA,GPIO_Pin_15)


/*-----------------------------------------------------
                     函数声明
-------------------------------------------------------*/
void LCD_DATA_DIR_IN(void);
void LCD_DATA_DIR_OUT(void);
unsigned char lcd_read_status (void);
unsigned char wait_while_busy (void);
void lcd_write_4bit (unsigned char c);
void lcd_write_cmd (unsigned char c);
void lcd_write_data (unsigned char c);

extern void lcd_init       (void);
extern void lcd_clear      (void);
extern void lcd_putchar    (char c);
extern void set_cursor     (int column, int line);
extern void lcd_print      (char *string);
extern void lcd_bargraph   (int value, int size);
extern void lcd_bargraphXY (int pos_x, int pos_y, int value);
//==================================================
#endif

