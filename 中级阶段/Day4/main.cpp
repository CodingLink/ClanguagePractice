//����3 4 5 6 7 9999һ��������9999���������ͨ��ͷ�巨�½������������ͨ��β�巨�½����������
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <malloc.h>

typedef int ElemType;
typedef struct LNode
{
	ElemType data;//������
	struct LNode* next;//ָ����
}LNode, *LinkList;//�ṹ�����ͣ��ṹ��ָ������

//ͷ�巨
void CreatList_tou(LinkList& L)
{
	LNode* a;//����½ڵ�
	ElemType x;//����������
	L = (LinkList)malloc(sizeof(LNode));//����ͷ�ڵ�
	L->next = NULL;//��ʼ��Ϊ������

	scanf("%d",&x );
	while (x != 9999)
	{
		a = (LinkList)malloc(sizeof(LNode));//�½ڵ�
		a->data = x;//��ֵ
		a->next = L->next;
		L->next = a;
		scanf("%d", &x);
	}
}

//β�巨
void CreatList_wei(LinkList& L)
{
	LNode* r;//βָ��	
	LNode* a;//�½ڵ�
	ElemType x;
	L = (LinkList)malloc(sizeof(LNode));
	L->next=NULL;
	r = L;

	scanf("%d", &x);
	while (x != 9999)
	{
		a = (LinkList)malloc(sizeof(LNode));
		a->data = x;
		r->next = a;
		r = a;//rָ���µ�β�ڵ�
		scanf("%d", &x);
	}
	r->next = NULL;
}
//��ӡԪ��
void PrintList(LinkList L)
{
	L = L->next;
	while (L != NULL)
	{
		printf("%d", L->data);//��ӡ��ǰ�������
		L = L->next;//ָ����һ�����
		if (L != NULL)
		{
			printf(" ");
		}
	}
	printf("\n");
}

int main()
{
	LinkList L;//ͷָ��L
	//ͷ�巨
	CreatList_tou(L);
	PrintList(L);
	CreatList_wei(L);
	PrintList(L);
	return 0;
}