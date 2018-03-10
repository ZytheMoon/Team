#include<iostream>
#include<string>
#include<conio.h>
#include<cstring>
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

	LIST *pHead;
	void newList(int n);	      //β���½�n���ڵ�,�������
public:
	int readData();	              //��ȡ����ԭ����Ϣ����������
	void write();				  //���ļ���д������ѧ������
	LIST*show();				  //���������һ���ڵ�
};
class operating
{
public:
	void newData(int number, char name[10], int chineseScore, int mathScore, int englishScore);									 //����һλѧ���ɼ�
	bool delData(int number);																									 //ɾ��һλѧ���ɼ�
	bool changeData(int number, int newNumber, char newName[10], int newChineseScore, int newEnglishScore, int newMathScore);	 //�޸�ĳ��ѧ����������Ϣ
	bool findData(int number);																									 //����ĳ��ѧ����Ϣ
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
void dataProcessing::newList(int n) //β���½�n���ڵ�,�������
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
int dataProcessing::readData() //��ȡ����ԭ����Ϣ
{
	LIST*p;
	FILE*fp;
	char readName[100];
	int i, k = 0;
	

	k = 0;
	p = pHead;
	fp = fopen("ѧ��������Ϣ.txt", "r");
	while (fgets(readName, 100, fp) != NULL)	//��ȡ�ļ���������������k
		k++;
	dataProcessing::newList(k);
	rewind(fp);
	p = pHead->next;
	for (i = 0; i<k; i++)						//�������ڴ����ļ��ж�ȡ����Ϣ
	{
		fscanf(fp, "%d %s %d %d %d", &p->number, p->name, &p->chineseScore, &p->mathScore, &p->englishScore);
		p = p->next;
	}
	fclose(fp);
	return k;
}
void dataProcessing::write()//���ļ���д������ѧ������
{
	LIST*p;
	FILE*fp;
	fp = fopen("ѧ��������Ϣ.txt", "w");
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
	//��ȡ�ļ�
	for (int i = 1; i <= k+1; i++)
		p = p->next;
	//pָ��ָ�����һλ
	pNew->number = number;
	strcpy_s(pNew->name, name);
	pNew->chineseScore = chineseScore;
	pNew->englishScore = englishScore;
	pNew->mathScore = mathScore;
	//��������
	p->next = pNew;
	pNew->next = NULL;
	//��������
	data.write();
	//д���ļ�
}
bool operating::delData(int number)
{
	LIST*pFront, *p;
	dataProcessing data;
	int k;
	k = data.readData();
	pFront = data.show();
	p = pFront->next;
	//��ȡ�ļ�
	while (p != NULL)
	{
		if (p->number == number)
		{
			pFront->next = p->next;
			break;
		}
		p = p->next;
	}
	//ɾ������
	if (p == NULL)
		return false;
	data.write();
	return true;
	//����Ƿ��ҵ���ɾ���Ķ�Ӧѧ����д���ļ�
}
bool operating::changeData(int number, int newNumber, char newName[10], int newChineseScore, int newEnglishScore, int newMathScore)
{
	LIST*p;
	dataProcessing data;
	int k;
	k = data.readData();
	p = data.show();
	p = p->next;
	//��ȡ�ļ�
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
	//�ҵ����޸�
	if (p == NULL)
		return false;
	data.write();
	return true;
	//����Ƿ��޸ĳɹ�
}
bool operating::findData(int number)
{
	LIST*p;
	dataProcessing data;
	int k;
	k = data.readData();
	p = data.show();
	p = p->next;
	//��ȡ�ļ�
	while (p != NULL)
	{
		if (p->number == number)
		{
			cout << "                       �Ѳ�ѯ����ѧ����Ϣ����:" << endl;
			cout << "******************************************************************************" << endl;
			cout << "    ѧ��        ����       ����      ��ѧ      Ӣ��" << endl;
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
		cout << "\n\t\t��ӭʹ�ñ�ϵͳ��" << endl;
		return 1;
	}
	else
	{
		cout << "\n\t\t����������������룡" << endl;
		return 0;
	}
}
int middle::number_(int i)
{
	if (i > 0 && i < 6)
		return i;
	else
	{
		cout << "\n\t\t����������" << endl;
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
		cout << "\n\t������ѧ�ţ�";
		cin >> number;
		cout << "\t������������";
		cin >> name;
		cout << "\t���������ĳɼ���";
		cin >> chinese;
		cout << "\t��������ѧ�ɼ���";
		cin >> math;
		cout << "\t������Ӣ��ɼ���";
		cin >> english;
		data.newData(number, name, chinese, math, english);
		break;
	case 2:
		cout << "������Ҫɾ���ı�ţ�";
		cin >> number;
		data.delData(number);
		break;
	case 3:
		cout << "������ҪѰ�ҵı�ţ�";
		cin >> number;
		x = data.findData(number);
		if (x)
		{
			cout << "\n\t\tѰ�ҳɹ�!";
			system("pause");
		}
		else
		{
			cout << "\n\t\tѰ��ʧ��!";
			system("pause");
		}
		break;
	case 4:
		cout << "\n\t������ѧ�ţ�";
		cin >> old;
		cout << "\n\t��������ѧ�ţ�";
		cin >> number;
		cout << "\t��������������";
		cin >> name;
		cout << "\t�����������ĳɼ���";
		cin >> chinese;
		cout << "\t����������ѧ�ɼ���";
		cin >> math;
		cout << "\t��������Ӣ��ɼ���";
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
		cout << " \n #######################��ӭ��¼ѧ������ϵͳ########################\n\n" << endl << endl;
		do {
			cout << "                �û�����";
			cin >> yyh;
			strcpy(a, yyh.c_str());
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
			strcpy(b, mma.c_str());
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
int interface::user_input()
{
	system("cls");
	cout << " \n #######################��ӭʹ��ѧ������ϵͳ########################\n\n" << endl << endl;
	cout << "         -------------------1������ѧ����Ϣ-------------- " << endl;
	cout << "         -------------------2��ɾ������ -----------------" << endl;
	cout << "         -------------------3��ѧ����Ϣ��ѯ--------------" << endl;
	cout << "         -------------------4���޸�ѧ����Ϣ--------------" << endl;
	cout << "         -------------------5���˳�ϵͳ------------------" << endl;
	cout << "           ������Ҫ����Ĺ��ܣ�";
	int choice;
	int n;
	cin >> n;
	cout << "\n\n\n##################  ʹ��Ȩ�����ʿƼ��о�Ժ����######################" << endl;
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