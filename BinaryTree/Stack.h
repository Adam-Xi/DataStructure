#ifndef _SEQLIST_H_
#define _SEQLIST_H_


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>

#include"BTree.h"

typedef BTNode * SLDataType;

typedef struct Stack {
	SLDataType* array;  // 指向动态开辟的数组
	size_t size;       // 有效数据个数
	size_t capacity;   // 容量空间的大小
}Stack;

void StackInit(Stack* psl, size_t capacity);
void StackDestory(Stack* psl);

void CheckCapacity(Stack* psl);
void StackPush(Stack* psl, SLDataType x);
void StackPop(Stack* psl);

int StackIsEmpty(Stack* psl);
SLDataType StackFront(Stack* psl);



#endif /*_SEQLIST_H_*/

