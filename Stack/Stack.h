#ifndef _STACK_H_
#define _STACK_H_

#include<stdio.h>
#include<Windows.h>

typedef int STDataType;

typedef struct Stack
{
	STDataType a[20];
	int top; //Õ»¶¥
	int capacity; //ÈÝÁ¿
}Stack;

void StackInit(Stack* ps, int size);
void StackDestory(Stack* ps);

void StackPush(Stack* ps, STDataType x);
STDataType StackPop(Stack* ps);
STDataType StackTop(Stack* ps);
int StackEmpty(Stack* ps); 
int StackSize(Stack* ps);


#endif /*_STACK_H_*/