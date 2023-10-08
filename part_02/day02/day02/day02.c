#define _CRT_SECURE_NO_WARNINGS

/*
	���Ա�
		���Խṹ��һ������ҳ��õ����ݽṹ�����Խṹ�Ļ����ص��ǽڵ�֮���������Թ�ϵ��
		���ݽṹ��
			��̬����
			����
			ջ
			����
		�ص㣺
			���Ա���������߶������Ԫ�ص��������У�����Ԫ��֮������˳��ģ�����Ԫ�ظ��������޵ģ�����Ԫ�ص����ͱ�����ͬ��


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
		
		�洢��ʽ��
			˳��洢
			��ʽ�洢

		���Ա��˳��洢�ṹ��Ϊ��̬����
		���Ա����ʽ�洢�ṹ��Ϊ����

		��̬����ʵ�ֹ����в��ô����Ľӿڱ�̣������ı��ģʽ�����ڿ�ܵ��ȶ��ԺͿ���չ�ԣ�
			���ݽṹʵ�ָ���
				1��ȷ�����ݽṹ��������Ҫ������;����
				2��ȷ�����ݽṹ�Ľӿڣ�����ɾ�Ĳ鹦��
				3����������α����ʵ�����ʹ�����ݽṹ����������������ݽṹ������

		��̬�����ص�����;��
			�ص㣺
				����Ϊ���Ա��е��߼���ϵ���Ӷ���Ŀռ䣻
				���Կ��ٵĻ�ȡ���кϷ�λ�õ�Ԫ�أ�����Ϊ��ַ����������ͨ��step��ɵ�ַ�ռ�ֱ��������
				�����ɾ��������Ҫ�ƶ�����Ԫ�أ�
			��;��
				


*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include "dynamicArray.h"


//����
struct Person
{
	char name[64];
	int age;
};

void myPrintPerson(void* data)
{
	struct Person* p = data;
	printf("������ %s ���䣺%d\n", p->name, p->age);

}

int myComparePerson(void* data1, void* data2)
{
	struct Person* p1 = data1;
	struct Person* p2 = data2;

	return  strcmp(p1->name, p2->name) == 0 && p1->age == p2->age;
}



void test01()
{
	// ���Զ�̬����ṹ��������
	
	//��ʼ����̬����
	struct dynamicArray* array = init_DynamicArray(5);

	//׼������
	struct Person p1 = { "��ɪ", 18 };
	struct Person p2 = { "槼�", 20 };
	struct Person p3 = { "������", 19 };
	struct Person p4 = { "��", 21 };
	struct Person p5 = { "�����", 999 };
	struct Person p6 = { "���", 999 };

	printf("��������ǰ�� ������%d  ��С��%d\n", array->m_capacity, array->m_size);

	//��������
	insert_DynamicArray(array, 0, &p1);
	insert_DynamicArray(array, 0, &p2);
	insert_DynamicArray(array, 1, &p3);
	insert_DynamicArray(array, 0, &p4);
	insert_DynamicArray(array, -1, &p5);
	insert_DynamicArray(array, 2, &p6);

	//��������
	foreach_DynamicArray(array, myPrintPerson);

	printf("�������ݺ� ������%d  ��С��%d\n", array->m_capacity, array->m_size);

	//����ɾ�� ��λ��ɾ��
	removeByPos_DynamicArray(array, 2);
	printf("---------------------\n");
	foreach_DynamicArray(array, myPrintPerson);
	printf("ɾ�����ݺ� ������%d  ��С��%d\n", array->m_capacity, array->m_size);

	struct Person  p = { "��ɪ", 18 };
	removeByValue_DynamicArray(array, &p, myComparePerson);
	printf("---------------------\n");
	foreach_DynamicArray(array, myPrintPerson);
	printf("ɾ�����ݺ� ������%d  ��С��%d\n", array->m_capacity, array->m_size);

	//��������
	destroy_DynamicArray(array);
	array = NULL;
}


int main()
{
	// ��̬����
	test01();


	return 0;
}


