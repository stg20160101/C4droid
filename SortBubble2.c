/*
双向冒泡排序
author: stg20160101
date: 2017-09-01
*/

#include <stdio.h>

void swap(int* a,int* b)
{
	int temp=(*a);
	(*a)=(*b);
	(*b)=temp;
}

void BubbleSort(int arr[],int len)
{
	int i;
	int flag=1;
	while(flag)
	{
		flag=0;
		for(i=0;i<len-1;i++)
			if(arr[i]<arr[i+1])
			{
				flag=1;
				swap(&arr[i],&arr[i+1]);
			}
		for(i=len-1;i>0;i--)
			if(arr[i]>arr[i-1])
			{
				flag=1;
				swap(&arr[i],&arr[i-1]);
			}
	}
}

int main(void)
{
	int arr[10]={0,9,8,1,2,7,6,3,4,5};
	int len=10;
	int i;
	BubbleSort(arr,len);
	for(i=0;i<len;i++)
		printf("%d ",arr[i]);
	printf("\n");
	
	return 0;
}