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
						showMsg("�ļ���ȡ�ɹ���");
					}
					break;
				}
			case 2:
				{
					system("mode con lines=120");
					system("cls");
					printf("0.����\n1.����\n���������򷽷����س�ȷ�ϣ�");
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
					printf("0.����\n1.����\n���������򷽷����س�ȷ�ϣ�");
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
					printf("��������Ҫ�޸ĵ�ѧ��ѧ�ţ�");
					fflush(stdin);
					scanf("%d",&id);
					print_studentById(id);
					printf("1.ѧ��\n2.����\n3.�Ա�\n4.ѧԺ\n5.�ɼ�\n������Ҫ�޸ĵ���Ϣ��");
					scanf("%d",&func_code);
					switch(func_code)
					{
						case 1:
							{
								printf("\n�������޸ĺ��ѧ�ţ�");
								scanf("%d",&tid);
								changeId(id,tid);
								break;
							}
						case 2:
							{
								printf("\n�������޸ĺ��������");
								scanf("%s",stmp);
								changeName(id,stmp);
								break;
							}
						case 3:
							{
								printf("0.Ů\n1.��\n2.δ��\n�������޸ĺ���Ա�");
								scanf("%d",&tid);
								changeSex(id,tid);
								break;
							}
						case 4:
							{
								printf("1.��ϢѧԺ\n2.�����ѧԺ\n3.�ķ�ѧԺ\n4.�����ѧԺ\n5.����ѧԺ\n6.���ѧԺ\n7.����ѧԺ\n8.��ѧԺ\n9.����ѧԺ\n10.����ѧԺ\n�������޸ĺ��ѧԺ��");
								scanf("%d",&tid);
								changeCollege(id,tid);
								break;
							}
						case 5:
							{
								for(i=1;i<=10;i++)
								{
									printf("%d.��Ŀ%d\n",i,i);
								}
								printf("������Ҫ�޸ĵĿ�Ŀ��ɼ����Կո�ָ���");
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
					printf("������ѧ���������س�ȷ�ϣ�");
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
						printf("������������(1-16���ַ�)�����س�ȷ�ϣ�");
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
