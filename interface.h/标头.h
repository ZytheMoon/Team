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
		cout << " \n #######################��ӭ��¼ѧ������ϵͳ########################\n\n" << endl << endl;
		do {
			cout << "                �û�����";
			cin >> yyh;
			cout << endl;
			cout << "                ���룺";
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
				cout << "\n\n\n##################  ʹ��Ȩ�����ʿƼ��о�Ժ����######################" << endl;;
				return 1;
			}
			else
			{
				if (i++ == 4)
				{
					cout << "\n\n\n############## �Բ���,���������Ѵﵽ���ޣ�����Ȩʹ��^_^##############" << endl;
					return 0;
					break;
				}
				else
				{
					delete[]p;
					count = 0;
					system("cls");
					cout << " \n #######################��ӭ��¼ѧ������ϵͳ########################\n\n" << endl << endl;
					cout << "   \n\n\n      ��������ȷ�û�������,��ֻ�����λ����������룡����" << "���ǵ�" << i - 1 << "��\n" << endl;
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
			cout << " \n #######################��ӭʹ��ѧ������ϵͳ########################\n\n" << endl << endl;

			cout << "         -------------------1������ѧ����Ϣ-------------- " << endl;
			cout << "         -------------------2��ɾ������ -----------------" << endl;
			cout << "         -------------------3��ѧ����Ϣ��ѯ--------------" << endl;
			cout << "         -------------------4���޸�ѧ����Ϣ--------------" << endl;
			cout << "         -------------------5���˳�ϵͳ------------------\n\n\n\n" << endl;
			cout << "          ������Ҫ���й���Ĺ���:";
			int choice;
			cin >> choice;
			cout << "\n\n\n##################  ʹ��Ȩ�����ʿƼ��о�Ժ����######################" << endl;

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