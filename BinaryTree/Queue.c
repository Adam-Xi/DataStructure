#include"Queue.h"

void QueueInit(Queue* pq, BTNode * x)
{
	QueueNode * cur = (QueueNode *)malloc(sizeof(QueueNode));
	cur->_data = x;
	cur->_next = NULL;
	pq->_front = pq->_rear = cur;
}

void QueueDestory(Queue* pq)
{
	QueueNode * cur;
	while (pq->_front != pq->_rear)
	{
		cur = pq->_front;
		pq->_front = pq->_front->_next;
		free(cur);
	} 
}

QueueNode* BuyQueueNode(BTNode * x)
{
	QueueNode * cur = (QueueNode *)malloc(sizeof(QueueNode));
	if (cur == NULL)
	{
		return NULL;
	}
	cur->_data = x;
	cur->_next = NULL;
	return cur;
}
//β��--���
void QueuePush(Queue* pq, BTNode * x)
{
	QueueNode * cur = BuyQueueNode(x);
	pq->_rear->_next = cur;
	pq->_rear = cur;

}
//ͷɾ--����
void QueuePop(Queue* pq)
{
	if (!QueueIsEmpty(pq))
	{
		QueueNode * cur = pq->_front;
		pq->_front = pq->_front->_next;
		free(cur);
	}
}

int QueueIsEmpty(Queue* pq)
{
	if (pq->_front == pq->_rear)
	{
		return 1;
	}
	return 0;
}