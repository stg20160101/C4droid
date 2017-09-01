/*
基数排序
author: stg20160101
date: 2017-09-02
*/

#include <stdio.h>

//寻找数组最大数
int FindMax(int arr[],int len)
{
	int max=arr[0];
	int i;
	for(i=1;i<len;i++)
		if(max<arr[i])
			max=arr[i];
	return max;
}

//获取val的第cnt位
int GetNum(int val, int cnt)
{
	int result=-1;
	while(cnt)
	{
		result=val%10;
		val/=10;
		cnt--;
	}
	return result;
}

//桶排序
void BucketSort(int arr[],int len,int cnt)
{
	int i,j,k;
	//桶空间 [0-9]*N
	int tmpArr[10][10];
	for(i=0;i<10;i++)
			tmpArr[i][0]=0;
	//将源数组的值当作桶空间下标并标记和保存
	for(i=0;i<len;i++)
	{
		j=GetNum(arr[i],cnt);
		k=tmpArr[j][0];
		tmpArr[j][k+1]=arr[i];
		tmpArr[j][0]++;
	}
	//遍历桶空间，将非0值的下标依次赋值给源数组
	for(i=0,j=0;i<10;i++)
	{
		k=1;
		while(tmpArr[i][0]!=0)
		{
			arr[j++]=tmpArr[i][k++];
			tmpArr[i][0]--;
		}
	}
	/*
	for(i=0;i<len;i++)
		printf("%d ",arr[i]);
	printf("\n");
	*/
	free(tmpArr);
}

//基数排序
void RadixSort(int arr[],int len)
{
	//寻找源数组最大数
	int max=FindMax(arr,len);
	int cnt=1;
	int i;
	max/=10;
	while(max!=0)
	{
		//计算最大数的位数
		cnt++;
		max/=10;
	}
	//从最低位到最高位依次进行桶排序
	for(i=1;i<=cnt;i++)
		BucketSort(arr,len,i);
}

int main(void)
{
	int arr[]={99,12,55,1,26,70,22,16};
	int len=sizeof(arr)/sizeof(int);
	int i;
	RadixSort(arr,len);
	for(i=0;i<len;i++)
		printf("%d ",arr[i]);
	printf("\n");
	
	return 0;
}

/*
将所有待比较数值（正整数）统一为同样的数位长度，数位较短的数前面补零。然后，从最低位开始，依次进行一次排序。这样从最低位排序一直到最高位排序完成以后, 数列就变成一个有序序列。
*/