int inputCollegeInfo(char * filename,College x[]);//从文件读取学院信息 
int inputSexInfo(char * filename,Sex x[]);//从文件读取性别信息 
int inputStudentInfo(char * filename,Student x[]);//从文件读取学生信息 
void menu(enum menu_type m_type);//输出菜单 
int check_pwd(char * pwd);//检查密码是否正确 
int base64_encode(const char *indata, int inlen, char *outdata, int *outlen);//base64加密 
char cmove_bits(unsigned char src, unsigned lnum, unsigned rnum); //位移操作 
void print_table(int n,char c);//输出表格 
void countAvg(Student x[],int num);//计算学生平均分 
void showMsg(char * msg);//显示信息 
int wherex();//返回光标X坐标 
int wherey();//返回光标Y坐标 
void gotoxy(int x,int y);//移动光标 
void print_stu();//输出全体学生信息 
void print_studentById(int id);//根据学生学号输出学生信息 
int find_studentIndexById(int id);//返回对应学号学生数组索引 
void changeId(int id,int nid);//更改学号 
void changeName(int id,char * nname);//更改姓名 
void changeSex(int id,int nsid);//更改性别 
void changeCollege(int id,int ncol);//更改学院 
void changeScore(int id,int sid,int nscore);//更改分数 
void print_studentByCollegeId(int cid);//输出对应学院学生信息 
void print_studentByName(char * name);//输出指定姓名学生信息 
void sort_studentByAvg(enum sort_method method);//根据学生平均分排序 
void sort_studentByName(enum sort_method method);//根据学生姓名排序 
int login();//登录函数 
void changePwd();//更改密码 
