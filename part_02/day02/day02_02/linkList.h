#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


//节点结构体
struct LinkNode
{
	//只维护指针域
	struct LinkNode* next;
};

//链表结构体
struct LList
{
	struct LinkNode pHeader;
	int m_Size;
};

typedef void* LinkList;

//初始化链表
LinkList init_LinkList();

//插入
void insert_LinkList(LinkList list, int pos, void* data);

//遍历链表
void foreach_LinkList(LinkList list, void(*myForeach)(void*));

//删除节点 按位置删除
void removeByPos_ListList(LinkList list, int pos);

//销毁数组
void destroy_LinkList(LinkList list);




