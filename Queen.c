/*
八皇后问题:回溯法
author: stg20160101
date: 2017-08-31
*/

#include <stdio.h>
#include <math.h>
#define N 8

//显示皇后的位置
void showQueen(int queenArr[],int len,int cnt)
{
	int i,j;
	printf("---Queen position:%d---\n",cnt);
	for(i=0;i<len;i++)
	{
		/*
		if(queenArr[i]==-1)
		{
			for(j=0;j<len;j++)
				printf("0 ");
			printf("\n");
			continue;
		}
		*/
		//每行皇后前面位置
		for(j=0;j<queenArr[i];j++)
			printf("0 ");
		//每行皇后的位置
		printf("1 ");
		//每行皇后后面位置
		for(j=0;j<len-queenArr[i]-1;j++)
			printf("0 ");
		printf("\n");
	}
}

//判断当前行皇后与之前行皇后位置是否有冲突
int isClash(int queenArr[],int row)
{
	int i;
	for(i=0;i<row;i++)
	{
		//是否同列
		if(queenArr[row]==queenArr[i])
		return 1;
		//是否同斜线
		if(abs(queenArr[row]-queenArr[i])==abs(row-i))
		return 1;
	}
	return 0;
}

//放置每一行的皇后
void putQueen(int queenArr[],int row,int len,int* cnt)
{
	int i;
	for(i=0;i<len;i++)
	{
		//逐一遍历当前行每一列
		queenArr[row]=i;
		//如果没冲突
		if(!isClash(queenArr,row))
		{
			//如果当前行是末行
			if(row==len-1)
			{
				(*cnt)++;
				showQueen(queenArr,len,*cnt);
			}
			else
			//不是末行则放置下一行皇后
				putQueen(queenArr,row+1,len,cnt);
		}
	}
}

int main(void)
{
	//每行皇后的位置
	int queenArr[N];
	//统计解决方案的个数
	int cnt=0;
	//从第0行开始放置皇后
	putQueen(queenArr,0,N,&cnt);
	
	return 0;
}