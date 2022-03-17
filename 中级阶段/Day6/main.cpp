//�½�һ��ջ����ȡ��׼����3������3 4 5����ջ3 4 5�����γ�ջ����ӡ 5 4 3��
//�½�ѭ�����У�MaxsizeΪ5������ȡ��׼����3 4 5 6 7�����7ʱ��
//��������ӡfalse��Ȼ�����γ��ӣ���� 3 4 5 6

#define _CRT_SECURE_NO_WARNINGS
#define SMaxsize 4//˳��ջ�����洢����
#define Maxsize 5//ѭ�����������Դ洢4�������˷�һ��λ�������ж϶���

#include<stdio.h>

typedef int ElemType;
//˳��ջ�Ľṹ��
typedef struct
{
	ElemType data[SMaxsize];//ջ������
	int top;//ջ��ָ��
}SqStack;

//ѭ�����еĽṹ��
typedef struct
{
	ElemType data[Maxsize];//����
	int front, rear;//��ͷָ�룬��βָ��
}CQueue;

void InintStack(SqStack &S)
{
	S.top = -1;//ջ��ָ��ָ��1
}

bool PushStack(SqStack& S, ElemType x)
{
	//�ж�ջ�Ƿ���λ��
	if ( SMaxsize - 1 == S.top)
	{
		return false;
	}
	//��ջ��ָ���������ߣ��ٸ�ֵ
	S.top++;
	S.data[S.top] = x;
	return true;
}

bool PopStack(SqStack& S, ElemType &e)
{
	//�ж�ջ�Ƿ�Ϊ��
	if (- 1 == S.top)
	{
		return false;
	}
	//��ջ���ȸ�ֵ��ָ����������
	e = S.data[S.top];
	S.top--;
	return true;
}

//����Ϊѭ������
void InintQueue(CQueue& Q)
{
	//��ΪMaxsize=5�����Դ洢�±�Ϊ0��1��2��3��4
	Q.front = Q.rear = 0;
}

bool EnQueue(CQueue& Q, ElemType y)
{
	//�ж϶�����
	if ((Q.rear + 1) % Maxsize == Q.front)
	{
		return false;
	}
	//0��1��2��3��4λ�û�û�����������ȸ�ֵ��ָ��֮���һ
	Q.data[Q.rear] = y;
	Q.rear++;
	return true;
}

bool DeQueue(CQueue& Q, ElemType &z)
{
	//�ж϶��п�
	if (Q.rear == Q.front)
	{
		return false;
	}
	//0��1��2��3��4λ�ö������������ȸ�ֵ��ָ��֮���һ
	z = Q.data[Q.front];
	Q.front++;
	return true;
}

int main()
{
	SqStack S;//�½�˳��ջ
	InintStack(S);//��ʼ��˳��ջ

	int i = 0;//���������뼸����
	ElemType x;//����������������
	for (i = 0; i < 3; i++)
	{
		scanf("%d", &x);
		PushStack(S, x);
	}
	//��ջ
	ElemType e ;//�������ճ�ջ����
	for (i = 0; i < 3; i++)
	{
		PopStack(S,e);
		printf("%2d", e);
	}
	printf("\n", e);

	//����Ϊѭ������
	CQueue Q;//�½�˳��ջ
	InintQueue(Q);//��ʼ��˳��ջ
	int j = 0;//���������뼸����
	ElemType y;//����������������
	int ret;//�жϷ���ֵ���������Ƿ�ɹ�
	for (j = 0; j < 5; j++)
	{
		scanf("%d", &y);
		ret = EnQueue(Q, y);
		if (ret == 0)
		{
			printf("false\n");
		}
	}
	//����
	ElemType z;//�������ճ�������
	for (j = 0; j < Maxsize-1; j++)
	{
		DeQueue(Q, z);
		printf("%2d", z);
	}

}