//����һ�����������������i��ͨ���Ӻ���change���������ı���i��2��Ȼ���ӡi��������������Ϊ10����ӡ��5����������Ϊ7����ӡ��3

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void change(int* p)
{
	*p = *p / 2;
}

int main()
{
	int i;
	scanf("%d", &i);

	change(&i);//ָ��Ĵ�ֵ
	printf("%d", i);
	return 0;
}