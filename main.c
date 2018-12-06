#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int inputCollegeInfo(char * filename,College x[]);
int main(int argc, char *argv[]) {
	int a;
	College x[16];
	a=inputCollegeInfo("C_Info1.txt",x);
	for(a=0;a<=9;a++)
	{
		printf("%d %s\n",x[a].id,x[a].name);
	}
	return 0;
}
