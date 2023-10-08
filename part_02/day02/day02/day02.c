#define _CRT_SECURE_NO_WARNINGS

/*
	线性表：
		线性结构是一种最简单且常用的数据结构，线性结构的基本特点是节点之间满足线性关系；
		数据结构：
			动态数组
			链表
			栈
			队列
		特点：
			线性表是零个或者多个数据元素的有限序列，数据元素之间是有顺序的，数据元素个数是有限的，数据元素的类型必须相同；


		线性表的抽象数据类型定义：
			ADT线性表（List）
			Data
				线性表的数据对象集合为{ a1, a2, ……, an }，每个元素的类型均为DataType；
					其中，除第一个元素a1外，每个元素有且只有一个直接前驱元素，
					除了最后一个元素an外，每个元素有且只有一个直接后继元素；
					数据元素之间的关系是一一对应的；

			Operation（操作）：定义，增删改查
				// 初始化，建立一个空的线性表L。
				InitList(*L);

				// 若线性表为空，返回true，否则返回false
				ListEmpty(L);

				// 将线性表清空
				ClearList(*L);

				// 将线性表L中的第i个位置的元素返回给e
				GetElem(L, i, *e);

				// 在线性表L中的第i个位置插入新元素e
				ListInsert(*L, i, e);

				// 删除线性表L中的第i个位置元素，并用e返回其值
				ListDelete(*L, i, *e);

				// 返回线性表L的元素个数
				ListLength(L);

				// 销毁线性表
				DestroyList(*L);
		
		存储方式：
			顺序存储
			链式存储

		线性表的顺序存储结构称为动态数组
		线性表的链式存储结构称为链表

		动态数组实现过程中采用大量的接口编程，这样的编程模式有利于框架的稳定性和可扩展性！
			数据结构实现感悟：
				1、确定数据结构特征，需要根据用途考虑
				2、确定数据结构的接口，即增删改查功能
				3、可以先用伪代码实现如何使用数据结构，这样逆向分析数据结构的需求；

		动态数组特点与用途：
			特点：
				无需为线性表中的逻辑关系增加额外的空间；
				可以快速的获取表中合法位置的元素；（因为地址连续，可以通过step完成地址空间直接增减）
				插入和删除操作需要移动大量元素；
			用途：
				


*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include "dynamicArray.h"


//测试
struct Person
{
	char name[64];
	int age;
};

void myPrintPerson(void* data)
{
	struct Person* p = data;
	printf("姓名： %s 年龄：%d\n", p->name, p->age);

}

int myComparePerson(void* data1, void* data2)
{
	struct Person* p1 = data1;
	struct Person* p2 = data2;

	return  strcmp(p1->name, p2->name) == 0 && p1->age == p2->age;
}



void test01()
{
	// 测试动态数组结构基本操作
	
	//初始化动态数组
	struct dynamicArray* array = init_DynamicArray(5);

	//准备数据
	struct Person p1 = { "亚瑟", 18 };
	struct Person p2 = { "妲己", 20 };
	struct Person p3 = { "安琪拉", 19 };
	struct Person p4 = { "凯", 21 };
	struct Person p5 = { "孙悟空", 999 };
	struct Person p6 = { "李白", 999 };

	printf("插入数据前： 容量：%d  大小：%d\n", array->m_capacity, array->m_size);

	//插入数据
	insert_DynamicArray(array, 0, &p1);
	insert_DynamicArray(array, 0, &p2);
	insert_DynamicArray(array, 1, &p3);
	insert_DynamicArray(array, 0, &p4);
	insert_DynamicArray(array, -1, &p5);
	insert_DynamicArray(array, 2, &p6);

	//遍历数据
	foreach_DynamicArray(array, myPrintPerson);

	printf("插入数据后： 容量：%d  大小：%d\n", array->m_capacity, array->m_size);

	//测试删除 按位置删除
	removeByPos_DynamicArray(array, 2);
	printf("---------------------\n");
	foreach_DynamicArray(array, myPrintPerson);
	printf("删除数据后： 容量：%d  大小：%d\n", array->m_capacity, array->m_size);

	struct Person  p = { "亚瑟", 18 };
	removeByValue_DynamicArray(array, &p, myComparePerson);
	printf("---------------------\n");
	foreach_DynamicArray(array, myPrintPerson);
	printf("删除数据后： 容量：%d  大小：%d\n", array->m_capacity, array->m_size);

	//销毁数组
	destroy_DynamicArray(array);
	array = NULL;
}


int main()
{
	// 动态数组
	test01();


	return 0;
}


