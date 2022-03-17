#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LinkNode{
	ElemType data;
	struct LinkNode *next;
}LinkNode;
typedef struct{
	LinkNode *front,*rear;//����ͷ ����β
}LinkQueue;//�Ƚ��ȳ�

void InitQueue(LinkQueue &Q)
{
	Q.front=Q.rear=(LinkNode*)malloc(sizeof(LinkNode));//ͷ��βָ��ͬһ�����
	Q.front->next=NULL;
}

bool IsEmpty(LinkQueue Q)
{
	if(Q.front==Q.rear)
		return true;
	else
		return false;
}
//��ӣ�β�����뷨
void EnQueue(LinkQueue &Q,ElemType x)
{
	LinkNode *s=(LinkNode *)malloc(sizeof(LinkNode));//���½ڵ�����ռ�
	s->data=x;//��ֵ
	s->next=NULL;
	Q.rear->next=s;//rearʼ��ָ��β��
	Q.rear=s;
}
//����  ͷ��ɾ����
bool DeQueue(LinkQueue &Q,ElemType &x)
{
	if(Q.front==Q.rear) return false;//����Ϊ��
	LinkNode *p=Q.front->next;//ͷ���ʲô��û�棬����ͷ������һ���ڵ��������
	x=p->data;//��ɾ����ֵ���ظ�������
	Q.front->next=p->next;//����  ��������ֵ����һ�����ڶ���Ԫ�ر�ɾ��
	if(Q.rear==p)//ɾ���������һ��Ԫ��
		Q.rear=Q.front;//������Ϊ��
	free(p);
	return true;
}
//������C��ѧӪ���γ�
//�����������ݽṹ 3.2.3 ���е���ʽ�洢
//ͷ��ɾ������β�����뷨
int main()
{
	LinkQueue Q;
	bool ret;
	ElemType element;//�洢����Ԫ��
	InitQueue(Q);
	EnQueue(Q,3);
	EnQueue(Q,4);
	EnQueue(Q,5);
	EnQueue(Q,6);
	EnQueue(Q,7);
	ret=DeQueue(Q,element);
	if(ret)
	{
		printf("���ӳɹ�,Ԫ��ֵΪ %d\n",element);
	}else{
		printf("����ʧ��\n");
	}
	system("pause");
}
