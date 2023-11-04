#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


struct BinaryNode
{
	//数据域
	char ch;
	//指针域
	struct BinaryNode* lChild;
	struct BinaryNode* rChild;
};


void calculateLeafNum(struct BinaryNode* root, int* p)
{
	if (root == NULL)
	{
		return;
	}

	if (root->lChild == NULL && root->rChild == NULL)
	{
		(*p)++;
	}

	calculateLeafNum(root->lChild, p);

	calculateLeafNum(root->rChild, p);
}

int getTreeHeight(struct BinaryNode* root)
{
	if (root == NULL)
	{
		return 0;
	}

	//获取左子树高度 
	int  lHeight = getTreeHeight(root->lChild);
	//获取右子树高度
	int  rHeight = getTreeHeight(root->rChild);

	int height = lHeight > rHeight ? lHeight + 1 : rHeight + 1;

	return height;
}


struct BinaryNode* copyTree(struct BinaryNode* root)
{
	if (root == NULL)
	{
		return NULL;
	}

	//先拷贝左子树
	struct BinaryNode* lChild = copyTree(root->lChild);
	//再拷贝右子树
	struct BinaryNode* rChild = copyTree(root->rChild);

	struct BinaryNode* newNode = malloc(sizeof(struct BinaryNode));

	newNode->ch = root->ch;
	newNode->lChild = lChild;

	newNode->rChild = rChild;

	return newNode;
}

void recursion(struct BinaryNode* root)
{
	if (root == NULL)
	{
		return;
	}

	printf("%c ", root->ch);

	recursion(root->lChild);

	recursion(root->rChild);

}

void freeTree(struct BinaryNode* root)
{
	if (root == NULL)
	{
		return;
	}

	//先释放左子树
	freeTree(root->lChild);
	//再释放右子树
	freeTree(root->rChild);
	//释放根
	printf("%c被释放了\n", root->ch);
	free(root);
}


// 二叉树编程

void test01()
{
	struct BinaryNode nodeA = { 'A', NULL, NULL };
	struct BinaryNode nodeB = { 'B', NULL, NULL };
	struct BinaryNode nodeC = { 'C', NULL, NULL };
	struct BinaryNode nodeD = { 'D', NULL, NULL };
	struct BinaryNode nodeE = { 'E', NULL, NULL };
	struct BinaryNode nodeF = { 'F', NULL, NULL };
	struct BinaryNode nodeG = { 'G', NULL, NULL };
	struct BinaryNode nodeH = { 'H', NULL, NULL };

	//建立关系
	nodeA.lChild = &nodeB;
	nodeA.rChild = &nodeF;

	nodeB.rChild = &nodeC;

	nodeC.lChild = &nodeD;
	nodeC.rChild = &nodeE;

	nodeF.rChild = &nodeG;

	nodeG.lChild = &nodeH;

	//1、求二叉树 叶子数量
	int num = 0;
	calculateLeafNum(&nodeA, &num);

	printf("树的叶子数量为：%d\n", num);

	//2、 求树的高度/深度
	int height = getTreeHeight(&nodeA);

	printf("树的高度为：%d\n", height);

	//3、 拷贝二叉树
	struct BinaryNode* newTree = copyTree(&nodeA);

	//递归遍历
	recursion(newTree);

	printf("\n");
	//4、 释放二叉树
	freeTree(newTree);
	newTree = NULL;
}



int main()
{

	test01();

	return 0;
}