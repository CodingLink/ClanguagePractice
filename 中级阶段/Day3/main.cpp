//��ʼ��˳���˳�����Ԫ��Ϊ���ͣ�����ߵ�Ԫ����1,2,3��Ȼ��ͨ��scanf��ȡһ��Ԫ�أ�����������6����
//���뵽��2��λ�ã���ӡ���˳���ÿ��Ԫ��ռ3���ո񣬸�ʽΪ1  6  2  3��Ȼ��scanf��ȡһ������������ɾ����λ�ã���������Ϊ1����
//Ȼ�����˳���  6  2  3�����������λ�ò��Ϸ������false�ַ��������ѣ�Languageһ��ҪѡΪC++��

#define _CRT_SECURE_NO_WARNINGS
#define MaxSize 20

#include<stdio.h>

typedef int ElemType;

typedef struct
{
	ElemType data[MaxSize];
	ElemType len;
}SqList;

bool ListInsert(SqList& L, int i, ElemType e)
{
	//�ж�λ���Ƿ�Ϸ�,�ɲ����λ���� 1��2��3��4
	if (i<1 || i>L.len + 1)
	{
		return false;
	}
	//˳����У�Ԫ����������20��Ԫ���ڣ������ڲ����ˣ���
	if (i > MaxSize)
	{
		return false;
	}
	//�����Ԫ������Ųһλ
	for (int j = L.len; j >= i; j--)
	{
		L.data[j] = L.data[j-1];
	}
	L.data[i - 1] = e;
	L.len++;
	return true;
}

bool ListDelete(SqList& L, int i)
{
	//�ж�λ���Ƿ�Ϸ�,��ɾ����λ���� 1��2��3
	if (i<1 || i>L.len)
	{
		return false;
	}
	//�����Ԫ����ǰŲһλ
	for (int j = i; j <L.len; j++)
	{
		L.data[j-1] = L.data[j];
	}
	L.len--;
	return true;
}

//���ڴ�ӡ
void printf_e(SqList& L)
{
	int i ;
	for (i = 0; i < L.len; i++)
	{
		printf("%3d", L.data[i]);
	}
	printf("\n");
}

int main()
{
	SqList L;
	L.data[0] = { 1 };
	L.data[1] = { 2 };
	L.data[2] = { 3 };
	L.len = 3;

	ElemType n;//������Ԫ��
	scanf("%d", &n);

	//���뵽��2��λ�ã���ӡ���˳���ÿ��Ԫ��ռ3���ո�
	int ret;
	ret=ListInsert(L, 2, n);
	if (ret)
	{
		printf_e(L);
	}
	else
	{
		return 0;//����ʧ��
	}

	int m;//��ɾ����λ��
	scanf("%d", &m);

	ret = ListDelete(L,m);
	if (ret)
	{
		printf_e(L);
	}
	else
	{
		printf("false");
		return 0;//����ʧ��
	}
	return 0;

}