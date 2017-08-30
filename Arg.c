/*
执行程序时，可以从命令行传值给 C 程序／命令行参数是使用 main() 函数参数来处理的，其中，argc 是指传入参数的个数，argv[] 是一个指针数组，指向传递给程序的每个参数
argv[0] = 文件名
*/

#include <stdio.h>
int main( int argc, char* argv[] )  
{
	while(argc != 0)
	{
		argc--;
		printf("%s\n",argv[argc]);
	}
}