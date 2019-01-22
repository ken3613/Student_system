#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include "struct.h"
#include "declare.h"

extern Student stus[100];
extern College cols[10];
extern Sex sexs[3];
extern int stu_num,col_num,sex_num;
extern const char base64_alphabet[64];

void print_table(int n,char c)
{
	int i;
	for(i=0;i<=n-1;i++)
		putchar(c);
}

int wherex()
{
    CONSOLE_SCREEN_BUFFER_INFO pBuffer;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &pBuffer);
    return (pBuffer.dwCursorPosition.X+1);
}

int wherey()
{
    CONSOLE_SCREEN_BUFFER_INFO pBuffer;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &pBuffer);
    return (pBuffer.dwCursorPosition.Y+1);
}

void gotoxy(int x,int y) 
{
    COORD c;
    c.X=x-1;
    c.Y=y-1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
    
char cmove_bits(unsigned char src, unsigned lnum, unsigned rnum) 
{
    src <<= lnum; // src = src << lnum;
    src >>= rnum; // src = src >> rnum;
    return src;
}

int base64_encode(const char *indata, int inlen, char *outdata, int *outlen) 
{
    
    int ret = 0,i; // return value
    if (indata == NULL || inlen == 0) {
        return ret = -1;
    }
    
    int in_len = 0; // 源字符串长度, 如果in_len不是3的倍数, 那么需要补成3的倍数
    int pad_num = 0; // 需要补齐的字符个数, 这样只有2, 1, 0(0的话不需要拼接, )
    if (inlen % 3 != 0) {
        pad_num = 3 - inlen % 3;
    }
    in_len = inlen + pad_num; // 拼接后的长度, 实际编码需要的长度(3的倍数)
    
    int out_len = in_len * 8 / 6; // 编码后的长度
    
    char *p = outdata; // 定义指针指向传出data的首地址
    
    //编码, 长度为调整后的长度, 3字节一组
    for (i = 0; i < in_len; i+=3) {
        int value = *indata >> 2; // 将indata第一个字符向右移动2bit(丢弃2bit)
        char c = base64_alphabet[value]; // 对应base64转换表的字符
        *p = c; // 将对应字符(编码后字符)赋值给outdata第一字节
        
        //处理最后一组(最后3字节)的数据
        if (i == inlen + pad_num - 3 && pad_num != 0) {
            if(pad_num == 1) {
                *(p + 1) = base64_alphabet[(int)(cmove_bits(*indata, 6, 2) + cmove_bits(*(indata + 1), 0, 4))];
                *(p + 2) = base64_alphabet[(int)cmove_bits(*(indata + 1), 4, 2)];
                *(p + 3) = '=';
            } else if (pad_num == 2) { // 编码后的数据要补两个 '='
                *(p + 1) = base64_alphabet[(int)cmove_bits(*indata, 6, 2)];
                *(p + 2) = '=';
                *(p + 3) = '=';
            }
        } else { // 处理正常的3字节的数据
            *(p + 1) = base64_alphabet[cmove_bits(*indata, 6, 2) + cmove_bits(*(indata + 1), 0, 4)];
            *(p + 2) = base64_alphabet[cmove_bits(*(indata + 1), 4, 2) + cmove_bits(*(indata + 2), 0, 6)];
            *(p + 3) = base64_alphabet[*(indata + 2) & 0x3f];
        }
        
        p += 4;
        indata += 3;
    }
    
    if(outlen != NULL) {
        *outlen = out_len;
    }
    
    return ret;
}


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
	fclose(fp);
	return num;
}

int inputStudentInfo(char * filename,Student x[])
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
	for(i=0;i<=num;i++)
	{
		fscanf(fp,"%d %s %d %d %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf",&x[i].id,x[i].name,&x[i].sid,&x[i].cid,&x[i].score[0],&x[i].score[1],&x[i].score[2],&x[i].score[3],&x[i].score[4],&x[i].score[5],&x[i].score[6],&x[i].score[7],&x[i].score[8],&x[i].score[9]);
	}
	countAvg(x,num);
	fclose(fp);
	return num;
}

