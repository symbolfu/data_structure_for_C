#define _CRT_SECURE_NO_WARNINGS


/*
		企业级链表设计:
			传统链表的结构将指针和数据绑定，降低了框架的稳定性和可扩展性；

			引出：
				企业级链表
				原理：节点只维护指针域，用户数据预留前四个字节由底层使用；

			企业级链表原型和传统链表一样；

			优点：
				用户开发过程中只需要预留前4字节，其他可由用户随意使用；
				可使得框架结构更稳定，扩展性更强；

			特点：
				用户开发过程中只需要预留前4字节的缘故，所以开发时按接口编程开发，功能函数由用户实现

*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "linkList.h"



//测试

struct Person
{
	void* node;
	char name[64];
	int age;
};


void myPrintPerson(void* data)
{
	struct Person* p = data;
	printf("姓名： %s  年龄： %d \n", p->name, p->age);
}



void test01()
{
	//初始化链表
	LinkList mylist = init_LinkList();

	//创建数据
	struct Person p1 = { NULL,"aaa", 10 };
	struct Person p2 = { NULL,"bbb", 20 };
	struct Person p3 = { NULL,"ccc", 30 };
	struct Person p4 = { NULL,"ddd", 40 };
	struct Person p5 = { NULL,"eee", 50 };

	//插入节点
	insert_LinkList(mylist, 0, &p1);
	insert_LinkList(mylist, 0, &p2);
	insert_LinkList(mylist, 1, &p3);
	insert_LinkList(mylist, -1, &p4);
	insert_LinkList(mylist, 0, &p5);


	//遍历链表
	// eee bbb  ccc aaa ddd
	foreach_LinkList(mylist, myPrintPerson);

	//删除 aaa
	removeByPos_ListList(mylist, 3);
	printf("-----------------------\n");
	foreach_LinkList(mylist, myPrintPerson);

	//销毁数组
	destroy_LinkList(mylist);
	mylist = NULL;

}



int main()
{
	// 企业级链式
	test01();


	return 0;
}
