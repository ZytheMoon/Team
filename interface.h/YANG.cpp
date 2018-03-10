#include"project.h"

int interface::main_page(middle &chance)
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
			strcpy_s(a, yyh.c_str());
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
			strcpy_s(b, mma.c_str());
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

int interface::user_input(middle &chance)
{
	system("cls");
	cout << " \n #######################欢迎使用学生管理系统########################\n\n" << endl << endl;
	cout << "         -------------------1、插入学生信息-------------- " << endl;
	cout << "         -------------------2、删除数据 -----------------" << endl;
	cout << "         -------------------3、学生信息查询--------------" << endl;
	cout << "         -------------------4、修改学生信息--------------" << endl;
	cout << "         -------------------5、退出系统------------------" << endl;
	cout << "         -------------------6、查看数据------------------" << endl;
	cout << "           请输入要管理的功能：";
	int choice;
	int n;
	cin >> n;
	cout << "\n\n\n##################  使用权：国际科技研究院分组######################" << endl;
	choice = chance.number_(n);
	if (choice == 0) user_input(chance);
	else if (choice == 1) return 1;
	else if (choice == 2)return 2;
	else if (choice == 3)return 3;
	else if (choice == 4)return 4;
	else if (choice == 5)return 5;
	else return 6;
}