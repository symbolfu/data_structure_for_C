#define _CRT_SECURE_NO_WARNINGS

/*
	队列：Queue
		链式存储
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "linkQueue.h"



struct Person
{
	void* node;             // 企业级链表结构
	char name[64];
	int age;
};

void test01()
{
	//初始化队列
	LinkQueue myQueue = init_LinkQueue();

	//准备数据
	struct Person p1 = { NULL,"aaa", 10 };
	struct Person p2 = { NULL,"bbb", 20 };
	struct Person p3 = { NULL,"ccc", 30 };
	struct Person p4 = { NULL,"ddd", 40 };

	//入队
	push_LinkQueue(myQueue, &p1);
	push_LinkQueue(myQueue, &p2);
	push_LinkQueue(myQueue, &p3);
	push_LinkQueue(myQueue, &p4);

	printf("队列大小为：%d\n", size_LinkQueue(myQueue));
	while (isEmpty_LinkQueue(myQueue) == 0)
	{
		//访问队头
		struct Person* pFront = front_LinkQueue(myQueue);
		printf("链式存储::队头元素 -- 姓名：%s  年龄： %d\n", pFront->name, pFront->age);
		//访问队尾
		struct Person* pBack = back_LinkQueue(myQueue);
		printf("链式存储::队尾元素 -- 姓名：%s  年龄： %d\n", pBack->name, pBack->age);
		//出队
		pop_LinkQueue(myQueue);
	}

	printf("队列大小为：%d\n", size_LinkQueue(myQueue));

	//销毁队列
	destroy_LinkQueue(myQueue);


}



int main()
{
	test01();

	return 0;
}