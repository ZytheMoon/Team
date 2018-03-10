#include<iostream>
#include<string>
#include<conio.h>
#include<cstring>
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

	LIST *pHead;
	void newList(int n);	      //尾插新建n个节点,链表操作
public:
	int readData();	              //读取所有原有信息并存入链表
	void write();				  //向文件中写入所有学生数据
	LIST*show();				  //返回链表第一个节点
};
class operating
{
public:
	void newData(int number, char name[10], int chineseScore, int mathScore, int englishScore);									 //增加一位学生成绩
	bool delData(int number);																									 //删除一位学生成绩
	bool changeData(int number, int newNumber, char newName[10], int newChineseScore, int newEnglishScore, int newMathScore);	 //修改某个学生的所有信息
	bool findData(int number);																									 //查找某个学生信息
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
	void port(int i);
};
char middle::account[10] = "abc";
char middle::password[12] = "abcabc";
middle chance;
class interface
{
public:
	int main_page();
	int user_input();
private:
	string yh;
	string ma;
};
interface swap_;
void dataProcessing::newList(int n) //尾插新建n个节点,链表操作
{
	int i;
	LIST *pNow, *pNext;
	pNow = pHead;
	for (i = 1; i <= n; i++)
	{
		pNext = new LIST;
		pNow->next = pNext;
		pNext->next = NULL;
		pNow = pNow->next;
	}
	
}
int dataProcessing::readData() //读取所有原有信息
{
	LIST*p;
	FILE*fp;
	char readName[100];
	int i, k = 0;
	

	k = 0;
	p = pHead;
	fp = fopen("学生所有信息.txt", "r");
	while (fgets(readName, 100, fp) != NULL)	//获取文件中已有数据条数k
		k++;
	dataProcessing::newList(k);
	rewind(fp);
	p = pHead->next;
	for (i = 0; i<k; i++)						//向链表内存入文件中读取的信息
	{
		fscanf(fp, "%d %s %d %d %d", &p->number, p->name, &p->chineseScore, &p->mathScore, &p->englishScore);
		p = p->next;
	}
	fclose(fp);
	return k;
}
void dataProcessing::write()//向文件中写入所有学生数据
{
	LIST*p;
	FILE*fp;
	fp = fopen("学生所有信息.txt", "w");
	if (pHead->next == NULL)
	{
		fprintf(fp, "");
		return;
	}
	p = pHead->next;
	while (p != NULL)
	{
		fprintf(fp, "%d %s %d %d %d\n", p->number, p->name, p->chineseScore, p->mathScore, p->englishScore);
		p = p->next;
	}
	fclose(fp);
}
LIST* dataProcessing::show()
{
	LIST*p = pHead;
	return p;
}

void operating::newData(int number, char name[10], int chineseScore, int mathScore, int englishScore)
{
	LIST*p, *pNew;
	int k;
	dataProcessing data;
	pNew = new LIST;
	k = data.readData();
	p = data.show();
	//读取文件
	for (int i = 1; i <= k+1; i++)
		p = p->next;
	//p指针指向最后一位
	pNew->number = number;
	strcpy_s(pNew->name, name);
	pNew->chineseScore = chineseScore;
	pNew->englishScore = englishScore;
	pNew->mathScore = mathScore;
	//插入数据
	p->next = pNew;
	pNew->next = NULL;
	//连接链表
	data.write();
	//写入文件
}
bool operating::delData(int number)
{
	LIST*pFront, *p;
	dataProcessing data;
	int k;
	k = data.readData();
	pFront = data.show();
	p = pFront->next;
	//读取文件
	while (p != NULL)
	{
		if (p->number == number)
		{
			pFront->next = p->next;
			break;
		}
		p = p->next;
	}
	//删除操作
	if (p == NULL)
		return false;
	data.write();
	return true;
	//检查是否找到可删除的对应学生并写入文件
}
bool operating::changeData(int number, int newNumber, char newName[10], int newChineseScore, int newEnglishScore, int newMathScore)
{
	LIST*p;
	dataProcessing data;
	int k;
	k = data.readData();
	p = data.show();
	p = p->next;
	//读取文件
	while (p != NULL)
	{
		if (p->number == number)
		{
			p->number = newNumber;
			p->chineseScore = newChineseScore;
			p->englishScore = newEnglishScore;
			p->mathScore = newMathScore;
			strcpy(p->name, newName);
			break;
		}
	}
	//找到后修改
	if (p == NULL)
		return false;
	data.write();
	return true;
	//检测是否修改成功
}
bool operating::findData(int number)
{
	LIST*p;
	dataProcessing data;
	int k;
	k = data.readData();
	p = data.show();
	p = p->next;
	//读取文件
	while (p != NULL)
	{
		if (p->number == number)
		{
			cout << "                       已查询到的学生信息如下:" << endl;
			cout << "******************************************************************************" << endl;
			cout << "    学号        姓名       语文      数学      英语" << endl;
			printf("%10d%10s%10d%10d%10d%\n", p->number, p->name, p->chineseScore, p->mathScore, p->englishScore);
			break;
		}
	}
	if (p == NULL)
		return false;
	return true;
}

