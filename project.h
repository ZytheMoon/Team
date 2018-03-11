#include<iostream>
#include<string>
#include<conio.h>
#include<cstring>
#include<cstdlib>
#include<cstdlib>
using namespace std;


typedef struct MyStruct
{
	int number;						      //学号
	char name[10];						  //姓名
	int chineseScore;					  //语文成绩
	int mathScore;						  //数学成绩
	int englishScore;					  //英语成绩
	struct MyStruct *next;
}LIST;
class dataProcessing
{
private:

	LIST*pHead;
	void newList(int n);	      //尾插新建n个节点,链表操作
public:
	int readData();	              //读取所有原有信息并存入链表
	void write();				  //向文件中写入所有学生数据
	void show(LIST*&p);				  //返回链表第一个节点
};

class operating
{
public:
	void newData(dataProcessing &data, int& number, char(&name)[10], int& chineseScore, int& mathScore, int& englishScore);									 //增加一位学生成绩
	bool delData(dataProcessing &data, int& number);																									 //删除一位学生成绩
	bool changeData(dataProcessing &data, int& number, int& newNumber, char(&newName)[10], int& newChineseScore, int& newEnglishScore, int& newMathScore);	 //修改某个学生的所有信息
	bool findData(dataProcessing &data, int& number);																									 //查找某个学生信息
};

class middle
{
private:
	static char  account[10];
	static char password[12];
	int number;
public:
	int account_(char a[], char  b[]);
	int number_(int i);
	void port(int i, dataProcessing &data, operating &oper);
};

class interface
{
public:
	int main_page(middle &chance);
	int user_input(middle &chance);
private:
	string yh;
	string ma;
};