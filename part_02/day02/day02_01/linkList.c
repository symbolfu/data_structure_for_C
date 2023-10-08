#include "linkList.h"


//初始化链表
LinkList init_LinkList()
{
	
	struct LList* myList = malloc(sizeof(struct LList));

	if (myList == NULL)
	{
		return NULL;
	}

	myList->pHeader.data = NULL;
	myList->pHeader.next = NULL;
	myList->m_size = 0;

	return myList;
}


//插入链表
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
	//将list还原成 struct LList数据类型
	struct LList* myList = (struct LList*)list;
	if (pos < 0 || pos >myList->m_size)
	{
		//无效位置 强制做尾插
		pos = myList->m_size;
	}

	//找到插入节点的前驱节点位置
	struct LinkNode* pCurrent = &myList->pHeader;

	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}

	//pCurrent 要插入节点的前驱


	//创建新节点
	struct LinkNode* newNode = malloc(sizeof(struct LinkNode));
	newNode->data = data;
	newNode->next = NULL;

	//建立节点关系
	newNode->next = pCurrent->next;
	pCurrent->next = newNode;

	//更新链表长度
	myList->m_size++;
}

//遍历链表
void foreach_LinkList(LinkList list, void(*myForeach)(void*))
{
	if (list == NULL)
	{
		return;
	}

	struct LList* mylist = (struct LList*)list;

	struct LinkNode* pCurrent = mylist->pHeader.next;

	for (int i = 0; i < mylist->m_size; i++)
	{
		myForeach(pCurrent->data);
		pCurrent = pCurrent->next;
	}
}

//删除链表  按位置
void removeByPos_LinkList(LinkList list, int pos)
{
	if (list == NULL)
	{
		return;
	}

	struct LList* mylist = (struct LList*)list;

	if (pos < 0 || pos > mylist->m_size - 1)
	{
		return;
	}

	//找到待删除节点的前驱节点
	struct LinkNode* pCurrent = &mylist->pHeader;
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}

	//记录待删除的节点
	struct LinkNode* pDel = pCurrent->next;

	//重新建立节点关系
	pCurrent->next = pDel->next;

	free(pDel);
	pDel = NULL;

	//更新链表长度
	mylist->m_size--;
}

//按照值删除链表
void removeByValue_LinkList(LinkList list, void* data, int(*myCompare)(void*, void*))
{
	if (list == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}

	struct LList* mylist = (struct LList*)list;

	//创建两个辅助指针
	struct LinkNode* pPrev = &mylist->pHeader;
	struct LinkNode* pCurrent = pPrev->next;

	for (int i = 0; i < mylist->m_size; i++)
	{
		//pCurrent->data  data 将两个指针比较利用回调 交给用户
		if (myCompare(pCurrent->data, data))          // 接口编程：外部定义比较规则
		{
			pPrev->next = pCurrent->next;

			free(pCurrent);
			pCurrent = NULL;

			mylist->m_size--;
			break;
		}

		//辅助指针后移
		pPrev = pCurrent;
		pCurrent = pCurrent->next;
	}
}

//清空链表
void clear_LinkList(LinkList list)
{
	if (list == NULL)
	{
		return;
	}

	struct LList* mylist = (struct LList*)list;

	struct LinkNode* pCurrent = mylist->pHeader.next;

	for (int i = 0; i < mylist->m_size; i++)
	{
		struct LinkNode* pNext = pCurrent->next;

		free(pCurrent);          // 如果直接将pHeader的next为NULL，不free各个node是不是更快，但是会存在内存泄露的问题

		pCurrent = pNext;
	}

	mylist->pHeader.next = NULL;
	mylist->m_size = 0;
}

//返回链表长度
int  size_LinkList(LinkList list)
{
	if (list == NULL)
	{
		return -1;
	}

	struct LList* mylist = (struct LList*)list;

	return mylist->m_size;
}

//销毁链表
void destroy_Linklist(LinkList list)
{
	if (list == NULL)
	{
		return;
	}

	//清空链表
	clear_LinkList(list);

	free(list);

	list = NULL;

}