#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int a[100] = {0};//���N����
	int num;//������뼸����
	int count = 0;//���ּ���2

	scanf("%d", &num);

	for (int i = 0; i < num; i++)
	{
		scanf("%d", &a[i]);
		if (a[i] == 2)
		{
			count++;
		}
	}
	printf("%d", count);
	return 0;

}