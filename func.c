#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"

int inputCollegeInfo(char * filename,College x[])
{
	int num,i;
	char tempstr[256];
	FILE *fp;
	if((fp=fopen(filename,"r"))==NULL)
	{
		printf("Can not open file.");
		exit(1);
	}
	while((fscanf(fp,"%d",&num))==0)
	{
		fscanf(fp,"%s",tempstr);
	}
	for(i=0;i<=num-1;i++)
	{
		fscanf(fp,"%d %s",&x[i].id,x[i].name);
	}
	return num;
}

void menu(enum menu_type m_type)
{
	switch(m_type)
	{
		case MainMenu:
			{
				printf("�����빦�ܴ��밴�س�ȷ�ϣ�\n1.ѧԺ����\n");
				break;
			}
	}
}

int login(char * pwd)
{
	return 0;
}
