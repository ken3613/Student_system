int inputCollegeInfo(char * filename,College x[]);//���ļ���ȡѧԺ��Ϣ 
int inputSexInfo(char * filename,Sex x[]);//���ļ���ȡ�Ա���Ϣ 
int inputStudentInfo(char * filename,Student x[]);//���ļ���ȡѧ����Ϣ 
void menu(enum menu_type m_type);//����˵� 
int check_pwd(char * pwd);//��������Ƿ���ȷ 
int base64_encode(const char *indata, int inlen, char *outdata, int *outlen);//base64���� 
char cmove_bits(unsigned char src, unsigned lnum, unsigned rnum); //λ�Ʋ��� 
void print_table(int n,char c);//������ 
void countAvg(Student x[],int num);//����ѧ��ƽ���� 
void showMsg(char * msg);//��ʾ��Ϣ 
int wherex();//���ع��X���� 
int wherey();//���ع��Y���� 
void gotoxy(int x,int y);//�ƶ���� 
void print_stu();//���ȫ��ѧ����Ϣ 
void print_studentById(int id);//����ѧ��ѧ�����ѧ����Ϣ 
int find_studentIndexById(int id);//���ض�Ӧѧ��ѧ���������� 
void changeId(int id,int nid);//����ѧ�� 
void changeName(int id,char * nname);//�������� 
void changeSex(int id,int nsid);//�����Ա� 
void changeCollege(int id,int ncol);//����ѧԺ 
void changeScore(int id,int sid,int nscore);//���ķ��� 
void print_studentByCollegeId(int cid);//�����ӦѧԺѧ����Ϣ 
void print_studentByName(char * name);//���ָ������ѧ����Ϣ 
void sort_studentByAvg(enum sort_method method);//����ѧ��ƽ�������� 
void sort_studentByName(enum sort_method method);//����ѧ���������� 
int login();//��¼���� 
void changePwd();//�������� 
