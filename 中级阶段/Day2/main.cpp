//��Ҫʹ��C++�е����ã��������ÿ��Թ�ܶ���ָ���ʹ�úͽ��c�����Ӻ�����ֻ��ֵ������ַ������

//ʹ��C++�����ã�ע���ύʱ�Ѵ���ѡΪC++���������������ַ�ָ�� char *p,Ȼ�����Ӻ�����malloc����ռ䣬ͨ��fgets��ȡ�ַ�����
//Ȼ�����������н��������Ҫ���Ӻ���ʹ��C++�����ã�ע����C++�дӱ�׼�����ȡ�ַ�������Ҫʹ��fgets(p,100,stdin)

#include<stdio.h>
#include <malloc.h>

void printf_str(char* &q)
{
	q = (char*)malloc(100);
	fgets(q, 100, stdin);

}

int main()
{
	char* p = NULL;

	//��ע��ָ����"����"ʱ�Ĵ���
	printf_str(p);
	puts(p);
	return 0;
}