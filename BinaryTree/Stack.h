#ifndef _SEQLIST_H_
#define _SEQLIST_H_


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>

#include"BTree.h"

typedef BTNode * SLDataType;

typedef struct Stack {
	SLDataType* array;  // ָ��̬���ٵ�����
	size_t size;       // ��Ч���ݸ���
	size_t capacity;   // �����ռ�Ĵ�С
}Stack;

void StackInit(Stack* psl, size_t capacity);
void StackDestory(Stack* psl);

void CheckCapacity(Stack* psl);
void StackPush(Stack* psl, SLDataType x);
void StackPop(Stack* psl);

int StackIsEmpty(Stack* psl);
SLDataType StackFront(Stack* psl);



#endif /*_SEQLIST_H_*/

