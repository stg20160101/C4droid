/*
冒泡排序
author: stg20160101
date: 2017-09-01
*/

#include <stdio.h>

void BubbleSort(int arr[],int len)
{
	int i,j;
	int temp;
	/*
	//左<--右
	for(i=0;i<len-1;i++)
		for(j=len-1;j>i;j--)
			if(arr[j-1]<arr[j])
			{
				temp=arr[j-1];
				arr[j-1]=arr[j];
				arr[j]=temp;
			}
		*/
		//左-->右
		for(i=len-1;i>0;i--)
			for(j=0;j<i;j++)
				if(arr[j]<arr[j+1])
				{
					temp=arr[j];
					arr[j]=arr[j+1];
					arr[j+1]=temp;
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