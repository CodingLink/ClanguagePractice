#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

////��p190ҳ����
//int main()
//{
//	int a[3] = { 2, 7, 8 };
//	int* p;
//	int j;
//	p = a;//������a����������ʼ��ַ����ֵ��ָ��p��ָ��pָ�����a[0]
//	j = *p++;//�൱��j=*p; p++; ��j����ָ��pָ���a[0]��ֵ��2����ָ��p���ƣ�ָ��a[1];
//	printf("a[0]=%d, j=%d, *p = %d\n", a[0], j, *p);//��ʱָ��pָ��a[1]��ȡֵΪ7
//
//	return 0;
//}


////��p196����
//char* print_malloc()
//{
//	char* c;
//	c = (char*)malloc(20);
//	strcpy(c, "i am print_malloc\n");
//	puts(c);
//	return c;
//}
//
//int main()
//{
//	char* p;
//	p = print_malloc();
//	puts(p);
//	free(p);
//	p = NULL;
//	return 0;
//}

int main()
{
	int i;//��Ӧ��С�ڴ�
	scanf("%d", &i);
	getchar();//���˻س�


	char* c;//��������ռ����ʼ��ַ
	c = (char*)malloc(i);
	gets(c);
	puts(c);

	return 0;
}