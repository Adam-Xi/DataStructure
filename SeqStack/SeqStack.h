#ifndef _SEQSTACK_H_
#define _SEQSTACK_H_

#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<string.h>

#define STACKSIZE 200

//顺序栈结构体定义
typedef int STDataType;
typedef struct StackNode
{
	STDataType array[20];
	size_t _top;
	size_t _capacity;
}Stack;

//顺序栈基本接口实现
void StackInit(Stack * sk);
void StackDestory(Stack *sk);
void StackPush(Stack *sk, STDataType x);
void StackPop(Stack *sk);
STDataType StackTop(Stack *sk);
int StackIsEmpty(Stack *sk);
int StackSize(Stack *sk);

#endif /*_SEQSTACK_H_*/