//����3 4 5 6 7 9999һ��������9999���������ͨ��β�巨�½�����
//���ҵڶ���λ�õ�ֵ���������2��λ�ò���99�����Ϊ  3 99  4  5  6  7��
//ɾ����4��λ�õ�ֵ����ӡ���Ϊ  3 99  4  5  6  7��
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;

typedef struct LNode
{
	ElemType data;
	struct LNode* next;
}LNode,*LinkList;

//β�巨
void CreatList(LinkList& L)
{
	L = (LinkList)malloc(sizeof(LNode));//Ϊͷ�ڵ�����ռ�
	L->next = NULL;//��ʼ��ͷ�ڵ�

	LNode* r;//��Զ��β�ڵ�
	r = L;

	LNode* s;//����½ڵ�
	ElemType x;//�������
	scanf("%d", &x);

	while (x != 9999)
	{
		s = (LinkList)malloc(sizeof(LNode));//Ϊ�½ڵ�����ռ�
		s->data = x;//��ֵ
		r->next = s;//β���ڵ�ָ���½ڵ�
		r = s;//r��Ȼ��β�ڵ�
		scanf("%d", &x);
	}
	r->next = NULL;
}
//���ҵڶ���λ�õ�ֵ
LinkList SerchList(LinkList L, int i)
{
	//�ҵ���i�ڵ㼴�����
	int j = 1;//��������
	LNode* p = L->next;//��ָ��p���б���
	if (0 == i)
	{
		return L;//ֻ��ͷ�ڵ�
	}
	if (i<1)//λ�ò��Ϸ�
	{
		return NULL;
	}
	//����Ѱ��
	while (p != NULL && j < i)
	{
		p = p->next;
		j++;
	}
	return p;//���ص�i���ڵ��ָ��
}

void InsertList(LinkList L, int i, ElemType e)
{
	//�ҵ�ǰһ��λ�ã������������
	LNode* p = SerchList(L, i - 1);
	LNode* s = (LinkList)malloc(sizeof(LNode));//Ϊ�½ڵ�����ռ�
	s->data = e;
	s->next = p->next;
	p->next = s;
}
void PrintList(LinkList L)
{
	L = L->next;
	while (L != NULL)
	{
		printf("%3d", L->data);//��ӡ��ǰ�������
		L = L->next;//ָ����һ�����
	}
	printf("\n");
}

void DeleteList(LinkList L, int i)
{
	//�ҵ���i-1���ڵ㣬Ȼ��ɾ����i���ڵ�0
	LNode* p = SerchList(L, i - 1);
	LNode* s = p->next;//ָ��sָ��Ҫ��ɾ���ĵ�i���ڵ�
	p->next = s->next;//����
}
int main()
{
	LinkList L;

	//β�巨��������
	CreatList(L);
	LinkList answer;//�洢���ҵķ���ֵ

	//���ҵڶ���λ�õ�ֵ�����
	answer = SerchList(L, 2);
	if (answer != NULL)
	{
		printf("%d\n", answer->data);
	}

	//��2��λ�ò���99
	InsertList(L, 2, 99);
	PrintList(L);
	//ɾ����4��λ�õ�ֵ
	DeleteList(L, 4);
	PrintList(L);
	return 0;
}