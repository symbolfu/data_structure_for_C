#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef void* LinkStack;

//��ʼ��
LinkStack init_LinkStack();

//��ջ
void push_LinkStack(LinkStack stack, void* data);

//��ջ
void pop_LinkStack(LinkStack stack);

//����ջ��Ԫ��
void* top_LinkStack(LinkStack stack);

//����ջ����
int size_LinkStack(LinkStack stack);

//�ж��Ƿ�Ϊ��
int isEmpty_LinkStack(LinkStack stack);

//����
void destroy_LinkStack(LinkStack stack);


