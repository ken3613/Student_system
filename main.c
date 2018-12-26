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
	int i,id,tid,tscore;
	char stmp[20];
	system("mode con cols=120 lines=100");
	if(!login())
		exit(1);
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
			case 5:
				{
					system("cls");
					printf("请输入需要修改的学生学号：");
					fflush(stdin);
					scanf("%d",&id);
					print_studentById(id);
					printf("1.学号\n2.姓名\n3.性别\n4.学院\n5.成绩\n请输入要修改的信息：");
					scanf("%d",&func_code);
					switch(func_code)
					{
						case 1:
							{
								printf("\n请输入修改后的学号：");
								scanf("%d",&tid);
								changeId(id,tid);
								break;
							}
						case 2:
							{
								printf("\n请输入修改后的姓名：");
								scanf("%s",stmp);
								changeName(id,stmp);
								break;
							}
						case 3:
							{
								printf("0.女\n1.男\n2.未填\n请输入修改后的性别：");
								scanf("%d",&tid);
								changeSex(id,tid);
								break;
							}
						case 4:
							{
								printf("1.信息学院\n2.计算机学院\n3.文法学院\n4.外国语学院\n5.数理学院\n6.会金学院\n7.化工学院\n8.商学院\n9.航空学院\n10.艺术学院\n请输入修改后的学院：");
								scanf("%d",&tid);
								changeCollege(id,tid);
								break;
							}
						case 5:
							{
								for(i=1;i<=10;i++)
								{
									printf("%d.科目%d\n",i,i);
								}
								printf("请输入要修改的科目与成绩，以空格分隔：");
								scanf("%d %d",&tid,&tscore);
								changeScore(id,tid,tscore);
								break;
							}
					}
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
			case 7:
				{
					system("cls");
					if(login())
					{
						printf("请输入新密码(1-16个字符)，按回车确认：");
						changePwd();
						break;
					}
					else
					{
						break;
					}
				}
		}
	}while(1);
	return 0;
}
