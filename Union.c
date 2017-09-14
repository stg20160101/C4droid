/*
联合
author: stg20160101
date: 2017-09-14
*/

#include <stdio.h>

//三个成员共用一块内存空间
//大小由最大变量数据类型决定
union test {
	char a;
	short b;
	int i;
} t;

int main(void)
{
	t.i=0x12345678;
	printf("%d\n",sizeof(t));
	printf("%p %p %p\n",&t.i,&t.a,&t.b);
	printf("%#x %#x %#x",t.i,t.a,t.b);
	
	return 0;
}