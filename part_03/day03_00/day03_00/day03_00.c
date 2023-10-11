#define _CRT_SECURE_NO_WARNINGS


/*
		�������Ա�
			ջ��stack
			���У�Queue

			ջ��
				�������
					��������һ�����Ա�Ҳ����˵��ջԪ�ؾ������Թ�ϵ����ǰ����̹�ϵ��
					ֻ��������һ����������Ա���ѡ�������˵�������Ա�ı�β���в����ɾ��������
					�����β��ָջ����sp����������ջ�ף�fp��

				�ص㣺
					��������֮������������������Ա�Ĳ����ɾ����λ�ã���ʼ��ֻ��ջ�����͵�ַ�����С�
					��Ҳ��ʹ�ã�ջ�ף��ߵ�ַ���ǹ̶��ģ����Ƚ�ջ��ֻ����ջ�ף�
					
					ջ��֧�ֱ���
					������׵�ַ��ջ��Ч�ʻ���ߣ�ʡȥ�˳�ջ�ͽ�ջ����Ԫ�ص��ƶ���

				����������
					��ջ��ѹջ����ջ�Ĳ��������
					��ջ����ջ����ջ��ɾ��������

				�����ӿڣ�
					ջ�ĳ�ʼ��
					��ջ
					��ջ
					����ջ��Ԫ��
					ջ��С
					ջ�Ƿ�Ϊ��
					����ջ

				�洢�ṹ��
					˳��洢
					��ʽ�洢

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
	//��ʼ��ջ
	SeqStack myStack = init_SeqStack();

	//��������
	struct Person p1 = { "aaa", 10 };
	struct Person p2 = { "bbb", 20 };
	struct Person p3 = { "ccc", 30 };
	struct Person p4 = { "ddd", 40 };
	struct Person p5 = { "eee", 50 };

	//��ջ
	push_SeqStack(myStack, &p1);
	push_SeqStack(myStack, &p2);
	push_SeqStack(myStack, &p3);
	push_SeqStack(myStack, &p4);
	push_SeqStack(myStack, &p5);

	printf("ջ��Ԫ�ظ���Ϊ��%d\n", size_SeqStack(myStack));

	while (isEmpty_SeqStack(myStack) == 0) //ջ��Ϊ�գ��鿴ջ��Ԫ�أ���ջ
	{
		struct Person* p = top_SeqStack(myStack);
		printf("������%s ���䣺%d\n", p->name, p->age);

		//��ջ
		pop_SeqStack(myStack);
	}


	printf("ջ��Ԫ�ظ���Ϊ��%d\n", size_SeqStack(myStack));

	//����ջ
	destroy_SeqStack(myStack);

	myStack = NULL;



}


int main()
{
	// ջ��˳��洢�ṹ
	test01();

	return 0;
}