int inputSexInfo(char * filename,Sex x[])
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
	fclose(fp);
	return num;
}

void countAvg(Student x[],int num)
{
	int i,j;
	double sum;
	for(i=0;i<=num-1;i++)
	{
		sum=0;
		for(j=0;j<=9;j++)
		{
			sum+=x[i].score[j];
		}
		x[i].avg=sum/10;
	}
}

void print_stu()
{
	int i;
	printf("学号   姓名   性别\t学院\t\t科目一 科目二 科目三 科目四 科目五 科目六 科目七 科目八 科目九 科目十 平均分\n");
	for(i=0;i<=stu_num-1;i++)
	{
		printf("%d %s %s\t%-10s\t%6.2lf %6.2lf %6.2lf %6.2lf %6.2lf %6.2lf %6.2lf %6.2lf %6.2lf %6.2lf %6.2lf\n",stus[i].id,stus[i].name,sexs[stus[i].sid].name,cols[stus[i].cid-1].name,stus[i].score[0],stus[i].score[1],stus[i].score[2],stus[i].score[3],stus[i].score[4],stus[i].score[5],stus[i].score[6],stus[i].score[7],stus[i].score[8],stus[i].score[9],stus[i].avg);
	}
}

void print_studentById(int id)
{
	int i;
	printf("学号   姓名   性别\t学院\t\t科目一 科目二 科目三 科目四 科目五 科目六 科目七 科目八 科目九 科目十 平均分\n");
	for(i=0;i<=stu_num-1;i++)
	{
		if(stus[i].id==id)
		{
			printf("%d %s %s\t%-10s\t%6.2lf %6.2lf %6.2lf %6.2lf %6.2lf %6.2lf %6.2lf %6.2lf %6.2lf %6.2lf %6.2lf\n",stus[i].id,stus[i].name,sexs[stus[i].sid].name,cols[stus[i].cid-1].name,stus[i].score[0],stus[i].score[1],stus[i].score[2],stus[i].score[3],stus[i].score[4],stus[i].score[5],stus[i].score[6],stus[i].score[7],stus[i].score[8],stus[i].score[9],stus[i].avg);
		}
	}
}

int find_studentIndexById(int id)
{
	int i;
	for(i=0;i<=stu_num-1;i++)
	{
		if(stus[i].id==id)
		{
			return i;
		}
	}	
}

void changeId(int id,int nid)
{
	int i,index;
	FILE *fp;
	for(i=0;i<=stu_num-1;i++)
	{
		if(stus[i].id==nid)
		{
			showMsg("学号重复！修改失败！");
			return;
		}
	}
	index=find_studentIndexById(id);
	stus[index].id=nid;
	fp=fopen("data\\Stu_Info3.txt","w");
	fprintf(fp,"#开头为注释。注释后的第一行为学生数\n#注释后的第二行开始\n#学号,姓名,性别,学院和10门成绩\n%d\n",stu_num);
	for(i=0;i<=stu_num-1;i++)
	{
		fprintf(fp,"%d %s %d %d %.0lf %.0lf %.0lf %.0lf %.0lf %.0lf %.0lf %.0lf %.0lf %.0lf\n",stus[i].id,stus[i].name,stus[i].sid,stus[i].cid,stus[i].score[0],stus[i].score[1],stus[i].score[2],stus[i].score[3],stus[i].score[4],stus[i].score[5],stus[i].score[6],stus[i].score[7],stus[i].score[8],stus[i].score[9]);	
	}
	fclose(fp);
	inputStudentInfo("data\\Stu_Info3.txt",stus);
	showMsg("修改成功！");
}

