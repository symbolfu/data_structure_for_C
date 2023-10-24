#define _CRT_SECURE_NO_WARNINGS

/*
	���У�Queue
		�ص㣺
			ֻ������һ�˽��в��������
			������һ�˽���ɾ�����������Ա�
		������һ���Ƚ��ȳ���t��First In First Out�������Ա����FIFO��

		�洢�ṹ��
			˳��洢
			��ʽ�洢

*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "seqQueue.h"


struct Person
{
	char name[64];
	int age;
};


void test01()
{
	seqQueue myQueue = init_SeqQueue();

	//׼������
	struct Person p1 = { "aaa", 10 };
	struct Person p2 = { "bbb", 20 };
	struct Person p3 = { "ccc", 30 };
	struct Person p4 = { "ddd", 40 };

	//���
	push_SeqQueue(myQueue, &p1);
	push_SeqQueue(myQueue, &p2);
	push_SeqQueue(myQueue, &p3);
	push_SeqQueue(myQueue, &p4);

	printf("���д�СΪ��%d\n", size_SeqQueue(myQueue));

	while (isEmpty_SeqQueue(myQueue) == 0)
	{
		//���ʶ�ͷ
		struct Person* pFront = front_SeqQueue(myQueue);
		printf("��ͷԪ�� -- ������%s  ���䣺 %d\n", pFront->name, pFront->age);
		//���ʶ�β
		struct Person* pBack = back_SeqQueue(myQueue);
		printf("��βԪ�� -- ������%s  ���䣺 %d\n", pBack->name, pBack->age);
		//����
		pop_SeqQueue(myQueue);
	}

	printf("���д�СΪ��%d\n", size_SeqQueue(myQueue));

	//���ٶ���
	destroy_SeqQueue(myQueue);

}



int main()
{
	test01();

	return 0;
}
