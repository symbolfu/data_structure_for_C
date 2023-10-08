#include "linkList.h"

//初始化链表
LinkList init_LinkList()
{
	struct LList* myList = malloc(sizeof(struct LList));

	if (myList == NULL)
	{
		return NULL;
	}

	myList->pHeader.next = NULL;
	myList->m_Size = 0;

	return myList;
}

//插入
void insert_LinkList(LinkList list, int pos, void* data)
{
	if (list == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}

	struct LList* myList = list;
	if (pos < 0 || pos >myList->m_Size - 1)
	{
		//无效位置进行尾插
		pos = myList->m_Size;
	}

	//用户数据前4个字节 由我们来使用
	struct LinkNode* myNode = data;

	//找插入节点的前驱节点
	struct LinkNode* pCurrent = &myList->pHeader;

	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}
	//pCurrent是前驱节点位置


	//更改指针指向
	myNode->next = pCurrent->next;
	pCurrent->next = myNode;

	//更新链表长度
	myList->m_Size++;
}

//遍历链表
void foreach_LinkList(LinkList list, void(*myForeach)(void*))
{
	if (list == NULL)
	{
		return;
	}

	struct LList* myList = list;

	struct LinkNode* myNode = myList->pHeader.next;

	for (int i = 0; i < myList->m_Size; i++)
	{
		myForeach(myNode);
		myNode = myNode->next;
	}
}

//删除节点 按位置删除
void removeByPos_ListList(LinkList list, int pos)
{
	if (list == NULL)
	{
		return;
	}

	struct LList* mylist = list;

	if (pos < 0 || pos > mylist->m_Size - 1)
	{
		return;
	}

	//找待删除节点的前驱位置
	struct LinkNode* pCurrent = &mylist->pHeader;
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}

	//记录待删除节点
	struct LinkNode* pDel = pCurrent->next;


	//更改指针指向
	pCurrent->next = pDel->next;

	//free(pDel); //数据是用户管理开辟的，用户管理释放

	//更新长度
	mylist->m_Size--;
}

//销毁数组
void destroy_LinkList(LinkList list)
{
	if (list == NULL)
	{
		return;
	}

	free(list);
	list = NULL;
}