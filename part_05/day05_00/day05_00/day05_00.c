#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


/*
	排序算法
		排序是计算机内经常进行的一种操作，其目的是将一组“无序”的数据元素调整为“有序”的数据元素；
		https://blog.csdn.net/m0_37741420/article/details/106981276?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522169906198616800180646554%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=169906198616800180646554&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~top_positive~default-1-106981276-null-null.142^v96^pc_search_result_base8&utm_term=%E9%80%89%E6%8B%A9%E6%8E%92%E5%BA%8F&spm=1018.2226.3001.4187

		关键操作：
			比较： 任意两个数据元素通过比较操作确定先后次序
			交换： 数据元素之间需要交换才能得到预期结果


		排序算法：
			冒泡排序：
				冒泡排序是一种效率低下的排序方法，在数据规模很小时，可以采用；
				原理：
					相邻的元素两两比较，较大的数下沉，较小的数冒起来

			选择排序：
				原理：
					第一次从待排序的数据元素中选出最小（或最大）的一个元素，存放在序列的起始位置，
					然后再从剩余的未排序元素中寻找到最小（大）元素，继续放在起始位置知道未排序元素个数为0；

			插入排序：
				插入排序算法是一个队少量元素进行排序的有效算法
				原理：
					将初始数据分为有序部分和无序部分，每一步将一个无序部分的数据插入到前面已经排好序的有序部分中，直到插完所有元素为止；
				
				
	
*/


void insertSort(int arr[], int len)
{
	for (int i = 1; i < len; i++)
	{
		if (arr[i - 1] > arr[i])
		{
			int temp = arr[i];
			int j = i - 1;

			//数据后移并且找到insert index
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
	//插入排序
	int len = sizeof(arr) / sizeof(int);
	insertSort(arr, len);

	//打印数组
	printArray(arr, len);
}


int main()
{
	test01();


	return 0;
}