void changeName(int id,char * nname)
{
	int index,i;
	FILE *fp;
	index=find_studentIndexById(id);
	strcpy(stus[index].name,nname);
	fp=fopen("data\\Stu_Info3.txt","w");
	fprintf(fp,"#开头为注释。注释后的第一行为学生数\n#注释后的第二行开始\n#学号,姓名,性别,学院和10门成绩\n%d\n",stu_num);
	for(i=0;i<=stu_num-1;i++)
	{
		fprintf(fp,"%d %s %d %d %.0lf %.0lf %.0lf %.0lf %.0lf %.0lf %.0lf %.0lf %.0lf %.0lf\n",stus[i].id,stus[i].name,stus[i].sid,stus[i].cid,stus[i].score[0],stus[i].score[1],stus[i].score[2],stus[i].score[3],stus[i].score[4],stus[i].score[5],stus[i].score[6],stus[i].score[7],stus[i].score[8],stus[i].score[9]);	
	}
	fclose(fp);
	inputStudentInfo("data\\Stu_Info3.txt",stus);
	showMsg("修改成功！");
}

void changeSex(int id,int nsid)
{
	int index,i;
	FILE *fp;
	index=find_studentIndexById(id);
	stus[index].sid=nsid;
	fp=fopen("data\\Stu_Info3.txt","w");
	fprintf(fp,"#开头为注释。注释后的第一行为学生数\n#注释后的第二行开始\n#学号,姓名,性别,学院和10门成绩\n%d\n",stu_num);
	for(i=0;i<=stu_num-1;i++)
	{
		fprintf(fp,"%d %s %d %d %.0lf %.0lf %.0lf %.0lf %.0lf %.0lf %.0lf %.0lf %.0lf %.0lf\n",stus[i].id,stus[i].name,stus[i].sid,stus[i].cid,stus[i].score[0],stus[i].score[1],stus[i].score[2],stus[i].score[3],stus[i].score[4],stus[i].score[5],stus[i].score[6],stus[i].score[7],stus[i].score[8],stus[i].score[9]);	
	}
	fclose(fp);
	inputStudentInfo("data\\Stu_Info3.txt",stus);
	showMsg("修改成功！");
}

void changeCollege(int id,int ncol)
{
	int index,i;
	FILE *fp;
	index=find_studentIndexById(id);
	stus[index].cid=ncol;
	fp=fopen("data\\Stu_Info3.txt","w");
	fprintf(fp,"#开头为注释。注释后的第一行为学生数\n#注释后的第二行开始\n#学号,姓名,性别,学院和10门成绩\n%d\n",stu_num);
	for(i=0;i<=stu_num-1;i++)
	{
		fprintf(fp,"%d %s %d %d %.0lf %.0lf %.0lf %.0lf %.0lf %.0lf %.0lf %.0lf %.0lf %.0lf\n",stus[i].id,stus[i].name,stus[i].sid,stus[i].cid,stus[i].score[0],stus[i].score[1],stus[i].score[2],stus[i].score[3],stus[i].score[4],stus[i].score[5],stus[i].score[6],stus[i].score[7],stus[i].score[8],stus[i].score[9]);	
	}
	fclose(fp);
	inputStudentInfo("data\\Stu_Info3.txt",stus);
	showMsg("修改成功！");
}

void changeScore(int id,int sid,int nscore)
{
	int index,i;
	FILE *fp;
	index=find_studentIndexById(id);
	stus[index].score[sid-1]=nscore;
	fp=fopen("data\\Stu_Info3.txt","w");
	fprintf(fp,"#开头为注释。注释后的第一行为学生数\n#注释后的第二行开始\n#学号,姓名,性别,学院和10门成绩\n%d\n",stu_num);
	for(i=0;i<=stu_num-1;i++)
	{
		fprintf(fp,"%d %s %d %d %.0lf %.0lf %.0lf %.0lf %.0lf %.0lf %.0lf %.0lf %.0lf %.0lf\n",stus[i].id,stus[i].name,stus[i].sid,stus[i].cid,stus[i].score[0],stus[i].score[1],stus[i].score[2],stus[i].score[3],stus[i].score[4],stus[i].score[5],stus[i].score[6],stus[i].score[7],stus[i].score[8],stus[i].score[9]);	
	}
	fclose(fp);
	inputStudentInfo("data\\Stu_Info3.txt",stus);
	showMsg("修改成功！");
}

