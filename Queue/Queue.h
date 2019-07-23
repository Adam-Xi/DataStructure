#ifndef _SQ_H_
#define _SQ_H_

#include<stdio.h>
#include<Windows.h>

#define MAXSIZE 100

typedef int QuDataType;

typedef struct Queue
{
	QuDataType data[MAXSIZE];
	QuDataType * front;
	QuDataType * rear;
	size_t size;
}Queue;

void QueueInit(Queue* pq);
void QueueDestory(Queue* pq);

void QueuePush(Queue* pq, QuDataType x);
void QueuePop(Queue* pq);

QuDataType QueueFront(Queue* pq);
QuDataType QueueBack(Queue* pq);
int QueueEmpty(Queue* pq);
int QueueSize(Queue* pq);




#endif /*_SQ_H_*/