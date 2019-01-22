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
"5.修改指定学生成绩信息",
"6.按姓名查询学生，输出",
"7.修改密码",
"0.退出系统"
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
