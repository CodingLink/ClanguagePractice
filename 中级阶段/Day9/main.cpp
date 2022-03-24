//��ȡ10��Ԫ�� 87  7 60 80 59 34 86 99 21  3��Ȼ���������������
//����������3  7 21 34 59 60 80 86 87 99�����������Ԫ�أ�
//����һ������Ϊ10�������У�ͨ���۰�����ҵ�21���±꣨�±�Ϊ2����Ȼ�����2

#define _CRT_SECURE_NO_WARNINGS
#define MaxSize 10
#include<stdio.h>
#include<stdlib.h>

//���Ľṹ��
typedef int Elemtype;
typedef struct BiNode
{
	Elemtype data;//������
	struct BiNode* lchild;//������ָ��
	struct BiNode* rchild;//������ָ��
}BiNode, * Bitree;//���Ľڵ� �� �ṹ��ָ������

typedef struct SeqList
{
	Elemtype elm[MaxSize];//������
	int length;//˳���ĳ���
}SeqList;//˳���

bool BST_Insert(Bitree& tree, Elemtype e)
{
	//˼�룺ԭ��Ϊ�գ��²���ĵ�Ϊ���ڵ㣨�����ÿһ��С����˵��
	//�����нڵ������ڵ���ͬ�������ʧ��
	//������ڵ���ڸýڵ㣬���������������������������
	if (NULL == tree)//ԭ������Ϊ�գ�����������Ϊ�գ�
	{
		tree = (Bitree)malloc(sizeof(BiNode));//Ϊ��������ռ�
		tree->data = e;//���ýڵ㸳ֵ����ʼ������ָ��
		tree->lchild = NULL;
		tree->rchild = NULL;
		return true;//����ɹ�
	}
	else if (tree->data == e)
	{
		return false;//����ʧ��
	}
	else if (e > tree->data)
	{
		return BST_Insert(tree->rchild, e);
	}
	else
	{
		return BST_Insert(tree->lchild, e);
	}
}

void Crest_BST(Bitree& tree, Elemtype x[])
{
	tree = NULL;

	int i = 0;//��������
	//��10��Ԫ�ز���
	while (i < 10)
	{
		BST_Insert(tree, x[i]);
		i++;
	}
}

//���ź����Ԫ�ش������飬Ҳ������ô����ע��pos������
//void MidOrder_Array(Bitree tree,Elemtype key[],int &pos)
//{
//
//	if (NULL != tree)
//	{
//		MidOrder_Array(tree->lchild, key, pos);
//		printf("%3d", tree->data);
//		key[pos] = tree->data;
//		pos++;
//		MidOrder_Array(tree->rchild, key, pos);
//	}
//}
void MidOrder(Bitree tree)
{

	if (NULL != tree)
	{
		MidOrder(tree->lchild);
		printf("%3d", tree->data);
		MidOrder(tree->rchild);
	}
}

int toArrayIn(Bitree tree, SeqList &L, int pos)
{
	if (tree == NULL)
		return pos;
	pos = toArrayIn(tree->lchild, L, pos);
	L.elm[pos] = tree->data;
	return toArrayIn(tree->rchild, L, pos + 1);
}

int Binary_Search(SeqList& L, Elemtype tag)
{
	int low = 0;
	int high = L.length - 1;
	int mid;

	while (low < high)
	{
		mid = (low + high) / 2;
		if (L.elm[mid] == tag)
		{
			return mid;//�ҵ��򷵻������±�
		}
		else if (L.elm[mid] > tag)
		{
			high = mid - 1;//������
		}
		else 
		{
			low = mid + 1;
		}
	}
	return -1;//������������δ�ҵ�������-1
}

int main()
{
	Bitree tree = NULL;//��Ϊ��

	int i;//���Լ�������10��Ԫ��
	Elemtype x[MaxSize];
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &x[i]);
	}
	Crest_BST(tree, x);
	int pos = 0;
	//�������
	//Elemtype key[MaxSize];
	//MidOrder_Array(tree, key, pos);
	MidOrder(tree);

	//���ź����Ԫ�ش���������
	SeqList L;
	L.length = 10;
	toArrayIn(tree, L, pos);
	printf("\n");

	//�۰����
	printf("%d", Binary_Search(L, 21));
	return 0;
}