//��ȡ�ַ���abcdefghij��Ȼ���ν�������һ�Ŷ�������Ȼ��ǰ��������abdhiejcfg��ע�ⲻҪ��ӡǰ�������������
//˼·����α����������������ö��м�¼�ڵ㣨�ýڵ��Ƿ������Һ��ӣ�

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
//�������Ľṹ�壬������ʵ��
typedef  char ElemType;
typedef struct BiTNode
{
	ElemType data;
	struct BiTNode* lchild, * rchild;//���Һ���ָ��
}BiTNode, * BiTree;//�������Ľڵ㣬����������

//��¼�ڵ�����ӣ����ڵ�����Һ��Ӳ�Ϊ�գ������
typedef struct label
{
	BiTree p;//����ĳһ�����ĵ�ֵַ
	struct label* pnext;
}label, * Label;//���ӽڵ㣬����

void preOrder(BiTree tree)
{
	if (tree != NULL)
	{
		putchar(tree->data);
		preOrder(tree->lchild);
		preOrder(tree->rchild);
	}
}

int main()
{
	BiTree pnew;//�����½ڵ�
	BiTree tree = NULL;//����Ϊ��

	//��α����ĸ�������
	Label phead = NULL, ptail = NULL;//phead���Ƕ���ͷ��ptail���Ƕ���β
	Label listpnew;//���ӵ��½ڵ�
	Label pcur = NULL;//listpnew�Ƕ��е��½ڵ� pcur�����ĵ�ǰ�ڵ�

	ElemType c;
	while (scanf("%c", &c) != EOF)
	{
		if (c == '\n')
		{
			break;
		}
		pnew = (BiTree)calloc(1, sizeof(BiTNode));//calloc����ռ䲢�Կռ���г�ʼ��
		pnew->data = c;//���ݷŽ�ȥ

		listpnew = (Label)calloc(1, sizeof(Label));//�����н������ռ�
		listpnew->p = pnew;//��ֵ

		if (NULL == tree)//����Ϊ��
		{
			tree = pnew;//���ĸ�
			phead = listpnew;//����ͷ
			ptail = listpnew;//����β
			pcur = listpnew;
			continue;//��������ѭ��
		}
		else {
			ptail->pnext = listpnew;//�½���������ͨ��β�巨//β�巨���
			ptail = listpnew;//ptailָ�����β��
		}

		//pcurʼ��ָ��Ҫ����Ľ���λ��
		if (NULL == pcur->p->lchild)//��ΰ��½�������
		{
			pcur->p->lchild = pnew;//���½��ŵ�Ҫ����������
		}
		else if (NULL == pcur->p->rchild)
		{
			pcur->p->rchild = pnew;//���½��ŵ�Ҫ��������ұ�
			pcur = pcur->pnext;//���Ҷ����˽���pcurָ����е���һ��
		}
	}
	preOrder(tree);
}
