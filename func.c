#include <stdio.h>
#include <stdlib.h>
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

void sortCollegeInfoById(enum sort_method method,College x[],int num)
{
	int i,j,flag;
	College tmp;
	switch(method)
	{
		case UP:
			{
				for(i=0;i<=num-1;i++)
				{
					flag=i;
					for(j=i+1;j<=num-1;j++)
					{
						if(x[j].id<x[flag].id)
							flag=j;
					}
					if(flag!=i)
					{
						tmp=x[i];
						x[i]=x[flag];
						x[flag]=tmp;
					}
				}
				break;
			}
		case DOWN:
			{
				for(i=0;i<=num-1;i++)
				{
					flag=i;
					for(j=i+1;j<=num-1;j++)
					{
						if(x[j].id>x[flag].id)
							flag=j;
					}
					if(flag!=i)
					{
						tmp=x[i];
						x[i]=x[flag];
						x[flag]=tmp;
					}
				}
				break;
			}
	}
}
