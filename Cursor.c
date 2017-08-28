#include <stdio.h>
int main(void) 
{
	int x=5; //col
	int y=2; //row
	
	printf("test");
	printf("\033[%d;%dH",y,x); //(x,y)
	printf("test");
	
   return 0;
}

/*
\r	 光标移到行首	  
\b	 退格	  
“\033[2J”	 清屏	清屏后光标还在原来位置
“\033[H”	 光标复位，回到左上角（1行1列）	  
“\033[%d;%dH”, y, x	 设置光标到y行x列	 从1开始数
“\033[%dA”, y	 光标上移y行	  
“\033[%dB”, y	 光标下移y行	  
“\033[%dD”, x	 光标左移x列	  
“\033[%dC”, x	 光标右移x列	  
“\033[?25l”	 隐藏光标
“\033[?25h”	 显示光标
*/