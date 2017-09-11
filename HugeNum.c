/*
大数运算
author: stg20160101
date: 2017-09-12
*/

#include <stdio.h>
#include <stdlib.h>

#define MAXNUM 0xFFFFFFFF

typedef struct HugeNode {
	unsigned int val;
	struct HugeNode* next;
} NODE, * PNODE;

typedef struct HugeNum {
	int len;
	PNODE head;
} NUM, * PNUM;

//初始化
void Init(PNUM num)
{
	num->len=0;
	num->head=0;
	return;
}

//添加节点
void Add(PNUM num,unsigned int val)
{
	PNODE new=0;
	PNODE tail=num->head;
	new=(PNODE)malloc(sizeof(NODE));
	if(!new) exit(-1);
	new->val=val;
	new->next=0;
	if(!num->head)
	{
		num->head=new;
		num->len++;
		return;
	}
	while(tail->next) tail=tail->next;
	tail->next=new;
	num->len++;
	return;
}

//清空节点
void Clean(PNUM num)
{
	PNODE tmp=num->head;
	PNODE next;
	if(!num->head)
	{
		num->len=0;
		return;
	}
	while(tmp)
	{
		next=tmp->next;
		free(tmp);
		tmp=next;
	}
	num->len=0;
	num->head=0;
	return;
}

void Rm(PNODE head,int* len)
{
	PNODE tail=head->next;
	if(tail==0)
		return;
	if(tail->next!=0)
		Rm(tail,len);
	if(tail->val==0&&tail->next==0)
	{
		free(tail);
		head->next=0;
		(*len)--;
	}
	return;
}

//删除高位0
void Rm0(PNUM num)
{
	Rm(num->head,&(num->len));
	return;
}

//加法，和保存在n1
void Plus(PNUM n1,PNUM n2)
{
	PNODE tail1=n1->head;
	PNODE tail2=n2->head;
	PNODE tmp;
	int i;
	//被加数比加数短，高位补0
	for(i=n1->len;i<n2->len;i++)
		Add(n1,0);
	//防止最高位进位
	Add(n1,0);
	//逐位相加
	while(1)
	{
		if(!tail2)
			break;
		//进位
		if(MAXNUM-tail1->val<tail2->val)
		{
			tail1->next->val+=1;
			tmp=tail1->next;
			while(tmp->val-1==MAXNUM)
			{
				tmp->next->val+=1;
				tmp=tmp->next;
			}
		}
		tail1->val+=tail2->val;
		tail1=tail1->next;
		tail2=tail2->next;
	}
	Rm0(n1);
	return;
}

int main(void)
{
	NUM n1,n2;
	PNODE tmp;
	Init(&n1);
	Init(&n2);
	Add(&n1,0xffffffff);
	Add(&n1,0xffffffff);
	Add(&n1,0xffffffff);
	Add(&n1,0);
	Add(&n1,1);
	Add(&n2,0xffffffff);
	Add(&n2,0xffffffff);
	Add(&n2,1);
	Plus(&n1,&n2);
	printf("%d ",n1.len);
	tmp=n1.head;
	while(tmp)
	{
		printf("%X ",tmp->val);
		tmp=tmp->next;
	}
	Clean(&n1);
	Clean(&n2);
	
	return 0;
}