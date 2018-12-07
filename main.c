#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "struct.h"
#include "declare.h"
int main(int argc, char *argv[]) {
	system("chcp 65001");
	system("cls");
	int a;
	College x[16];
	a=inputCollegeInfo("C_Info1.txt",x);
	sortCollegeInfoById(UP,x,a);
	for(a=0;a<=9;a++)
	{
		printf("%d %s\n",x[a].id,x[a].name);
	}
	return 0;
}
