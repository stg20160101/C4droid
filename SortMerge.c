/*
归并排序
author: stg20160101
date: 2017-09-01
*/

#include <stdio.h>

void Merge(int srcArr[],int tmpArr[],int start,int mid,int end)
{
	int i,j,k;
	i=start;
	j=mid+1;
	k=start;
	while(i!=mid+1&&j!=end+1)
	{
		if(srcArr[i]>srcArr[j])
			tmpArr[k++]=srcArr[i++];
		else
			tmpArr[k++]=srcArr[j++];
	}
	while(i!=mid+1)
		tmpArr[k++]=srcArr[i++];
	while(j!=end+1)
		tmpArr[k++]=srcArr[j++];
	for(i=start;i<=end;i++)
		srcArr[i]=tmpArr[i];
}

void MergeSort(int srcArr[],int tmpArr[],int start,int end)
{
	int mid;
	if(start<end)
	{
		mid=(start+end)/2;
		MergeSort(srcArr,tmpArr,start,mid);
		MergeSort(srcArr,tmpArr,mid+1,end);
	Merge(srcArr,tmpArr,start,mid,end);
	}
}

int main(void)
{
	int srcArr[10]={0,9,8,1,2,7,6,3,4,5};
	int tmpArr[10];
	int i;
	MergeSort(srcArr,tmpArr,0,9);
	for(i=0;i<10;i++)
		printf("%d ",srcArr[i]);
	printf("\n");
	
	return 0;
}

/*
归并过程为：比较a[i]和b[j]的大小，若a[i]≤b[j]，则将第一个有序表中的元素a[i]复制到r[k]中，并令i和k分别加上1；否则将第二个有序表中的元素b[j]复制到r[k]中，并令j和k分别加上1，如此循环下去，直到其中一个有序表取完，然后再将另一个有序表中剩余的元素复制到r中从下标k到下标t的单元。

归并排序的算法我们通常用递归实现，先把待排序区间[s,t]以中点二分，接着把左边子区间排序，再把右边子区间排序，最后把左区间和右区间用一次归并操作合并成有序的区间[s,t]。
*/