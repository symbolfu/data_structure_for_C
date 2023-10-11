#include "seqStack.h"



// 为什么定义到c文件中而不是头文件中定义呢？
// 因为这个结构体只是函数体实现内部使用，并没在函数声明中使用
// 为了放置结构体名称的污染，放置到这里，这是一个很好的编程习惯
struct SStack
{
	void* data[MAX];  //栈的数组       // 这里既可以为数组也可以指针数组，指针数组可以保持结构的稳定性；

	int m_Size; //栈大小
};


//初始化栈
SeqStack init_SeqStack()
{
	struct SStack* myStack = malloc(sizeof(struct SStack));

	if (myStack == NULL)
	{
		return NULL;
	}

	//初始化数组
	// 全局变量和局部静态变量是存储在静态存储区的，他们在分配的时候都被系统默认初始化为0;
	// 局部自动变量是在栈上分配内存的，如果不对它们进行初始化，那么他们可能是任意的随机值;
	memset(myStack->data, 0, sizeof(void*) * MAX);

	//初始化栈大小
	myStack->m_Size = 0;

	return myStack;
}

//入栈
void push_SeqStack(SeqStack stack, void* data)
{
	//入栈本质  --- 数组尾插
	if (stack == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}

	struct SStack* mystack = stack;
	if (mystack->m_Size == MAX)
	{
		return;
	}

	mystack->data[mystack->m_Size] = data;

	mystack->m_Size++;
}

//出栈
void pop_SeqStack(SeqStack stack)
{
	//出栈本质  --- 数组尾删
	if (stack == NULL)
	{
		return;
	}

	struct SStack* mystack = stack;

	if (mystack->m_Size == 0)
	{
		return;
	}

	mystack->data[mystack->m_Size - 1] = NULL;

	mystack->m_Size--;
}

//返回栈顶
void* top_SeqStack(SeqStack stack)
{
	if (stack == NULL)
	{
		return NULL;
	}

	struct SStack* mystack = stack;

	if (mystack->m_Size == 0)
	{
		return NULL;
	}
	return mystack->data[mystack->m_Size - 1];
}

//返回栈大小
int size_SeqStack(SeqStack stack)
{
	if (stack == NULL)
	{
		return -1;
	}

	struct SStack* mystack = stack;

	return mystack->m_Size;
}

//判断栈是否为空
int isEmpty_SeqStack(SeqStack stack)
{
	if (stack == NULL)
	{
		return -1;//返回-1代表真  空栈
	}

	struct SStack* mystack = stack;

	if (mystack->m_Size == 0)
	{
		return -1;
	}

	return 0; //返回0 代表 不是空栈
}

//销毁栈
void destroy_SeqStack(SeqStack stack)
{
	if (stack == NULL)
	{
		return;
	}

	free(stack);
	stack = NULL;

}