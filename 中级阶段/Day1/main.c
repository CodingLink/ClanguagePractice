//����һ��ѧ����ѧ�ţ��������Ա��ýṹ��洢��ͨ��scanf��ȡ��Ȼ����ͨ��printf��ӡ���
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

	//����ṹ��
typedef struct student
{
	int num;
	char name[20];
	char sex;
}stu;

int main()
{
	stu eg = {0};

	//ע�������ȡ��ַ�����%cǰ��ӿո�
	scanf("%d %s %c", &eg.num, eg.name, &eg.sex);

	printf("%d %s %c", eg.num, eg.name, eg.sex);
	return 0;
}
