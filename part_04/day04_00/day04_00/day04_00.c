#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*
	树与二叉树
		基本概念：
			根：即根节点；，没有前驱
			叶子：终端节点，没有后继
			双亲：上层的那个节点，前驱
			孩子：下层的节点，后继；

			节点：树的数据元素
			节点的度： 节点挂接的子树数，即有几个直接后继就是几度
			终端节点：即叶子；
			树的度：所有节点度中的最大值
			树的深度：所有节点的最大的层数；

		特点：
			非线性结构： 一对多结构
			树的定义具有递归性，即树中有树；


		多叉树转变为二叉树：
			左孩子右兄弟；

		=======================================================================================
		数据结构引出：
			LPointer data RPointer
			节点有两个指针域，其中一个指针指向子节点，另一个指针指向其兄弟节点


		重点研究二叉树：
			结构：1对2；
			特点：
				每个结点最多只有两棵子树，即不存在度大于2的节点；
				左子树和右子树次序不能颠倒，即有序树；

			基本性质：
				在二叉树的第i层上至多有2^i-1个结点
				深度为k的二叉树至多有2^k-1个结点
				任何一棵二叉树，若度为2的结点数有n2个，则叶子数（n0）必定为n2＋1;

			满二叉树：
				每层都“充满”了结点

			完全二叉树：
				除最后一层外，每一层上的节点数均达到最大值；
				在最后一层上只缺少右边的若干结点；
				性质：
					具有n个结点的完全二叉树的深度必为log2n+1；
					对完全二叉树，若从上至下、从左至右编号，则编号为i 的结点，其左孩子编号必为2i，
					其右孩子编号必为2i＋1；其双亲的编号必为i/2（i＝1 时为根,除外）

				引出：使用上述性质可以使用完全二叉树实现树的顺序存储；
					利用上述性质，每个元素的index是确认的，即变相实现了一一对应关系；
					缺点：
						浪费空间；
						插入和删除不方便；


			二叉树的表示：
				二叉链表示法：
					一般从根结点开始存储。相应地，访问树中结点时也只能从根开始；
					存储结构
						LPointer data RPointer

				三叉链表示法：
					每个节点有三个指针域，其中两个分别指向子节点（左孩子，右孩子），还有一共指针指向该节点的父节点；
					存储结构：
						lchild data rchild parent


			二叉树的遍历：
				指按某条搜索路线遍访每个结点且不重复；
				遍历的用途：
					它是树结构插入、删除、修改、查找和排序运算的前提，
					是二叉树一切运算的基础和核心；

				遍历方法：
					牢记一种约定，对每个结点的查看都是“先左后右”；
					限定先左后右，树的遍历有三种实现方案：
						DLR: 先序遍历，即先根再左再右
						LDR: 中序遍历，即先左再根再右
						LRD: 后序遍历，即先左再右再根

						先中后可以理解为根目录的访问时机；

					从递归的角度看，这三种算法是完全相同的，或者说这三种遍历算法的访问路径是相同的，只是访问结点的时机不同;

*/


struct BinaryNode
{
	// data field
	char ch;
	// pointer field
	struct BinaryNode* lChild;
	struct BinaryNode* rChild;
};


void recursion(struct BinaryNode* root)
{
	if (root == NULL)
	{
		return;
	}

	// DLR
	printf("%c ", root->ch);
	recursion(root->lChild);
	recursion(root->rChild);
}


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

	// 建立关系
	nodeA.lChild = &nodeB;
	nodeA.rChild = &nodeF;

	nodeB.lChild = &nodeC;

	nodeC.lChild = &nodeD;
	nodeC.rChild = &nodeE;

	nodeF.lChild = &nodeG;

	nodeG.lChild = &nodeH;

	// recursion
	recursion(&nodeA);



}


int main()
{

	test01();


	return 0;
}