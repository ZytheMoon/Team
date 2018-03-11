#include"project.h"

void operating::newData(dataProcessing &data, int& number, char(&name)[10], int& chineseScore, int& mathScore, int& englishScore)
{
	LIST*p=NULL, *pNew;
	int k;
	pNew = new LIST;
	k = data.readData();
	data.show(p);
	//读取文件
	while (p->next != NULL)
		p = p->next;
	//p指针指向最后一位
	pNew->number = number;
	strcpy_s(pNew->name, name);
	pNew->chineseScore = chineseScore;
	pNew->englishScore = englishScore;
	pNew->mathScore = mathScore;
	//插入数据
	p->next = pNew;
	pNew->next = NULL;
	//连接链表
	data.write();
	//写入文件

}
bool operating::delData(dataProcessing &data, int& number)
{
	LIST*pHead=NULL, *p,*pFront;
	int k;
	k = data.readData();
	data.show(pHead);
	p = pHead->next;
	pFront = pHead;
	//读取文件
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
	//删除操作
	if (p == NULL)
		return false;
	data.write();
	return true;
	//检查是否找到可删除的对应学生并写入文件
}
bool operating::changeData(dataProcessing &data, int& number, int& newNumber, char(&newName)[10], int& newChineseScore, int& newEnglishScore, int& newMathScore)
{
	LIST*p=NULL;
	int k;
	k = data.readData();
	data.show(p);
	p = p->next;
	//读取文件
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
	//找到后修改
	if (p == NULL)
		return false;
	data.write();
	return true;
	//检测是否修改成功
}
bool operating::findData(dataProcessing &data, int& number)
{
	LIST*p=NULL;
	int k;
	k = data.readData();
	data.show(p);
	p = p->next;
	//读取文件
   	while (p != NULL)
	{
		if (p->number == number)
		{
			cout << "                       已查询到的学生信息如下:" << endl;
			cout << "******************************************************************************" << endl;
			cout << "      学号        姓名       语文      数学      英语" << endl;
			printf("%10d%10s%10d%10d%10d\n", p->number, p->name, p->chineseScore, p->mathScore, p->englishScore);
			break;
		}
		p = p->next;
	}
	if (p == NULL)
		return false;
	return true;
}