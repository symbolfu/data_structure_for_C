#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef void* LinkStack;

//初始化
LinkStack init_LinkStack();

//入栈
void push_LinkStack(LinkStack stack, void* data);

//出栈
void pop_LinkStack(LinkStack stack);

//返回栈顶元素
void* top_LinkStack(LinkStack stack);

//返回栈个数
int size_LinkStack(LinkStack stack);

//判断是否为空
int isEmpty_LinkStack(LinkStack stack);

//销毁
void destroy_LinkStack(LinkStack stack);


