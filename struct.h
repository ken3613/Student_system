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
"1.载入原始文件数据",
"2.按学生姓名排序并输出",
"3.按平均成绩排序，输出",
"4.输出给定学院学生",
"0.退出系统"
};

#endif
