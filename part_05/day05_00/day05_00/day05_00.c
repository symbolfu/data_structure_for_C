#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


/*
	�����㷨
		�����Ǽ�����ھ������е�һ�ֲ�������Ŀ���ǽ�һ�顰���򡱵�����Ԫ�ص���Ϊ�����򡱵�����Ԫ�أ�
		https://blog.csdn.net/m0_37741420/article/details/106981276?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522169906198616800180646554%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=169906198616800180646554&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~top_positive~default-1-106981276-null-null.142^v96^pc_search_result_base8&utm_term=%E9%80%89%E6%8B%A9%E6%8E%92%E5%BA%8F&spm=1018.2226.3001.4187

		�ؼ�������
			�Ƚϣ� ������������Ԫ��ͨ���Ƚϲ���ȷ���Ⱥ����
			������ ����Ԫ��֮����Ҫ�������ܵõ�Ԥ�ڽ��


		�����㷨��
			ð������
				ð��������һ��Ч�ʵ��µ����򷽷��������ݹ�ģ��Сʱ�����Բ��ã�
				ԭ��
					���ڵ�Ԫ�������Ƚϣ��ϴ�����³�����С����ð����

			ѡ������
				ԭ��
					��һ�δӴ����������Ԫ����ѡ����С������󣩵�һ��Ԫ�أ���������е���ʼλ�ã�
					Ȼ���ٴ�ʣ���δ����Ԫ����Ѱ�ҵ���С����Ԫ�أ�����������ʼλ��֪��δ����Ԫ�ظ���Ϊ0��

			��������
				���������㷨��һ��������Ԫ�ؽ����������Ч�㷨
				ԭ��
					����ʼ���ݷ�Ϊ���򲿷ֺ����򲿷֣�ÿһ����һ�����򲿷ֵ����ݲ��뵽ǰ���Ѿ��ź�������򲿷��У�ֱ����������Ԫ��Ϊֹ��
				
				
	
*/


void insertSort(int arr[], int len)
{
	for (int i = 1; i < len; i++)
	{
		if (arr[i - 1] > arr[i])
		{
			int temp = arr[i];
			int j = i - 1;

			//���ݺ��Ʋ����ҵ�insert index
			for (; j >= 0 && temp < arr[j]; j--)
			{
				
				arr[j + 1] = arr[j];
			}

			arr[j + 1] = temp;
		}
	}
}

void printArray(int arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d\n", arr[i]);
	}
}



int test01()
{
	int arr[] = { 4, 1, 2, 3, 5, 7, 6 };
	//��������
	int len = sizeof(arr) / sizeof(int);
	insertSort(arr, len);

	//��ӡ����
	printArray(arr, len);
}


int main()
{
	test01();


	return 0;
}