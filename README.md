C语言学生成绩管理系统
================

项目由以下文件组成:
------------------------------
+ Student_system.c：项目工程文件
+ main.c：项目主程序文件
+ struct.h：结构体及枚举定义
+ declare.h：函数声明
+ func.c：函数定义

### 函数定义说明
- ```c
int inputCollegeInfo(char * filename,College x[]);
	```
	
		- 作用：从filename文件中读取学院信息，存入x结构体数组中，并返回学院数量
		- 参数：`char * filename` 文件路径
			          `College x[]` College结构体数组
	    - 返回值：`int` 成功读取的学院数量
