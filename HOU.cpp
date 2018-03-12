#include"project.h"
char middle::account[10] = "abc";
char middle::password[12] = "abcabc";

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
	if (i > 0 && i < 7)
		return i;
	else
	{
		cout << "\n\t\t请重新输入" << endl;
		system("pause");
		return 0;
	}
}
void middle::port(int i, dataProcessing &data, operating &oper)
{
	int number;
	int old;
	char name[10];
	int  chinese;
	int math;
	int english;
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
		oper.newData(data,number, name, chinese, math, english);
		break;
	case 2:
		cout << "输入你要删除的编号：";
		cin >> number;
		if (oper.delData(data, number))
			cout << "\t删除成功" << endl;
		else
			cout << "\t删除失败" << endl;
		system("pause");
		break;
	case 3:
		cout << "输入你要寻找的编号：";
		cin >> number;
		x = oper.findData(data,number);
		if (x)
		{
			cout << "\n\t寻找成功!";
			system("pause");
		}
		else
		{
			cout << "\n\t寻找失败!";
			system("pause");
		}
		break;
	case 4:
		cout << "\n\t请输入学号：";
		cin >> old;
		x = oper.findData(data, old);
		if (x)
		{
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
			oper.changeData(data, old, number, name, chinese, math, english);
		}
		else
		{
			cout<<"\t无此同学"<<endl;
			system("pause");
		}
		break;
	case 5:
		exit(1);
		break;
	case 6:
		LIST*p = NULL;
		int k;
		k = data.readData();
		data.show(p);
		p = p->next;
		if (k != 0)
		{
			cout << "                       已查询到的学生信息如下:" << endl;
			cout << "******************************************************************************" << endl;
			while (p != NULL)
			{

				cout << "      学号        姓名       语文      数学      英语" << endl;
				printf("%10d%10s%10d%10d%10d\n", p->number, p->name, p->chineseScore, p->mathScore, p->englishScore);
				p = p->next;
			}
		}
		else
			cout << "\t\t尚未存储数据" << endl;
		system("pause");
		break;
	}
}