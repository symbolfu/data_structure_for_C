#define _CRT_SECURE_NO_WARNINGS

/*
	ջ����ʽ�洢�ṹ
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "LinkStack.h"

//����
struct Person
{
	void* node;           // ��ҵ������ʵ�ַ�ʽ    
	char name[64];
	int age;
};




void test01()
{
	//��ʼ��ջ
	LinkStack myStack = init_LinkStack();

	//��������
	struct Person p1 = { NULL, "aaa", 10 };
	struct Person p2 = { NULL, "bbb", 20 };
	struct Person p3 = { NULL, "ccc", 30 };
	struct Person p4 = { NULL, "ddd", 40 };
	struct Person p5 = { NULL, "eee", 50 };

	//��ջ
	push_LinkStack(myStack, &p1);
	push_LinkStack(myStack, &p2);
	push_LinkStack(myStack, &p3);
	push_LinkStack(myStack, &p4);
	push_LinkStack(myStack, &p5);

	printf("��ʽ�洢-- ջ��Ԫ�ظ���Ϊ��%d\n", size_LinkStack(myStack));

	while (isEmpty_LinkStack(myStack) == 0) //ջ��Ϊ�գ��鿴ջ��Ԫ�أ���ջ
	{
		struct Person* p = top_LinkStack(myStack);
		printf("������%s ���䣺%d\n", p->name, p->age);

		//��ջ
		pop_LinkStack(myStack);
	}

	printf("��ʽ�洢-- ջ��Ԫ�ظ���Ϊ��%d\n", size_LinkStack(myStack));

	//����ջ
	destroy_LinkStack(myStack);

	myStack = NULL;


}


int main()
{
	// ջ��˳��洢�ṹ
	test01();

	return 0;
}