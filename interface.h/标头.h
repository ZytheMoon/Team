#pragma once
#include<iostream>
#include<string>
#include<conio.h>
using namespace std;
class interface
{
public:
	interface(string y, string m)
	{
		yh = y;
		ma = m;

	}
	int main_page()
	{
		string yyh;
		char c;
		int count = 0;

		int i = 1;
		cout << " \n #######################欢迎登录学生管理系统########################\n\n" << endl << endl;
		do {
			cout << "                用户名：";
			cin >> yyh;
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
			cout << endl;
			if ((yh == yyh) && (ma == mma))
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
	int user_input()
	{
		if (main_page())
		{
			system("cls");
			cout << " \n #######################欢迎使用学生管理系统########################\n\n" << endl << endl;

			cout << "         -------------------1、插入学生信息-------------- " << endl;
			cout << "         -------------------2、删除数据 -----------------" << endl;
			cout << "         -------------------3、学生信息查询--------------" << endl;
			cout << "         -------------------4、修改学生信息--------------" << endl;
			cout << "         -------------------5、退出系统------------------\n\n\n\n" << endl;
			cout << "          请输入要进行管理的功能:";
			int choice;
			cin >> choice;
			cout << "\n\n\n##################  使用权：国际科技研究院分组######################" << endl;

			if (choice == 1) return 1;
			else if (choice == 2) return 2;
			else if (choice == 3)return 3;
			else if (choice == 4) return 4;
			else
				return 5;
		}


	}
private:
	string yh;
	string ma;


};
int main()
{
	interface *q = new interface("abc", "abcabc");
	cout << q->user_input() << endl;

	delete q;
	system("pause");
	return 0;
}