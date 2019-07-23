#include"Queue.h"

void QueueInit(Queue* pq)
{
	pq->front = pq->data;
	pq->rear = pq->data;
	pq->size = 0;
}

void QueueDestory(Queue* pq)
{
	pq->front = pq->data;
	pq->rear = pq->data;
	pq->size = 0;
}

void QueuePush(Queue* pq, QuDataType x)
{
	//����
	if (pq->size + 1 == MAXSIZE)
	{
		return;
	}
	/*����pq->size,��������Ҳ����Ϊ��
	if (pq->rear + 1 - MAXSIZE == pq->data && pq->data == pq->front
		|| pq->rear + 1 == pq->front)
	{
		return ;
	}
	*/

	*(pq->rear) = x;
	pq->rear++;

	pq->size++;

	if (pq->rear - pq->data == MAXSIZE)
	{
		pq->rear = pq->data;
	}
	

}

void QueuePop(Queue* pq)
{
	//�п�
	if (pq->size == 0)
	{
		return;
	}
	pq->front++;

	pq->size--;

	if (pq->front - pq->data == MAXSIZE)
	{
		pq->front = pq->data;
	}

}

QuDataType QueueFront(Queue* pq)
{
	if (pq->size == 0)
	{
		return -1;
	}
	return *(pq->front);
}


QuDataType QueueBack(Queue* pq)
{
	if (pq->size == 0)
	{
		return -1;
	}
	if (pq->rear == pq->data)
	{
		return pq->data[MAXSIZE - 1];
	}
	return *(pq->rear - 1);
}
