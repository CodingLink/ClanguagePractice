//������̨�ף���Ƶ�������м��׶�Day1��23min����

//˼·��ʹ�õݹ麯������һ��д��ʽ���ڶ�����д��������
//�ҹ�ʽ����ѧ�ϵĹ�������

//̨��   ����
//1       1
//2       2
//3       3
//4       5
//5       8

//˵����ǰ����֮�� step��n��=step��n-1��+step��n-2��
//���ǽ���������1�׺�2��ʱΪ���������дΪ��������

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>


int step(int n)
{
	if (n == 1 || n == 2)
	{
		return n;
	}
	return step(n - 1) + step(n - 2);
}

int main()
{
	int n;//��n��̨��

	scanf("%d", &n);

	printf("%d", step(n));

	return 0;
}