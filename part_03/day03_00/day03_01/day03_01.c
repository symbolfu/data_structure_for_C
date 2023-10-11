#define _CRT_SECURE_NO_WARNINGS

/*
	栈的链式存储结构
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "LinkStack.h"

//测试
struct Person
{
	void* node;           // 企业级链表实现方式    
	char name[64];
	int age;
};




void test01()
{
	//初始化栈
	LinkStack myStack = init_LinkStack();

	//创建数据
	struct Person p1 = { NULL, "aaa", 10 };
	struct Person p2 = { NULL, "bbb", 20 };
	struct Person p3 = { NULL, "ccc", 30 };
	struct Person p4 = { NULL, "ddd", 40 };
	struct Person p5 = { NULL, "eee", 50 };

	//入栈
	push_LinkStack(myStack, &p1);
	push_LinkStack(myStack, &p2);
	push_LinkStack(myStack, &p3);
	push_LinkStack(myStack, &p4);
	push_LinkStack(myStack, &p5);

	printf("链式存储-- 栈的元素个数为：%d\n", size_LinkStack(myStack));

	while (isEmpty_LinkStack(myStack) == 0) //栈不为空，查看栈顶元素，出栈
	{
		struct Person* p = top_LinkStack(myStack);
		printf("姓名：%s 年龄：%d\n", p->name, p->age);

		//出栈
		pop_LinkStack(myStack);
	}

	printf("链式存储-- 栈的元素个数为：%d\n", size_LinkStack(myStack));

	//销毁栈
	destroy_LinkStack(myStack);

	myStack = NULL;


}


int main()
{
	// 栈的顺序存储结构
	test01();

	return 0;
}