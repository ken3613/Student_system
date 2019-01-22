#ifndef STU_INFO
#define STU_INFO
typedef struct college
{
	int id;
	char name[20];
}College;

typedef struct sex
{
	int id;
	char name[10];
}Sex;

typedef struct studen
{
	int id;
	int sid;
	int cid;
	char name[16];
	double score[10];
	double avg;
}Student;

enum sort_method
{
	UP,DOWN
};

enum menu_type
{
	MainMenu,CollegeMenu
};

static char const main_str[][32]={
"1.����ԭʼ�ļ�����",
"2.��ѧ�������������",
"3.��ƽ���ɼ��������",
"4.�������ѧԺѧ��",
"5.�޸�ָ��ѧ���ɼ���Ϣ",
"6.��������ѯѧ�������",
"7.�޸�����",
"0.�˳�ϵͳ"
};

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

#endif
