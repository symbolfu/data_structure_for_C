#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


//节点结构体
struct LinkNode
{
	//数据域
	void* data;
	//指针域
	struct LinkNode* next;
};

//链表结构体
struct LList
{
	//头节点
	struct LinkNode pHeader;
	//链表长度
	int m_size;
};

typedef void* LinkList;

//初始化链表
LinkList init_LinkList();

//插入链表
void insert_LinkList(LinkList list, int pos, void* data);

//遍历链表
void foreach_LinkList(LinkList list, void(*myForeach)(void*));

//删除链表  按位置
void removeByPos_LinkList(LinkList list, int pos);

//按照值删除链表
void removeByValue_LinkList(LinkList list, void* data, int(*myCompare)(void*, void*));

//清空链表
void clear_LinkList(LinkList list);

//返回链表长度
int  size_LinkList(LinkList list);

//销毁链表
void destroy_Linklist(LinkList list);