int middle::account_(char a[], char  b[])
{
	if (strcmp(a, account) == 0 && strcmp(b, password) == 0)
	{
		cout << "\n\t\t欢迎使用本系统！" << endl;
		return 1;
	}
	else
	{
		cout << "\n\t\t输入错误，请重新输入！" << endl;
		return 0;
	}
}
int middle::number_(int i)
{
	if (i > 0 && i < 6)
		return i;
	else
	{
		cout << "\n\t\t请重新输入" << endl;
		system("pause");
		return 0;
	}
}
void middle::port(int i)
{
	int number;
	int old;
	char name[10];
	int  chinese;
	int math;
	int english;
	operating data;
	bool x;
	switch (i)
	{
	case 1:
		cout << "\n\t请输入学号：";
		cin >> number;
		cout << "\t请输入姓名：";
		cin >> name;
		cout << "\t请输入语文成绩：";
		cin >> chinese;
		cout << "\t请输入数学成绩：";
		cin >> math;
		cout << "\t请输入英语成绩：";
		cin >> english;
		data.newData(number, name, chinese, math, english);
		break;
	case 2:
		cout << "输入你要删除的编号：";
		cin >> number;
		data.delData(number);
		break;
	case 3:
		cout << "输入你要寻找的编号：";
		cin >> number;
		x = data.findData(number);
		if (x)
		{
			cout << "\n\t\t寻找成功!";
			system("pause");
		}
		else
		{
			cout << "\n\t\t寻找失败!";
			system("pause");
		}
		break;
	case 4:
		cout << "\n\t请输入学号：";
		cin >> old;
		cout << "\n\t请输入新学号：";
		cin >> number;
		cout << "\t请输入新姓名：";
		cin >> name;
		cout << "\t请输入新语文成绩：";
		cin >> chinese;
		cout << "\t请输入新数学成绩：";
		cin >> math;
		cout << "\t请输入新英语成绩：";
		cin >> english;
		data.changeData(old, number, name, chinese, math, english);
		break;
	case 5:
		exit(1);
		break;
	}
}

int interface::main_page()
{
	{
		string yyh;
		char c;
		int count = 0;
		char a[10];
		char b[12];
		int i = 1;
		cout << " \n #######################欢迎登录学生管理系统########################\n\n" << endl << endl;
		do {
			cout << "                用户名：";
			cin >> yyh;
			strcpy(a, yyh.c_str());
			cout << endl;
			cout << "                密码：";
			char *p = new char[20];
			while ((c = _getch()) != '\r')
			{
				if (c == 8)
				{
					if (count == 0)
					{
						continue;
					}
					putchar('\b');
					putchar(' ');
					putchar('\b');
					count--;
				}
				if (count == 19)
				{
					continue;
				}
				if ((c >= 'a'&&c <= 'z') || c >= 'A'&&c <= 'Z' || c >= '0'&&c <= '9')
					putchar('*');
				p[count++] = c;
			}
			p[count] = '\0';
			string mma = p;
			strcpy(b, mma.c_str());
			cout << endl;
			int n;
			n = chance.account_(a, b);
			system("pause");
			if (n)
			{
				delete[]p;
				cout << "\n\n\n##################  使用权：国际科技研究院分组######################" << endl;;
				return 1;
			}
			else
			{
				if (i++ == 4)
				{
					cout << "\n\n\n############## 对不起,重新输入已达到上限，您无权使用^_^##############" << endl;
					return 0;
					break;
				}
				else
				{
					delete[]p;
					count = 0;
					system("cls");
					cout << " \n #######################欢迎登录学生管理系统########################\n\n" << endl << endl;
					cout << "   \n\n\n      请输入正确用户名密码,您只有三次机会重新输入！！！" << "这是第" << i - 1 << "次\n" << endl;
					continue;
				}
			}
		} while (i <= 4);
	}
}
int interface::user_input()
{
	system("cls");
	cout << " \n #######################欢迎使用学生管理系统########################\n\n" << endl << endl;
	cout << "         -------------------1、插入学生信息-------------- " << endl;
	cout << "         -------------------2、删除数据 -----------------" << endl;
	cout << "         -------------------3、学生信息查询--------------" << endl;
	cout << "         -------------------4、修改学生信息--------------" << endl;
	cout << "         -------------------5、退出系统------------------" << endl;
	cout << "           请输入要管理的功能：";
	int choice;
	int n;
	cin >> n;
	cout << "\n\n\n##################  使用权：国际科技研究院分组######################" << endl;
	choice = chance.number_(n);
	if (choice == 0) user_input();
	else if (choice == 1) return 1;
	else if (choice == 2)return 2;
	else if (choice == 3)return 3;
	else if (choice == 4)return 4;
	else return 5;

}
int main()
{
	int n;
	if (swap_.main_page())
	{
		while (1)
		{
			n = swap_.user_input();
			chance.port(n);
		}
	}
	else
		exit(1);
	system("pause");
	return 0;
}