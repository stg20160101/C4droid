/*
	最大公约数
	Greatest Common Divisor
	Author: stg20160101
	Date: 2017-11-12
	
	最小公倍数=a*b/GCD
	Least Common Multiple
	
	66=2*3*11
	12=2*2*3
	(66,12)=2*3
	[66,12]=2*2*3*11
*/

#include <stdio.h>

//更相减损法
//66/2=33 12/2=6
//33-6=27 27-6=21 21-6=15
//15-6=9 9-6=3 6-3=3
//(66,12)=3*2^1
int GCD1(int a,int b)
{
	int nCnt=0;
	int c;
	if(a==0 || b==0)
		return 0;
	while(a%2==0 && b%2==0)
	{
		++nCnt;
		a/=2;
		b/=2;
	}
	while(a!=b)
	{
		if(a<b)
		{c=a;a=b;b=c;}
		a=a-b;
	}
	return a<<nCnt; //a*2^nCnt
}

//辗转相除法
//66/12=5->6
//12/6=2->0
//(66,12)=(12,6)=6
int GCD2(int a,int b)
{
	int c;
	if(a==0 || b==0)
		return 0;
	while((a=a%b)!=0)
	{
		//a%=b;
		if(a<b)
		{c=a;a=b;b=c;}
	}
	return b;
}

int GCD(int a,int b)
{
	int n = a<b?a:b;
	while(n>1)
	{
		if(a%n==0 && b%n==0)
			break;
		--n;
	}
	return n;
}

int LCM(int a,int b)
{
	int n=a>b?a:b;
	if(a==0 || b==0)
		return 0;
	while(1)
	{
		if(n%a==0 && n%b==0)
			break;
		++n;
	}
	return n;
}

int main(void)
{
	int a=66,b=12,c=3;
	printf("%d\n",GCD(a,b));
	printf("%d\n",GCD1(a,b));
	printf("%d\n",GCD2(a,b));
	printf("%d\n",LCM(a,b));
	printf("%d\n",a*b/GCD(a,b));
	printf("%d\n",GCD(c,GCD(a,b)));
	
	return 0;
}