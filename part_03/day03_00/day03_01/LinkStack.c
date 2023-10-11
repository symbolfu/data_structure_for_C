#include "LinkStack.h"


//�ڵ�ṹ��
struct stackNode
{
	struct stackNode* next;
};

//ջ�Ľṹ��
struct LStack
{
	struct stackNode  pHeader;
	int m_size;
};


//��ʼ��
LinkStack init_LinkStack()
{
	struct LStack* myStack = malloc(sizeof(struct LStack));

	if (myStack == NULL)
	{
		return NULL;
	}
	myStack->pHeader.next = NULL;
	myStack->m_size = 0;

	return myStack;
}

//��ջ
void push_LinkStack(LinkStack stack, void* data)
{
	//��ջ���� --- ����ͷ��
	if (stack == NULL)
	{
		return;
	}

	if (data == NULL)
	{
		return;
	}

	struct LStack* myStack = stack;

	//���û����� ȡ��ǰ4�ֽ���
	struct stackNode* myNode = data;

	//����ָ��ָ��
	myNode->next = myStack->pHeader.next;
	myStack->pHeader.next = myNode;

	//����������
	myStack->m_size++;
}

//��ջ
void pop_LinkStack(LinkStack stack)
{
	//��ջ���� --- ����ͷɾ
	if (stack == NULL)
	{
		return;
	}

	struct LStack* myStack = stack;

	if (myStack->m_size == 0)
	{
		return;
	}

	//����ָ��ָ��
	//�����һ�������ݽڵ�
	struct stackNode* pFirst = myStack->pHeader.next;

	myStack->pHeader.next = pFirst->next;

	//����ջ��С
	myStack->m_size--;
}

//����ջ��Ԫ��
void* top_LinkStack(LinkStack stack)
{
	if (stack == NULL)
	{
		return NULL;
	}
	struct LStack* myStack = stack;

	if (myStack->m_size == 0)
	{
		return NULL;
	}

	return myStack->pHeader.next;
}

//����ջ����
int size_LinkStack(LinkStack stack)
{
	if (stack == NULL)
	{
		return -1;
	}
	struct LStack* myStack = stack;

	return myStack->m_size;
}

//�ж��Ƿ�Ϊ��
int isEmpty_LinkStack(LinkStack stack)
{
	if (stack == NULL)
	{
		return -1;
	}
	struct LStack* myStack = stack;

	if (myStack->m_size == 0)
	{
		return 1;
	}

	return 0;
}

//����
void destroy_LinkStack(LinkStack stack)
{
	if (stack == NULL)
	{
		return;
	}
	free(stack);
	stack = NULL;
}