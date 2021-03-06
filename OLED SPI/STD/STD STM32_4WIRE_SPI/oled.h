//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//使用SysTick的普通计数模式对延迟进行管理
//包括delay_us,delay_ms
//冰火青云电子
//店铺地址：http://shop73023976.taobao.com/shop/view_shop.htm?tracelog=twddp&trace_log=qianniu_pc
//修改日期:2014/3/16
//版本：V1.0
//版权所有，盗版必究。
//Copyright(C) 冰火青云电子2014/3/16
//All rights reserved
//********************************************************************************


#ifndef __OLED_H
#define __OLED_H			  	 
#include "sys.h"
#include "stdlib.h"	    

//OLED模式设置
//0:4线串行模式

#define OLED_MODE 0
		    						  
//-----------------OLED端口定义----------------  					   

#define OLED_CS_Clr()  GPIO_ResetBits(GPIOD,GPIO_Pin_6)//CS
#define OLED_CS_Set()  GPIO_SetBits(GPIOD,GPIO_Pin_6)

#define OLED_RST_Clr() GPIO_ResetBits(GPIOG,GPIO_Pin_15)//RES
#define OLED_RST_Set() GPIO_SetBits(GPIOG,GPIO_Pin_15)

#define OLED_RS_Clr() GPIO_ResetBits(GPIOD,GPIO_Pin_3)//DC
#define OLED_RS_Set() GPIO_SetBits(GPIOD,GPIO_Pin_3)

#define OLED_WR_Clr() GPIO_ResetBits(GPIOG,GPIO_Pin_14)
#define OLED_WR_Set() GPIO_SetBits(GPIOG,GPIO_Pin_14)

#define OLED_RD_Clr() GPIO_ResetBits(GPIOG,GPIO_Pin_13)
#define OLED_RD_Set() GPIO_SetBits(GPIOG,GPIO_Pin_13)



//PC0~7,作为数据线
#define DATAOUT(x) GPIO_Write(GPIOC,x);//输出  
//使用4线串行接口时使用 

#define OLED_SCLK_Clr() GPIO_ResetBits(GPIOC,GPIO_Pin_0)//CLK
#define OLED_SCLK_Set() GPIO_SetBits(GPIOC,GPIO_Pin_0)

#define OLED_SDIN_Clr() GPIO_ResetBits(GPIOC,GPIO_Pin_1)//DIN
#define OLED_SDIN_Set() GPIO_SetBits(GPIOC,GPIO_Pin_1)

 		     
#define OLED_CMD  0	//写命令
#define OLED_DATA 1	//写数据
//OLED控制用函数
void OLED_WR_Byte(u8 dat,u8 cmd);	    
void OLED_Display_On(void);
void OLED_Display_Off(void);
void OLED_Refresh_Gram(void);		   
							   		    
void OLED_Init(void);
void OLED_Clear(void);
void OLED_DrawPoint(u8 x,u8 y,u8 t);
void OLED_Fill(u8 x1,u8 y1,u8 x2,u8 y2,u8 dot);
void OLED_ShowCHinese(u8 x,u8 y,u8 no);
void OLED_ShowChar(u8 x,u8 y,u8 chr,u8 size,u8 mode);
void OLED_ShowNum(u8 x,u8 y,u32 num,u8 len,u8 size);
void OLED_ShowString(u8 x,u8 y,const u8 *p);	 
void LCD_Set_Pos(u8 x, u8 y) ;
#endif  
	 



