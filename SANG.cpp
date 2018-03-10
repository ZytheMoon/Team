#include"project.h"

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
	//delete pNow;
}

int dataProcessing::readData() //��ȡ����ԭ����Ϣ
{
	FILE*fp;
	char readName[100];
	int i, k = 0;
	LIST*p;
	pHead = new LIST;
	pHead->next = NULL;
	char a[10];
	k = 0;
	p = pHead;
	fopen_s(&fp, "ѧ��������Ϣ.txt", "r");
	while (fgets(readName, 100, fp) != NULL)	//��ȡ�ļ���������������k
		k++;
	dataProcessing::newList(k);
	rewind(fp);
	if (k == 0)
		p = pHead;
	else
		p = pHead->next;
	for (i = 0; i<k; i++)						//�������ڴ����ļ��ж�ȡ����Ϣ
	{
		fscanf(fp, "%d %s %d %d %d", &p->number, &a, &p->chineseScore, &p->mathScore, &p->englishScore);
			strcpy_s(p->name, a);
		p = p->next;
	}
	fclose(fp);
	return k;
}

void dataProcessing::write()//���ļ���д������ѧ������
{
	LIST*p;
	FILE*fp;
	fopen_s(&fp, "ѧ��������Ϣ.txt", "w");
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

void dataProcessing::show(LIST*&p)
{
	
	p = pHead;
}