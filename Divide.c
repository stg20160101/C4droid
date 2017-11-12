/*
负整形数的整除与求模
author: stg20160101
date: 2017-10-5
*/

#include <stdio.h>

int main(void)
{
	int i;
	for(i=10;i>=-10;i--)
	{
		//向零取整
		printf("%d\/4=%d\n",i,i/4);
		//向下取整
		printf("%d>>2=%d\n",i,i>>2);
		printf("\n");
	}
	
	return 0;
}

/*
Q=A/B
R=A%B
A=Q*B+R
R=A-Q*B=A-(A/B)*B
余数的符号与被除数相同
*/