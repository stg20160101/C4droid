/*
插入排序
author: stg20160101
date: 2017-09-01
*/

#include <stdio.h>

void InsertSort(int arr[],int len)
{
	int i,j;
	int temp;
	//从第2个元素开始
	for(i=1;i<len;i++)
	{
		//取出插入元素
		temp=arr[i];
		for(j=i-1;j>=0;j--)
			//小于插入元素的数后移
			if(arr[j]<temp)
				arr[j+1]=arr[j];
			else
				break;
		//插入
		arr[j+1]=temp;
	}
}

int main(void)
{
	int arr[10]={0,9,8,1,2,7,6,3,4,5};
	int len=10;
	int i;
	InsertSort(arr,len);
	for(i=0;i<len;i++)
		printf("%d ",arr[i]);
	printf("\n");
	
	return 0;
}