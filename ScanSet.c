/*
扫描集
author: stg20160101
date: 2017-09-12
*/

#include <stdio.h>

int main(void)
{
	char str[5];
	//以字符a为结束字符
	//scanf("%[^a]",str);
	//printf("%s\nstr: ",str);
	//以非数字为结束字符
	scanf("%[0-9]",str);
	printf("%s",str);
	
	return 0;
}