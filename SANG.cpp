#include"project.h"

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
	//delete pNow;
}

int dataProcessing::readData() //读取所有原有信息
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
	fopen_s(&fp, "学生所有信息.txt", "r");
	while (fgets(readName, 100, fp) != NULL)	//获取文件中已有数据条数k
		k++;
	dataProcessing::newList(k);
	rewind(fp);
	if (k == 0)
		p = pHead;
	else
		p = pHead->next;
	for (i = 0; i<k; i++)						//向链表内存入文件中读取的信息
	{
		fscanf(fp, "%d %s %d %d %d", &p->number, &a, &p->chineseScore, &p->mathScore, &p->englishScore);
			strcpy_s(p->name, a);
		p = p->next;
	}
	fclose(fp);
	return k;
}

void dataProcessing::write()//向文件中写入所有学生数据
{
	LIST*p;
	FILE*fp;
	fopen_s(&fp, "学生所有信息.txt", "w");
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