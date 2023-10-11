#include "LinkStack.h"


//节点结构体
struct stackNode
{
	struct stackNode* next;
};

//栈的结构体
struct LStack
{
	struct stackNode  pHeader;
	int m_size;
};


//初始化
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

//入栈
void push_LinkStack(LinkStack stack, void* data)
{
	//入栈本质 --- 链表头插
	if (stack == NULL)
	{
		return;
	}

	if (data == NULL)
	{
		return;
	}

	struct LStack* myStack = stack;

	//将用户数据 取出前4字节用
	struct stackNode* myNode = data;

	//更改指针指向
	myNode->next = myStack->pHeader.next;
	myStack->pHeader.next = myNode;

	//更新链表长度
	myStack->m_size++;
}

//出栈
void pop_LinkStack(LinkStack stack)
{
	//出栈本质 --- 链表头删
	if (stack == NULL)
	{
		return;
	}

	struct LStack* myStack = stack;

	if (myStack->m_size == 0)
	{
		return;
	}

	//更改指针指向
	//缓存第一个有数据节点
	struct stackNode* pFirst = myStack->pHeader.next;

	myStack->pHeader.next = pFirst->next;

	//更新栈大小
	myStack->m_size--;
}

//返回栈顶元素
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

//返回栈个数
int size_LinkStack(LinkStack stack)
{
	if (stack == NULL)
	{
		return -1;
	}
	struct LStack* myStack = stack;

	return myStack->m_size;
}

//判断是否为空
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

//销毁
void destroy_LinkStack(LinkStack stack)
{
	if (stack == NULL)
	{
		return;
	}
	free(stack);
	stack = NULL;
}