#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "struct.h"
#include "declare.h"

Student stus[100];
College cols[10];
Sex sexs[3];
int stu_num=0,col_num=0,sex_num=0;

int main(int argc, char *argv[]) {
	unsigned int func_code;
	int i;
	char stmp[20];
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
					system("mode con lines=120");
					system("cls");
					printf("0.升序\n1.降序\n请输入排序方法按回车确认：");
					scanf("%d",&func_code);
					sort_studentByName(func_code);
					print_stu();
					system("pause");
					system("mode con cols=120 lines=100");
					break;
				}
			case 3:
				{
					system("mode con lines=120");
					system("cls");
					printf("0.升序\n1.降序\n请输入排序方法按回车确认：");
					scanf("%d",&func_code);
					sort_studentByAvg(func_code);
					print_stu();
					system("pause");
					system("mode con cols=120 lines=100");
					break;
				}
			case 4:
				{
					system("mode con lines=120");
					menu(CollegeMenu);
					fflush(stdin);
					scanf("%d",&func_code);
					print_studentByCollegeId(func_code);
					system("pause");
					system("mode con cols=120 lines=100");
					break;
				}
			case 6:
				{
					system("mode con lines=120");
					system("cls");
					printf("请输入学生姓名按回车确认：");
					scanf("%s",stmp);
					print_studentByName(stmp);
					system("pause");
					system("mode con cols=120 lines=100");
					break;
				}
		}
	}while(1);
	return 0;
}
