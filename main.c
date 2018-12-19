#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "struct.h"
#include "declare.h"

Student stus[100];
College cols[10];
Sex sexs[3];
int stu_num=0,col_num=0,sex_num=0;

int main(int argc, char *argv[]) {
	unsigned int func_code;
	int i;
	system("mode con cols=120 lines=100");
	//login();
	do
	{
		menu(MainMenu);
		fflush(stdin);
		scanf("%d",&func_code);
		switch(func_code)
		{
			case 0:
				{
					exit(0); 
				}
			case 1:
				{
					col_num=inputCollegeInfo("data\\C_Info1.txt",cols);
					stu_num=inputStudentInfo("data\\Stu_Info3.txt",stus);
					sex_num=inputSexInfo("data\\S_Info2.txt",sexs);
					if(stu_num!=0 && col_num!=0 && sex_num!=0)
					{
						showMsg("文件读取成功！");
					}
					break;
				}
			case 2:
				{
					menu(CollegeMenu);
					fflush(stdin);
					scanf("%d",&func_code);
					break;
				}
			case 4:
				{
					menu(CollegeMenu);
					fflush(stdin);
					scanf("%d",&func_code);
					
					break;
				}
		}
	}while(1);
	return 0;
}
