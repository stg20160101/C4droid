/*
结构体变量与结构体指针的"."和"->"
author: stg20160101
date: 2017-09-03
*/

#include <stdio.h>

typedef struct Stu {
	int i;
	int* p;
} STU, * PSTU;

int main(void)
{
	STU stu;
	PSTU pStu;
	
	stu.i=0;
	stu.p=NULL;
	//stu->p=NULL; //error
	pStu->i=0;
	pStu->p=NULL;
	//pStu.i->=0; //error
	
	return 0;
}