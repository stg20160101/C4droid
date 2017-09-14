/*
判断大尾/小尾模式
author: stg20160101
date: 2017-09-14
*/

#include <stdio.h>

union Check {
	char ch;
	int i;
} c;

int CheckSystem()
{
	c.i=1;
	return (c.ch==1);
}

int main(void)
{
	if(CheckSystem()==0)
		printf("Big endian");
	else
		//01 00 00 00
		printf("Little endian");
		
	return 0;
}