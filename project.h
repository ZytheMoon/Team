#include<iostream>
#include<string>
#include<conio.h>
#include<cstring>
#include<cstdlib>
#include<cstdlib>
using namespace std;


typedef struct MyStruct
{
	int number;						      //ѧ��
	char name[10];						  //����
	int chineseScore;					  //���ĳɼ�
	int mathScore;						  //��ѧ�ɼ�
	int englishScore;					  //Ӣ��ɼ�
	struct MyStruct *next;
}LIST;
class dataProcessing
{
private:

	LIST*pHead;
	void newList(int n);	      //β���½�n���ڵ�,�������
public:
	int readData();	              //��ȡ����ԭ����Ϣ����������
	void write();				  //���ļ���д������ѧ������
	void show(LIST*&p);				  //���������һ���ڵ�
};

class operating
{
public:
	void newData(dataProcessing &data, int& number, char(&name)[10], int& chineseScore, int& mathScore, int& englishScore);									 //����һλѧ���ɼ�
	bool delData(dataProcessing &data, int& number);																									 //ɾ��һλѧ���ɼ�
	bool changeData(dataProcessing &data, int& number, int& newNumber, char(&newName)[10], int& newChineseScore, int& newEnglishScore, int& newMathScore);	 //�޸�ĳ��ѧ����������Ϣ
	bool findData(dataProcessing &data, int& number);																									 //����ĳ��ѧ����Ϣ
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