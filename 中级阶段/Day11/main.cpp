//��ȡ10����������12 63 58 95 41 35 65  0 38 44��
//Ȼ��ͨ��ð�����򣬿������򣬲������򣬷ֱ�Ը������ݽ�������(��С���󣩣����3����������ÿ���������ռ3���ո�

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

//��������Ԫ��
void swap(int& x, int& y)
{
	int temp;
	temp = x;
	x = y;
	y = temp;
}

void Printf_Int(int data[])
{
	int i;
	for (i = 0; i < 10; i++)
	{
		printf("%3d", data[i]);
	}
	printf("\n");
}

//ð������
void BubbleSort(int data[], int len)
{
	int i;//�������ѭ�������n-1��
	int j;//�����ڲ�ѭ����������β��ǰ���н�������n-1��ʼ��9��
	for (i = 0; i < len - 1; i++)
	{
		int flag = 0;//ȷ�������Ƿ񽻻���1Ϊ����
		for (j = len - 1; j = j; j--)
		{
			//��һ��ѭ������ʱ��j=9��������β
			if (data[j - 1] > data[j])
			{
				swap(data[j - 1], data[j]);//����Ԫ�أ�ʹС����ǰ��
				flag = 1;//��ʾ�Ѿ�����
			}
		}
		if (0 == flag)
		{
			return ;//�����Ѿ��ź�˳�򣬺�������
		}
	}
}

//�����н���
int change(int kuai[], int left, int right)
{
	int k;//ָ��Ҫ��������Ԫ�أ�������ǰ>data[right])
	int i;//���Ա���Ԫ��

	for (i = k = left; i < right; i++)
	{
		if (kuai[i] < kuai[right])
		{
			swap(kuai[i], kuai[k]);
			k++;
		}
	}
	swap(kuai[right], kuai[k]);//�����һλ�뵱ǰk����
	return k;
}

// 64 94 95 79 69 84 18 22 12 78
//��64С�ķ�����ߣ���64��ķ����ұ�
int Partition(int A[],int low,int high)
{
	int pivot=A[low];//������ߵ�ֵ�ݴ棬��Ϊ��׼ֵ����ʱ�������ߵ�һ����
	while(low<high)
	{
		while (low < high && A[high] >= pivot)//������ǰ�ң��ҵ�һ���ȱ�׼ֵС��ֵ
		{
			--high;
		}	
		A[low]=A[high];//����ֵ�ŵ����λ
		while (low < high && A[low] <= pivot)//������ǰ���ҵ�һ���ȱ�׼ֵ���ֵ
		{
			++low;
		}
		A[high]=A[low];//�����ֵ���
	}
	A[low]=pivot;//���ݴ�ֵ���뱾�������Ŀ�λ������߶�С�������ұ߶�������
	return low;
}
//��������
void QuickSort(int kuai[], int low, int high)
{
	int pos;
	if (low < high)
	{
		pos = change(kuai, low, high);//�����д
		//pos = Partition(kuai, low, high);//�������ϵ�д��
		QuickSort(kuai, pos+1, high);//��벿������
		QuickSort(kuai, low, pos-1);//ǰ�벿������
	}
}

void InsertSort(int elem[], int n)
{
	int i;//���ѭ����ָ��Ҫ�����������е�Ԫ��
	int j;//�ڲ�ѭ����ָ��Ҫ�����λ��

	//��1-10��Ԫ�أ���Ҫ�������2-10
	for (i = 2; i <= n; i++)
	{
		if (elem[i - 1] > elem[i])//elem[1]>elem[2]
		{
			elem[0] = elem[i];//�����ݴ�
			//���Ҳ���λ�ã����źõ������У����Գ����������
			for (j = i - 1; elem[0] < elem[j]; j--)
			{
				elem[j + 1] = elem[j];//������
			}
			elem[j + 1] = elem[0];//�����Ԫ��
		}
	}
}

int main()
{
	int data[10] = { 0 };
	int kuai[10] = { 0 };//���ڿ���
	int elem[11] = { 0 };//���ڲ���

	int i;//���Լ�������
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &data[i]);
	}

	//�������������Ԫ��
	memcpy(kuai, data, sizeof(data));
	memcpy(elem + 1, data, sizeof(data));
	elem[0] = 0;//��Ϊ�ڱ�

	//ð������
	//˼�룺�������ѭ����
	BubbleSort(data, 10);
	Printf_Int(data);//��ӡԪ��

	//��������
	//˼�룺���Σ�kʼ��ָ�򱻽�����Ԫ�أ�i���������i[last]��ÿ�αȽϵĶ���
	QuickSort(kuai, 0, 9);
	Printf_Int(kuai);//��ӡԪ��

	//��������
	//˼�룺��ÿ�������е�Ԫ�أ�����˳������Ѿ��ĺõ�������
	InsertSort(elem, 10);
	Printf_Int(kuai);//��ӡԪ��


	return 0;
}