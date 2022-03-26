//��ȡ10����������12 63 58 95 41 35 65  0 38 44��
//Ȼ��ͨ��ѡ�����򣬶����򣬷ֱ�Ը������ݽ����������2����������ÿ���������ռ3���ո�

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <string.h>

//��ӡ����
void PrintInt(int a[])
{
	int i;
	for (i = 0; i < 10; i++)
	{
		printf("%3d", a[i]);
	}
	printf("\n");
}

//��������
void swap(int &x, int &y)
{
	int temp;
	temp = x;
	x = y;
	y = temp;
}

//ѡ������
//˼�룺ÿһ���ҵ���С��Ԫ�أ��ŵ�ǰ���λ�ã�ÿһ��ȷ��һ��Ԫ�ص�λ�ã�n-1�κ�����ȷ��
void SelectSort(int a[], int len)
{
	int i;//���ѭ������¼�ҵ��ڼ���
	int min;//��¼��ǰ��СԪ��λ��
	int j;//�ڲ�ѭ������δ����������У�����Сֵ��λ��
	for (i = 0; i < len - 1; i++)
	{
		min = i;
		for (j = i + 1; j < len; j++)//��i+1-n����Сֵ��λ��
		{
			if (a[j] < a[min])
			{
				min = j;//������Сֵλ��
			}
		}
		if (min != i)//����Сֵλ�ñ�����
		{
			swap(a[i], a[min]);
		}
	}
}

//������
//˼�룺�����������������Ԫ�����������һλ���н������´ι���len-1�Ĵ����������
void AdjustDown(int data[], int root, int len)
{
	int dad = root;
	int son = 2 * dad + 1; //�����±�
	while (son <= len)
	{
		//�������£���ÿ��С����Ƿ��бȸ����Ԫ�أ����У��򽻻����׺ͺ��ӡ�ֱ��ÿ��С�����鿴����
		if (son + 1 <= len && data[son] < data[son + 1])//������û���Һ��ӣ��Ƚ����Һ���ѡ���
		{
			son++;
		}
		if (data[son] > data[dad])//�ȽϺ��Ӻ͸��ף����ӱȸ��״�
		{
			swap(data[son], data[dad]);//����
			//����������С�������б���
			dad = son;
			son = 2 * dad + 1;//��������
		}
		else {
			break;
		}
	}
}

void HeapSort(int data[], int len)
{
	//��ϰ����������0-9����Ԫ�أ�iλ�õ�����Ϊ2i+1,�Һ���2i+2��iλ�õĸ��׽ڵ㣨i-1��/2������˭��Ҷ�ӽڵ㣬i<=(n-1)/2
	int i;
	//�������,[10��Ԫ�أ�0��1��2��3��4λ��Ϊ���ڵ�,len=9]
	for (i = len / 2; i >= 0; i--)
	{
		AdjustDown(data, i, len);
	}
	//�����������������һ��Ԫ��,
	swap(data[0], data[len]);


	//�ٴι���len-1�Ĵ����
	for (i = len - 1; i > 0; i--)
	{
		AdjustDown(data, 0, i);//ʣ��Ԫ�ص���Ϊ�����
		swap(data[0], data[i]);
	}
}


int main()
{
	int a[10] = { 0 };//ѡ�������Ԫ��

	int i;//���ڼ�����������
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &a[i]);
	}

	int b[10] = { 0 };//������Ԫ��
	memcpy(b, a, sizeof(a));

	//ѡ������
	SelectSort(a, 10);
	PrintInt(a);//��ӡԪ��

	//������
	HeapSort(b, 9);
	PrintInt(b);//��ӡԪ��
	return 0;
}