/*
快速排序
author: stg20160101
date: 2017-09-01
*/

#include <stdio.h>

//寻找第一个元素正确位置
//其左边比他小，右边比他大
int FindPos(int arr[],int low,int high)
{
	int val=arr[low];
	while(low<high)
	{
		while(low<high&&arr[high]>=val)
			high--;
		arr[low]=arr[high];
		while(low<high&&arr[low]<=val)
			low++;
		arr[high]=arr[low];
	}
	arr[low]=val;
	
	return low;
}

void QuickSort(int arr[],int low,int high)
{
	int pos;
	if(low<high)
	{
		pos=FindPos(arr,low,high);
		QuickSort(arr,low,pos-1);
		QuickSort(arr,pos+1,high);
	}
}

int main(void)
{
	int arr[10]={0,9,8,1,2,7,6,3,4,5};
	int i;
	QuickSort(arr,0,9);
	for(i=0;i<10;i++)
		printf("%d ",arr[i]);
	printf("\n");
	
	return 0;
}