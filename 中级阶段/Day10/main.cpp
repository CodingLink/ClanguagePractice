//����һ���ַ���abaabcdac��ֱ���ֶ���ӡ����next����ֵ��Ҳ�����Լ��˹��㣬ֱ��д����һ�������forѭ��������鼴�ɣ���
//ÿ���������ֵռ�����ո�%2d������˲��ܸ���������ɶ��

#define _CRT_SECURE_NO_WARNINGS
#define MaxSize 10
#include<stdio.h>

int main()
{
	char T[MaxSize];//���ԭ������
	int s[MaxSize] = {0,1,1,2,2,3,1,1,2};//���next����

	int i;//�������������

	for (i = 1; i < 10; i++)
	{
		scanf("%c", &T[i]);
	}

	for (i = 0; i < 9; i++)
	{
		printf("%2d", s[i]);
	}

	return 0;
}