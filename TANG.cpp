#include"project.h"

void operating::newData(dataProcessing &data, int& number, char(&name)[10], int& chineseScore, int& mathScore, int& englishScore)
{
	LIST*p=NULL, *pNew;
	int k;
	pNew = new LIST;
	k = data.readData();
	data.show(p);
	//��ȡ�ļ�
	while (p->next != NULL)
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
bool operating::delData(dataProcessing &data, int& number)
{
	LIST*pHead=NULL, *p,*pFront;
	int k;
	k = data.readData();
	data.show(pHead);
	p = pHead->next;
	pFront = pHead;
	//��ȡ�ļ�
	while (p != NULL)
	{
		if (p->number == number)
		{
			pFront->next = p->next;
			break;
		}
		p = p->next;
		pFront = pFront->next;
	}
	//ɾ������
	if (p == NULL)
		return false;
	data.write();
	return true;
	//����Ƿ��ҵ���ɾ���Ķ�Ӧѧ����д���ļ�
}
bool operating::changeData(dataProcessing &data, int& number, int& newNumber, char(&newName)[10], int& newChineseScore, int& newEnglishScore, int& newMathScore)
{
	LIST*p=NULL;
	int k;
	k = data.readData();
	data.show(p);
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
			strcpy_s(p->name, newName);
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
bool operating::findData(dataProcessing &data, int& number)
{
	LIST*p=NULL;
	int k;
	k = data.readData();
	data.show(p);
	p = p->next;
	//��ȡ�ļ�
   	while (p != NULL)
	{
		if (p->number == number)
		{
			cout << "                       �Ѳ�ѯ����ѧ����Ϣ����:" << endl;
			cout << "******************************************************************************" << endl;
			cout << "      ѧ��        ����       ����      ��ѧ      Ӣ��" << endl;
			printf("%10d%10s%10d%10d%10d\n", p->number, p->name, p->chineseScore, p->mathScore, p->englishScore);
			break;
		}
		p = p->next;
	}
	if (p == NULL)
		return false;
	return true;
}