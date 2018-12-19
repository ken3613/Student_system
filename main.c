#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "struct.h"
#include "declare.h"
int main(int argc, char *argv[]) {
	unsigned int func_code;
	int i,stu_num=0,col_num=0,sex_num=0;
	system("mode con cols=120 lines=100");
	login();
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
					stu_num=inputCollegeInfo("data\\C_Info1.txt",cols);
					col_num=inputStudentInfo("data\\Stu_Info3.txt",stus);
					sex_num=inputSexInfo("data\\S_Info2.txt",sexs);
					if(stu_num!=0 && col_num!=0 && sex_num!=0)
					{
						showMsg("文件读取成功！");
					}
					break;
				}
			case 2:
				{
					for(i=0;i<=99;i++) printf("%s\n",stus[i].name);
					system("pause");
					break;
				}
		}
	}while(1);
	return 0;
}