void print_studentByCollegeId(int cid)
{
	int i;
	printf("学号   姓名   性别\t学院\t\t科目一 科目二 科目三 科目四 科目五 科目六 科目七 科目八 科目九 科目十 平均分\n");
	for(i=0;i<=stu_num-1;i++)
	{
		if(stus[i].cid==cid)
		{
			printf("%d %s %s\t%-10s\t%6.2lf %6.2lf %6.2lf %6.2lf %6.2lf %6.2lf %6.2lf %6.2lf %6.2lf %6.2lf %6.2lf\n",stus[i].id,stus[i].name,sexs[stus[i].sid].name,cols[stus[i].cid-1].name,stus[i].score[0],stus[i].score[1],stus[i].score[2],stus[i].score[3],stus[i].score[4],stus[i].score[5],stus[i].score[6],stus[i].score[7],stus[i].score[8],stus[i].score[9],stus[i].avg);
		}
	}	
}

void print_studentByName(char * name)
{
	int i;
	printf("学号   姓名   性别\t学院\t\t科目一 科目二 科目三 科目四 科目五 科目六 科目七 科目八 科目九 科目十 平均分\n");
	for(i=0;i<=stu_num-1;i++)
	{
		if(strcmp(stus[i].name,name)==0)
		{
			printf("%d %s %s\t%-10s\t%6.2lf %6.2lf %6.2lf %6.2lf %6.2lf %6.2lf %6.2lf %6.2lf %6.2lf %6.2lf %6.2lf\n",stus[i].id,stus[i].name,sexs[stus[i].sid].name,cols[stus[i].cid-1].name,stus[i].score[0],stus[i].score[1],stus[i].score[2],stus[i].score[3],stus[i].score[4],stus[i].score[5],stus[i].score[6],stus[i].score[7],stus[i].score[8],stus[i].score[9],stus[i].avg);
		}
	}
}

void sort_studentByAvg(enum sort_method method)
{
	int i,j,flag;
	Student tmp;
		switch(method)
	{
		case UP:
			{
				for(i=0;i<=stu_num-1;i++)
				{
					flag=i;
					for(j=i+1;j<=stu_num-1;j++)
					{
						if(stus[j].avg<stus[flag].avg)
							flag=j;
					}
					if(flag!=i)
					{
						tmp=stus[i];
						stus[i]=stus[flag];
						stus[flag]=tmp;
					}
				}
				break;
			}
		case DOWN:
			{
				for(i=0;i<=stu_num-1;i++)
				{
					flag=i;
					for(j=i+1;j<=stu_num-1;j++)
					{
						if(stus[j].avg>stus[flag].avg)
							flag=j;
					}
					if(flag!=i)
					{
						tmp=stus[i];
						stus[i]=stus[flag];
						stus[flag]=tmp;
					}
				}
				break;
			}
	}
}

void sort_studentByName(enum sort_method method)
{
	int i,j,flag;
	Student tmp;
	switch(method)
	{
		case UP:
			{
				for(i=0;i<=stu_num-1;i++)
				{
					flag=i;
					for(j=i+1;j<=stu_num-1;j++)
					{
						if(strcmp(stus[j].name,stus[flag].name)<0)
							flag=j;
					}
					if(flag!=i)
					{
						tmp=stus[i];
						stus[i]=stus[flag];
						stus[flag]=tmp;
					}
				}
				break;
			}
		case DOWN:
			{
				for(i=0;i<=stu_num-1;i++)
				{
					flag=i;
					for(j=i+1;j<=stu_num-1;j++)
					{
						if(strcmp(stus[j].name,stus[flag].name)>0)
							flag=j;
					}
					if(flag!=i)
					{
						tmp=stus[i];
						stus[i]=stus[flag];
						stus[flag]=tmp;
					}
				}
				break;
			}
	}
}

