//��ȡ10����������12 63 58 95 41 35 65  0 38 44��Ȼ��ͨ���鲢����
//�Ը������ݽ������������������ÿ���������ռ3���ո�
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

void PrintInt(int data[])
{
	int i;//�������
	for (i = 0; i < 10; i++)
	{
		printf("%3d", data[i]);
	}
	printf("\n");
}

void Merge(int data[], int low, int mid, int high)
{
	//��Ԫ�ظ��Ƶ��µ������У���ֵ�ݴ�
	int temp[10] = { 0 };
	int k;//���Ը��Ƽ���
	for (k = low; k <= high; k++)
	{
		temp[k] = data[k];
	}

	int i = low;//ָ��ǰ������ĵ�һ��ֵ
	int j = mid + 1;//ָ��������ĵ�һ��ֵ
	for (k = i; i <= mid && j <= high; k++)//�ϲ�������������
	{
		if (temp[i] > temp[j])//ǰ�������е�Ԫ�أ���������е�Ԫ��
		{
			data[k] = temp[j];//��С����������������
			j++;//����ɨ��������,Ҳ��ѭ����������
		}
		else//ǰ�������е�Ԫ��<��������е�Ԫ��
		{
			data[k] = temp[i];//��С����������������
			i++;//����ɨ��ǰ�����飬Ҳ��ѭ����������
		}
	}//forѭ��

	//ǰ������δ����꣨����ֺ������ȫ��ǰ������ĳ��Ԫ��С�����������ʣ��Ԫ�ظ��Ƶ�����������
	while (i <= mid)
	{
		data[k] = temp[i];
		i++;
		k++;
	}
	while (j <= high)
	{
		data[k] = temp[j];
		j++;
		k++;
	}
}

//�鲢����
//˼�룺������������ϳ�һ���µ�������������Ԫ�ظ���[1,2,4,8...]
void MergeSort(int data[], int low, int high)
{
	//��10��Ԫ�أ��±��0-9
	if (low < high)//������Ԫ�أ�0��1ʱ���������ݹ飬��ֱ�Ӻϲ�
	{
		int mid = (low + high) / 2;//�����Ϊ�����֣�mid=4 ÿ�ζ�Ҫ����
		MergeSort(data, low, mid);//��ǰ�벿�ֱ�Ϊ�����
		MergeSort(data, mid + 1, high);//����벿�ֱ�Ϊ�����
		Merge(data, low, mid, high);//�ϲ����������
	}
}

int main()
{
	int data[10] = { 0 };//������������
	int i;//��������

	for (i = 0; i < 10; i++)
	{
		scanf("%d", &data[i]);
	}
	//�鲢����
	MergeSort(data, 0, 9);
	PrintInt(data);
	return 0;
}