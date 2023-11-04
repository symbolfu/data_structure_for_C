#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "seqStack.h"


struct BinaryNode
{
	//数据域
	char ch;
	//指针域
	struct BinaryNode* lChild;
	struct BinaryNode* rChild;
	//标志
	int flag;
};

// DRL
void nonRecursion(struct BinaryNode* root)
{
	//初始化栈
	SeqStack myStack = init_SeqStack();

	push_SeqStack(myStack, root);

	while (size_SeqStack(myStack) > 0)
	{
		//获取栈顶元素
		struct BinaryNode* pTop = top_SeqStack(myStack);
		//出栈
		pop_SeqStack(myStack);

		//如果标志位真  直接输出  并且执行下一次循环
		if (pTop->flag == 1)
		{
			printf("%c ", pTop->ch);
			continue;
		}

		//如果为假 将标志改为真
		pTop->flag = 1;

		//将右子树  左子树 根 入栈
		if (pTop->rChild != NULL)
		{
			push_SeqStack(myStack, pTop->rChild);
		}
		if (pTop->lChild != NULL)
		{
			push_SeqStack(myStack, pTop->lChild);
		}
		push_SeqStack(myStack, pTop);
	}

	//销毁栈
	destroy_SeqStack(myStack);
}



void test01()
{
	// 二叉树的非递归遍历
	struct BinaryNode nodeA = { 'A', NULL, NULL,0 };
	struct BinaryNode nodeB = { 'B', NULL, NULL,0 };
	struct BinaryNode nodeC = { 'C', NULL, NULL,0 };
	struct BinaryNode nodeD = { 'D', NULL, NULL,0 };
	struct BinaryNode nodeE = { 'E', NULL, NULL,0 };
	struct BinaryNode nodeF = { 'F', NULL, NULL,0 };
	struct BinaryNode nodeG = { 'G', NULL, NULL,0 };
	struct BinaryNode nodeH = { 'H', NULL, NULL,0 };

	//建立关系
	nodeA.lChild = &nodeB;
	nodeA.rChild = &nodeF;

	nodeB.rChild = &nodeC;

	nodeC.lChild = &nodeD;
	nodeC.rChild = &nodeE;

	nodeF.rChild = &nodeG;

	nodeG.lChild = &nodeH;

	//非递归遍历
	nonRecursion(&nodeA);
}


int main()
{
	test01();

	return 0;
}