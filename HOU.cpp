#include"project.h"
char middle::account[10] = "abc";
char middle::password[12] = "abcabc";

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
	if (i > 0 && i < 7)
		return i;
	else
	{
		cout << "\n\t\t����������" << endl;
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
		oper.newData(data,number, name, chinese, math, english);
		break;
	case 2:
		cout << "������Ҫɾ���ı�ţ�";
		cin >> number;
		if (oper.delData(data, number))
			cout << "\tɾ���ɹ�" << endl;
		else
			cout << "\tɾ��ʧ��" << endl;
		system("pause");
		break;
	case 3:
		cout << "������ҪѰ�ҵı�ţ�";
		cin >> number;
		x = oper.findData(data,number);
		if (x)
		{
			cout << "\n\tѰ�ҳɹ�!";
			system("pause");
		}
		else
		{
			cout << "\n\tѰ��ʧ��!";
			system("pause");
		}
		break;
	case 4:
		cout << "\n\t������ѧ�ţ�";
		cin >> old;
		x = oper.findData(data, old);
		if (x)
		{
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
			oper.changeData(data, old, number, name, chinese, math, english);
		}
		else
		{
			cout<<"\t�޴�ͬѧ"<<endl;
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
			cout << "                       �Ѳ�ѯ����ѧ����Ϣ����:" << endl;
			cout << "******************************************************************************" << endl;
			while (p != NULL)
			{

				cout << "      ѧ��        ����       ����      ��ѧ      Ӣ��" << endl;
				printf("%10d%10s%10d%10d%10d\n", p->number, p->name, p->chineseScore, p->mathScore, p->englishScore);
				p = p->next;
			}
		}
		else
			cout << "\t\t��δ�洢����" << endl;
		system("pause");
		break;
	}
}