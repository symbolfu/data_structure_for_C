#define _CRT_SECURE_NO_WARNINGS


/*
		受限线性表：
			栈：stack
			队列：Queue

			栈：
				基本概念：
					首先它是一个线性表，也就是说，栈元素具有线性关系，即前驱后继关系。
					只不过它是一种特殊的线性表而已。定义中说是在线性表的表尾进行插入和删除操作，
					这里表尾是指栈顶（sp），而不是栈底（fp）

				特点：
					它的特殊之处在于限制了这个线性表的插入和删除的位置，它始终只在栈顶（低地址）进行。
					这也就使得：栈底（高地址）是固定的，最先进栈的只能在栈底；
					
					栈不支持遍历
					数组的首地址作栈底效率会更高，省去了出栈和进栈后续元素的移动；

				基本操作：
					进栈（压栈）：栈的插入操作；
					出栈（弹栈）：栈的删除操作；

				基本接口：
					栈的初始化
					入栈
					出栈
					返回栈顶元素
					栈大小
					栈是否为空
					销毁栈

				存储结构：
					顺序存储
					链式存储

*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "seqStack.h"

struct Person
{
	char name[64];
	int age;
};


void test01()
{
	//初始化栈
	SeqStack myStack = init_SeqStack();

	//创建数据
	struct Person p1 = { "aaa", 10 };
	struct Person p2 = { "bbb", 20 };
	struct Person p3 = { "ccc", 30 };
	struct Person p4 = { "ddd", 40 };
	struct Person p5 = { "eee", 50 };

	//入栈
	push_SeqStack(myStack, &p1);
	push_SeqStack(myStack, &p2);
	push_SeqStack(myStack, &p3);
	push_SeqStack(myStack, &p4);
	push_SeqStack(myStack, &p5);

	printf("栈的元素个数为：%d\n", size_SeqStack(myStack));

	while (isEmpty_SeqStack(myStack) == 0) //栈不为空，查看栈顶元素，出栈
	{
		struct Person* p = top_SeqStack(myStack);
		printf("姓名：%s 年龄：%d\n", p->name, p->age);

		//出栈
		pop_SeqStack(myStack);
	}


	printf("栈的元素个数为：%d\n", size_SeqStack(myStack));

	//销毁栈
	destroy_SeqStack(myStack);

	myStack = NULL;



}


int main()
{
	// 栈的顺序存储结构
	test01();

	return 0;
}