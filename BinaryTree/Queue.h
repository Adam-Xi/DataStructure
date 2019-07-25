#ifndef _QUEUE_H_
#define _QUEUE_H_

#include<stdio.h>
#include<windows.h>

#include"BTree.h"

typedef struct QueueNode 
{
	struct QueueNode * _next;    
	BTNode * _data;
}QueueNode;

typedef struct Queue {
	QueueNode* _front; // ��ͷ    
	QueueNode* _rear;  // ��β
}Queue;

void QueueInit(Queue* pq, BTNode * x);
void QueueDestory(Queue* pq);

QueueNode* BuyQueueNode(BTNode * x);
void QueuePush(Queue* pq, BTNode * x);
void QueuePop(Queue* pq); 
int QueueIsEmpty(Queue* pq); 


void TestQueue();

#endif /*_QUEUE_H_*/