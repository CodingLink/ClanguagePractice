//�ڴ��ַԭ�����

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int i;
	char j;
	float k, count;

	scanf("%d %c%f", &i, &j, &k);//�������ʱ���ַ��ͱ���ǰ�ӿո�
	count = (float)i + (float)j + k;
	printf("%.2f", count);
	return 0;
}