//�ַ�����Сдת��P54-P55  97-a 65-A
//�����жϷ�����
//1����������ݣ��ܱ�4�����������ꡣ����2004��������꣬2001�겻�����꣩
//2��������ݣ��ܱ�400�����������ꡣ����2000�������꣬1900�겻�����꣩

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int year;
	scanf("%d", &year);
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0 && year % 100 == 0))
	{
		printf("yes\n");
	}
	else
	{
		printf("no\n");
	}
	return 0;
}