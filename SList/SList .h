#ifndef _SLIST_H_
#define _SLIST_H_

#include<stdio.h>
#include<windows.h>


typedef int SLTDataType;

typedef struct SListNode {
	SLTDataType data;
	struct SListNode* next;
}SListNode;

void SListInit(SListNode** pphead);
void SListDestory(SListNode** pphead);

SListNode* BuySListNode(SLTDataType x);
void SListPushFront(SListNode** pphead, SLTDataType x);
void SListPopFront(SListNode** pphead);
void SListInsertAfter(SListNode* pos, SLTDataType x);
void SListEraseAfter(SListNode* pos);
SListNode* SListFind(SListNode* phead, SLTDataType x);
void SListRemove(SListNode** pphead, SLTDataType x);

void SListPrint(SListNode* phead);

void SListReverse(SListNode **pphead);
void SListReverse2(SListNode **pphead);
#endif /*_SLIST_H_*/ //_SLIST_H_#ifndef _SLIST_H_
#define _SLIST_H_

#include<stdio.h>
#include<windows.h>


typedef int SLTDataType;

typedef struct SListNode {
	SLTDataType data;
	struct SListNode* next;
}SListNode;

void SListInit(SListNode** pphead);
void SListDestory(SListNode** pphead);

SListNode* BuySListNode(SLTDataType x);
void SListPushFront(SListNode** pphead, SLTDataType x);
void SListPopFront(SListNode** pphead);
void SListInsertAfter(SListNode* pos, SLTDataType x);
void SListEraseAfter(SListNode* pos);
SListNode* SListFind(SListNode* phead, SLTDataType x);
void SListRemove(SListNode** pphead, SLTDataType x);

void SListPrint(SListNode* phead);

void SListReverse(SListNode **pphead);
void SListReverse2(SListNode **pphead);
#endif /*_SLIST_H_*/ //_SLIST_H_#ifndef _SLIST_H_
#define _SLIST_H_

#include<stdio.h>
#include<windows.h>


typedef int SLTDataType;

typedef struct SListNode {
	SLTDataType data;
	struct SListNode* next;
}SListNode;

void SListInit(SListNode** pphead);
void SListDestory(SListNode** pphead);

SListNode* BuySListNode(SLTDataType x);
void SListPushFront(SListNode** pphead, SLTDataType x);
void SListPopFront(SListNode** pphead);
void SListInsertAfter(SListNode* pos, SLTDataType x);
void SListEraseAfter(SListNode* pos);
SListNode* SListFind(SListNode* phead, SLTDataType x);
void SListRemove(SListNode** pphead, SLTDataType x);

void SListPrint(SListNode* phead);

void SListReverse(SListNode **pphead);
void SListReverse2(SListNode **pphead);
#endif /*_SLIST_H_*/ //_SLIST_H_