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
		cout << " \n #######################��ӭ��¼ѧ������ϵͳ########################\n\n" << endl << endl;
		do {
			cout << "                �û�����";
			cin >> yyh;
			strcpy_s(a, yyh.c_str());
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
			strcpy_s(b, mma.c_str());
			cout << endl;
			int n;
			n = chance.account_(a, b);
			system("pause");
			if (n)
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
}

int interface::user_input(middle &chance)
{
	system("cls");
	cout << " \n #######################��ӭʹ��ѧ������ϵͳ########################\n\n" << endl << endl;
	cout << "         -------------------1������ѧ����Ϣ-------------- " << endl;
	cout << "         -------------------2��ɾ������ -----------------" << endl;
	cout << "         -------------------3��ѧ����Ϣ��ѯ--------------" << endl;
	cout << "         -------------------4���޸�ѧ����Ϣ--------------" << endl;
	cout << "         -------------------5���˳�ϵͳ------------------" << endl;
	cout << "         -------------------6���鿴����------------------" << endl;
	cout << "           ������Ҫ����Ĺ��ܣ�";
	int choice;
	int n;
	cin >> n;
	cout << "\n\n\n##################  ʹ��Ȩ�����ʿƼ��о�Ժ����######################" << endl;
	choice = chance.number_(n);
	if (choice == 0) user_input(chance);
	else if (choice == 1) return 1;
	else if (choice == 2)return 2;
	else if (choice == 3)return 3;
	else if (choice == 4)return 4;
	else if (choice == 5)return 5;
	else return 6;
}