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
"0.�˳�ϵͳ"
};

#endif
