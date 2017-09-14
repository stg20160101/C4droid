#include <stdio.h>

/*
在实际问题中，有些变量的取值被限定在一个有限的范围内，那么可以使用枚举来列举变量的范围。
变量从0开始自动+1赋值，如果对于赋值的元素，后面的元素在此基础上开始+1赋值。
*/

enum Week {
	Monday = 1,  //1
	Tuesday,     //2
	Wednesday,   //3
	Thursday,    //4
	Friday = 'a',//a
	Saturday,    //b
	Sunday //c
} a, b;

int main(void)
{
	a=Monday;
	b=Sunday;
	//a=1; //error
	//b=13; //error
	printf("%p %p\n",&a,&b);
	printf("%d %c\n",a,b);
	
	return 0;
}