/*
选择排序
author: stg20160101
date: 2017-09-01
*/

#include <stdio.h>

void SelectSort(int arr[],int len)
{
	int i,j;
	int temp;
	int max;
	for(i=0;i<len-1;i++)
	{
		max=i;
		for(j=i+1;j<len;j++)
			if(arr[max]<arr[j])
				max=j;
		if(max!=i)
		{
			temp=arr[i];
			arr[i]=arr[max];
			arr[max]=temp;
		}
	}
}

int main(void)
{
	int arr[10]={0,9,8,1,2,7,6,3,4,5};
	int len=10;
	int i;
	SelectSort(arr,len);
	for(i=0;i<len;i++)
		printf("%d ",arr[i]);
	printf("\n");
	
	return 0;
}