void menu(enum menu_type m_type)
{
	int i;
	switch(m_type)
	{
		case MainMenu:
			{
				system("cls");
				gotoxy(36,3);
				print_table(50,'=');
				for(i=0;i<=7;i++)
				{
					gotoxy(36,i+4);
					putchar('=');
					putchar(' ');
					puts(main_str[i]);
					gotoxy(85,i+4);
					putchar('=');
				}
				gotoxy(36,i+5);
				print_table(50,'=');
				gotoxy(85,i+4);
				putchar('=');
				gotoxy(36,i+4);
				printf("= 请输入功能代码按回车确认：");
				
				break;
			}
		case CollegeMenu:
			{
				system("cls");
				gotoxy(36,3);
				print_table(50,'=');
				for(i=0;i<=col_num-1;i++)
				{
					gotoxy(36,i+4);
					printf("= %d.%s",cols[i].id,cols[i].name);
					gotoxy(85,i+4);
					putchar('=');
				}
				gotoxy(36,i+5);
				print_table(50,'=');
				gotoxy(85,i+4);
				putchar('=');
				gotoxy(36,i+4);
				printf("= 请输入学院代码按回车确认：");
			}
	}
}

int check_pwd(char * pwd)
{
	FILE *fp;
	char password[32],b_pwd[32]={'\0'};
	fp=fopen("PASSWORD","r");
	fscanf(fp,"%s",password);
	base64_encode(pwd,strlen(pwd),b_pwd,NULL);
	fclose(fp);
	if(strcmp(b_pwd,password)==0)
	{
		return 1;
	}
	else
	{
	return 0;
	}
}

int login()
{
	int check,i=0;
	char c;
    gotoxy(36,1);
	print_table(50,'=');
	putchar('\n');
	print_table(35,' ');
	putchar('=');
	gotoxy(85,2);
	putchar('=');
	gotoxy(1,3);;
	print_table(35,' ');
	print_table(50,'=');
	gotoxy(37,2);
	char pwd[16]={'\0'};
	printf("请输入密码：");
	while(i<=16)
	{
		c=getch();
		if(c>=33 && c<=122)
		{
			pwd[i]=c;
			putch('*');
			i++;
		}
		else if(c=='\b' && i>0)
		{
			pwd[i]='\0';
			_cputs("\b \b");
			i--;
		}
		else if(c=='\r' || c=='\n')
		{
			check=check_pwd(pwd);
			if(!check)
			{
				system("cls");
				gotoxy(58,2);
				puts("密码错误！");
				system("pause");
				return 0;
			}
			else
			{
				system("cls");
				return 1;
			}
		}
	}
	if(i>16)
	{
		system("cls");
		gotoxy(58,2);
		puts("密码错误！");
		system("pause");
		return 0;
	}
}

void changePwd()
{
	FILE *fp;
	int i=0;
	char c,pwd[16]={'\0'},b64pwd[32]={'\0'};
	while(i<=16)
	{
		c=getch();
		if(c>=33 && c<=122)
		{
			pwd[i]=c;
			putch('*');
			i++;
		}
		else if(c=='\b' && i>0)
		{
			pwd[i]='\0';
			_cputs("\b \b");
			i--;
		}
		else if(c=='\r' || c=='\n')
		{
			putch('\n');
			fp=fopen("PASSWORD","w");
			base64_encode(pwd,strlen(pwd),b64pwd,NULL);
			fprintf(fp,"%s",b64pwd);
			fclose(fp);
			printf("修改密码成功！\n");
			system("pause");
			break;
		}
	}
}

void showMsg(char * msg)
{
	system("cls");
	puts(msg);
	system("pause");
}

