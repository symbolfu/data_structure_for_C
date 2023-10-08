#define _CRT_SECURE_NO_WARNINGS


/*
		���Ա����ʽ�洢�ṹ��Ϊ����
			��̬��������ȱ�㣺
				�����ɾ��ʱ��Ҫ�ƶ�����Ԫ�أ�����Ȼ��Ҫ�ķ�ʱ�䣻

			��������
				����Ϊ�˱�ʾÿ������Ԫ������ֱ�Ӻ��Ԫ��֮����߼���ϵ��
				ÿ��Ԫ�س��˴洢�������Ϣ�⣬����Ҫ�洢ָʾ��ֱ�Ӻ�̵���Ϣ��
			�������ͣ�
				��������
				˫������
				ѭ������

			������Ҫ������������
				�������
					��ͷ��㣺header
						�����еĵ�һ����㣬����ָ���һ������Ԫ�ص�ָ���Լ����������һЩ��Ϣ
					���ݽ�㣺Node
						�����д�������Ԫ�صĽ�㣬����ָ����һ������Ԫ�ص�ָ�������Ԫ�ص���Ϣ
					β��㣺tail
						�����е����һ�����ݽ�㣬����һԪ��ָ��Ϊ�գ���ʾ�޺��
					����ṹ��:
						����header����һЩ�����Ҫ����Ϣ������ṹ���С��
				note����������������Ѿ�˵���˵�������Ľṹ���ص㣻

			����Ͷ�̬����ĳ����������Ͷ�����һ����ֻ���ڲ�ʵ�ֲ�һ�����ѣ�
				���Ա�ĳ����������Ͷ��壺
				ADT���Ա�List��
					Data
						���Ա�����ݶ��󼯺�Ϊ{ a1, a2, ����, an }��ÿ��Ԫ�ص����;�ΪDataType��
							���У�����һ��Ԫ��a1�⣬ÿ��Ԫ������ֻ��һ��ֱ��ǰ��Ԫ�أ�
							�������һ��Ԫ��an�⣬ÿ��Ԫ������ֻ��һ��ֱ�Ӻ��Ԫ�أ�
							����Ԫ��֮��Ĺ�ϵ��һһ��Ӧ�ģ�

					Operation�������������壬��ɾ�Ĳ�
						// ��ʼ��������һ���յ����Ա�L��
						InitList(*L);

						// �����Ա�Ϊ�գ�����true�����򷵻�false
						ListEmpty(L);

						// �����Ա����
						ClearList(*L);

						// �����Ա�L�еĵ�i��λ�õ�Ԫ�ط��ظ�e
						GetElem(L, i, *e);

						// �����Ա�L�еĵ�i��λ�ò�����Ԫ��e
						ListInsert(*L, i, e);

						// ɾ�����Ա�L�еĵ�i��λ��Ԫ�أ�����e������ֵ
						ListDelete(*L, i, *e);

						// �������Ա�L��Ԫ�ظ���
						ListLength(L);

						// �������Ա�
						DestroyList(*L);

		�������ݽṹ����ʽ��
			1������ṹ��
			2�����ṹ��
				//�ڵ�ṹ��
				struct LinkNode
				{
					//������
					void* data;
					//ָ����
					struct LinkNode* next;
				};

				//����ṹ��
				struct LList
				{
					//ͷ�ڵ�
					struct LinkNode pHeader;
					//������
					int m_size;
				};
		�����ص�����;��
			�ص㣺
				����һ���Զ������������
				�����ɾ�����������ƶ�����Ԫ��
				����Ԫ�ر��뱣����Ԫ�ص�λ����Ϣ
				��ȡָ�����ݵ�Ԫ�ز�����Ҫ˳�����֮ǰ��Ԫ��
			��;��


*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "linkList.h"



//���� 
struct Person
{
	char name[64];
	int age;
};

void myPrintPerson(void* data)
{
	struct Person* p = data;
	printf("������%s  ���䣺%d\n", p->name, p->age);
}

int myComparePerson(void* data1, void* data2)
{
	struct Person* p1 = data1;
	struct Person* p2 = data2;

	return strcmp(p1->name, p2->name) == 0 && p1->age == p2->age;
}



void test01()
{
	//׼������
	struct Person p1 = { "��ɪ", 18 };
	struct Person p2 = { "槼�", 20 };
	struct Person p3 = { "������", 19 };
	struct Person p4 = { "��", 21 };
	struct Person p5 = { "�����", 999 };
	struct Person p6 = { "���", 999 };


	//��ʼ������
	LinkList mylist = init_LinkList();

	printf("������Ϊ��%d\n", size_LinkList(mylist));          //*********************

	//��������
	insert_LinkList(mylist, 0, &p1);
	insert_LinkList(mylist, 0, &p2);
	insert_LinkList(mylist, -1, &p3);
	insert_LinkList(mylist, 0, &p4);
	insert_LinkList(mylist, 1, &p5);
	insert_LinkList(mylist, 0, &p6);

	//����
	foreach_LinkList(mylist, myPrintPerson);

	printf("������Ϊ��%d\n", size_LinkList(mylist));

	//����ɾ�� 
	removeByPos_LinkList(mylist, 4);

	printf("------------------\n");

	foreach_LinkList(mylist, myPrintPerson);
	printf("������Ϊ��%d\n", size_LinkList(mylist));

	struct Person p = { "�����", 999 };
	removeByValue_LinkList(mylist, &p, myComparePerson);

	printf("------------------\n");

	foreach_LinkList(mylist, myPrintPerson);
	printf("������Ϊ��%d\n", size_LinkList(mylist));

	//�������
	clear_LinkList(mylist);

	//����������
	printf("������Ϊ��%d\n", size_LinkList(mylist));


	//����
	destroy_Linklist(mylist);
	mylist = NULL;

}


int main()
{
	// ��ʽ
	test01();


	return 0;
}