//˼·��ԭ����������ȡ�࣬���������������һ�������������ж�����������ԭ�������Ƿ�һ�¡�
//    ��һ�£�����������ǻ�����������һ�£�������������ǻ�������
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int start,end=0,temp;

	scanf("%d", &start);

	temp = start;
	while (start!=0)
	{
		end = end * 10 + start % 10;
		start = start / 10;
	}

	if (temp == end)
	{
		printf("yes");
	}
	else
	{
		printf("no");
	}

	return 0;
}