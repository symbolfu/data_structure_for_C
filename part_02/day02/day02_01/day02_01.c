#define _CRT_SECURE_NO_WARNINGS


/*
		线性表的链式存储结构称为链表：
			动态数组的最大缺点：
				插入和删除时需要移动大量元素，这显然需要耗费时间；

			引出链表：
				链表为了表示每个数据元素与其直接后继元素之间的逻辑关系；
				每个元素除了存储本身的信息外，还需要存储指示其直接后继的信息；
			链表类型：
				单向链表
				双向链表
				循环链表

			本节主要结束单向链表：
				基本概念：
					表头结点：header
						链表中的第一个结点，包含指向第一个数据元素的指针以及链表自身的一些信息
					数据结点：Node
						链表中代表数据元素的结点，包含指向下一个数据元素的指针和数据元素的信息
					尾结点：tail
						链表中的最后一个数据结点，其下一元素指针为空，表示无后继
					链表结构体:
						包含header，和一些链表必要的信息，比如结构体大小；
				note：上面基本概念中已经说明了单向链表的结构和特点；

			链表和动态数组的抽象数据类型定义是一样，只是内部实现不一样而已；
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

		链表数据结构两段式：
			1、链表结构体
			2、结点结构体
				//节点结构体
				struct LinkNode
				{
					//数据域
					void* data;
					//指针域
					struct LinkNode* next;
				};

				//链表结构体
				struct LList
				{
					//头节点
					struct LinkNode pHeader;
					//链表长度
					int m_size;
				};
		链表特点与用途：
			特点：
				无需一次性定制链表的容量
				插入和删除操作无需移动数据元素
				数据元素必须保存后继元素的位置信息
				获取指定数据的元素操作需要顺序访问之前的元素
			用途：


*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "linkList.h"



//测试 
struct Person
{
	char name[64];
	int age;
};

void myPrintPerson(void* data)
{
	struct Person* p = data;
	printf("姓名：%s  年龄：%d\n", p->name, p->age);
}

int myComparePerson(void* data1, void* data2)
{
	struct Person* p1 = data1;
	struct Person* p2 = data2;

	return strcmp(p1->name, p2->name) == 0 && p1->age == p2->age;
}



void test01()
{
	//准备数据
	struct Person p1 = { "亚瑟", 18 };
	struct Person p2 = { "妲己", 20 };
	struct Person p3 = { "安琪拉", 19 };
	struct Person p4 = { "凯", 21 };
	struct Person p5 = { "孙悟空", 999 };
	struct Person p6 = { "李白", 999 };


	//初始化链表
	LinkList mylist = init_LinkList();

	printf("链表长度为：%d\n", size_LinkList(mylist));          //*********************

	//插入数据
	insert_LinkList(mylist, 0, &p1);
	insert_LinkList(mylist, 0, &p2);
	insert_LinkList(mylist, -1, &p3);
	insert_LinkList(mylist, 0, &p4);
	insert_LinkList(mylist, 1, &p5);
	insert_LinkList(mylist, 0, &p6);

	//遍历
	foreach_LinkList(mylist, myPrintPerson);

	printf("链表长度为：%d\n", size_LinkList(mylist));

	//测试删除 
	removeByPos_LinkList(mylist, 4);

	printf("------------------\n");

	foreach_LinkList(mylist, myPrintPerson);
	printf("链表长度为：%d\n", size_LinkList(mylist));

	struct Person p = { "孙悟空", 999 };
	removeByValue_LinkList(mylist, &p, myComparePerson);

	printf("------------------\n");

	foreach_LinkList(mylist, myPrintPerson);
	printf("链表长度为：%d\n", size_LinkList(mylist));

	//测试清空
	clear_LinkList(mylist);

	//返回链表长度
	printf("链表长度为：%d\n", size_LinkList(mylist));


	//销毁
	destroy_Linklist(mylist);
	mylist = NULL;

}


int main()
{
	// 链式
	test01();


	return 0;
}