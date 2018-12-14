#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include "struct.h"
#include "declare.h"

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

static const char base64_alphabet[] = {
    'A', 'B', 'C', 'D', 'E', 'F', 'G',
    'H', 'I', 'J', 'K', 'L', 'M', 'N',
    'O', 'P', 'Q', 'R', 'S', 'T',
    'U', 'V', 'W', 'X', 'Y', 'Z',
    'a', 'b', 'c', 'd', 'e', 'f', 'g',
    'h', 'i', 'j', 'k', 'l', 'm', 'n',
    'o', 'p', 'q', 'r', 's', 't',
    'u', 'v', 'w', 'x', 'y', 'z',
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
    '+', '/'};
    
static char cmove_bits(unsigned char src, unsigned lnum, unsigned rnum) 
	{
    src <<= lnum; // src = src << lnum;
    src >>= rnum; // src = src >> rnum;
    return src;
	}

int base64_encode(const char *indata, int inlen, char *outdata, int *outlen) {
    
    int ret = 0,i; // return value
    if (indata == NULL || inlen == 0) {
        return ret = -1;
    }
    
    int in_len = 0; // Դ�ַ�������, ���in_len����3�ı���, ��ô��Ҫ����3�ı���
    int pad_num = 0; // ��Ҫ������ַ�����, ����ֻ��2, 1, 0(0�Ļ�����Ҫƴ��, )
    if (inlen % 3 != 0) {
        pad_num = 3 - inlen % 3;
    }
    in_len = inlen + pad_num; // ƴ�Ӻ�ĳ���, ʵ�ʱ�����Ҫ�ĳ���(3�ı���)
    
    int out_len = in_len * 8 / 6; // �����ĳ���
    
    char *p = outdata; // ����ָ��ָ�򴫳�data���׵�ַ
    
    //����, ����Ϊ������ĳ���, 3�ֽ�һ��
    for (i = 0; i < in_len; i+=3) {
        int value = *indata >> 2; // ��indata��һ���ַ������ƶ�2bit(����2bit)
        char c = base64_alphabet[value]; // ��Ӧbase64ת������ַ�
        *p = c; // ����Ӧ�ַ�(������ַ�)��ֵ��outdata��һ�ֽ�
        
        //�������һ��(���3�ֽ�)������
        if (i == inlen + pad_num - 3 && pad_num != 0) {
            if(pad_num == 1) {
                *(p + 1) = base64_alphabet[(int)(cmove_bits(*indata, 6, 2) + cmove_bits(*(indata + 1), 0, 4))];
                *(p + 2) = base64_alphabet[(int)cmove_bits(*(indata + 1), 4, 2)];
                *(p + 3) = '=';
            } else if (pad_num == 2) { // ����������Ҫ������ '='
                *(p + 1) = base64_alphabet[(int)cmove_bits(*indata, 6, 2)];
                *(p + 2) = '=';
                *(p + 3) = '=';
            }
        } else { // ����������3�ֽڵ�����
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
				for(i=0;i<=3;i++)
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
				printf("= �����빦�ܴ��밴�س�ȷ�ϣ�");
				
				break;
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
	if(strcmp(b_pwd,password)==0)
	{
		return 1;
	}
	else
	{
	return 0;
	}
}

void login()
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
	printf("���������룺");
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
				puts("�������");
				system("pause");
				exit(1);
			}
			else
			{
				system("cls");
				break;
			}
		}
	}
	if(i>16)
	{
		system("cls");
		gotoxy(58,2);
		puts("�������");
		system("pause");
		exit(1);
	}
}

void showMsg(char * msg)
{
	system("cls");
	puts(msg);
	system("pause");
}

