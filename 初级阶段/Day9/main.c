//˼·����������ַ�������������󣬴洢���µ������У�����ԭ�����ַ������бȽ�

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

int main()
{
	char start[100] = { 0 }, end[100] = { 0 };
	int len, j;//���ڴ洢�ַ�������

	gets(start);
	len = strlen(start);
	j = len;
	for (int i = 0; i < len; i++)
	{
		end[j - 1] = start[i];
		j--;
	}

	int result = strcmp(start, end);//���ַ������бȽ�
	if (result < 0)
	{
		printf("%d\n", -1);
	}
	else if (result > 0)
	{
		printf("%d\n", 1);
	}
	else {
		printf("%d\n", 0);
	}
	return 0;
}