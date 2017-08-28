#include <stdio.h>
#include <time.h>
int main(void)
{
	time_t rawtime;
	struct tm*  timeinfo;
	clock_t start, finish;
	long i=10000000L;
	
	time(&rawtime);
	timeinfo=localtime(&rawtime);
	printf("%s", asctime(timeinfo));
	
	start=clock();
	while(i--);
	finish=clock();
	printf("%f\n", (double)(finish-start)/CLOCKS_PER_SEC);
	
	return 0;
}