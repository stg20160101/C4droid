/*
计数排序
bug: 负数
author: stg20160101
date: 2017-09-02
*/

#include <stdio.h>

//计数排序
void BucketSort(int arr[],int len)
{
	int max=arr[0];
	int i,j;
	int* tmpArr;
	//获取源数组最大数
	for(i=1;i<len;i++)
		if(max<arr[i])
			max=arr[i];
	//申请桶空间并置0
	tmpArr=(int*)malloc(sizeof(int)*(max+1));
	memset(tmpArr,0,sizeof(int)*(max+1));
	//将源数组的值当作桶空间下标并标记
	for(i=0;i<len;i++)
		tmpArr[arr[i]]++;
	//遍历桶空间，将非0值的下标依次赋值给源数组
	for(i=0,j=0;i<(max+1);i++)
	{
		//printf("%d ",tmpArr[i]);
		while(tmpArr[i]!=0)
		{
			arr[j++]=i;
			tmpArr[i]--;
		}
	}
	//printf("\n");
	free(tmpArr);
}

int main(void)
{
	int arr[10]={0,9,8,1,2,7,6,3,1,15};
	int len=10;
	int i;
	BucketSort(arr,len);
	for(i=0;i<len;i++)
		printf("%d ",arr[i]);
	printf("\n");
	
	return 0;
}

/*
桶空间大小=max-min+1
*/