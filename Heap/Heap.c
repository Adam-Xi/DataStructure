#include<stdio.h>
#include<string.h>

#define ARRSIZE(a) (sizeof(a) / sizeof(a[0]))
#define MAXSIZE 100 

typedef int HPDataType;
typedef struct Heap
{
	HPDataType *_a;
    int _size;    
    int _capacity; 
}Heap;

void swap(HPDataType *a1, HPDataType *a2)
{
	HPDataType *tmp;
	tmp = a1;
	a1 = a2;
	a2 = tmp;
}
void downAdjust(Heap *hp, int n) //向下调整
{
	int cur = n;
	while(cur * 2 + 1 < hp->_size)
	{
		if(hp->_a[cur] < hp->_a[cur * 2 + 1]) 
		{
			if(cur * 2 + 2  >= hp->_size || hp->_a[cur * 2 + 1] > hp->_a[cur * 2 + 2])
			{
				swap(&hp->_a[cur], &hp->_a[cur * 2 + 1]);
				cur = cur  * 2 + 1;
			}
			else
			{
				swap(&hp->_a[cur], &hp->_a[cur *2 + 2]);
				cur = cur * 2 + 2;
			}
		}
		else if(cur * 2 + 2 < hp->_size || hp->_a[cur] < hp->_a[cur * 2 + 2])
		{
			swap(&hp->_a[cur], &hp->_a[cur * 2 + 2]);
			cur = cur * 2 + 2;
		}
		else
		{
			break;
		}
	}
}
void HeapInit(Heap *hp, HPDataType *a, int n)
{
	int i;
	hp->_capacity = MAXSIZE > n ? MAXSIZE: n;
	hp->_size = n;
	hp->_a = (HPDataType *)malloc(sizeof(HPDataType) * hp->_capacity);
	memcpy(hp->_a, a, sizeof(HPDataType) * n);

	for(i = n / 2 - 1; i >= 0; i--)
	{
		downAdjust(hp, i);
	}
}
void HeapDestory(Heap *hp)
{
	if(hp->_a)
	{
		free(hp->_a);
		hp->_a = NULL;
		hp->_size = hp->_capacity = 0;
	}
}
void HeapPush(Heap *hp, HPDataType x)  
{
	if(hp->_size == hp->_capacity)
	{
		hp->_capacity *= 2;
		hp->_a = (HPDataType *)realloc(hp->_a, hp->_capacity);
	}
	hp->_a[hp->_size] = x;
	hp->_size++;

	while()
	{
		if(hp->_a[cur] > hp->_a[(cur - 1) / 2])
		{
			swap(&hp->_a[cur], &hp->_a[(cur - 1) / 2]);
			cur = (cur - 1) / 2;
		}
		else
		{
			break;
		}
	}
}
void HeapPop(Heap *hp)
{
	swap(hp->_a, hp->_a + hp->_size - 1);
	hp->_size--;
	downAdjust(hp, 0);
}
HPDataType HeapTop(Heap *hp)
{
	if(hp->_size == 0)
	{
		return (HPDataType)0;
	}
	return hp->_a[0];
}		
int HeapSize(Heap *hp)
{
	return hp->_size;
}
int HeapEmpty(Heap *hp)
{
	return hp->_size == 0;
}
void HeapPrint(Heap *hp)
{
	int i;
	int tag = 0;
	int tmp = 1;
	for(i = 0; i < hp->_size; i++)
	{
		printf("%d ", hp->_a[i]);
		if(i == tag)
		{
			putchar('\n');
			tmp *= 2;
			tag += tmp;
		}
	}
}
void HeapSort(Heap *hp)
{
	int tmp = hp->_size;
	while(hp->_size >= 1)
	{
		HeapPop(hp);
	}
	hp->_size = tmp;
}

int main()
{
	int a[] = {1, 6, 3, 7, 9, 8};
	Heap hp;
	HeapInit(&hp, a, ARRSIZE(a));
	HeapPop(&hp);
	HeapPush(&hp, 5);
	HeapPush(&hp, 10);
	HeapSort(&hp);
	HeapPrint(&hp);
	HeapDestory(&hp);
	return 0;
}



/*
堆Heap--以顺序表存储，从下标为0开始
对于顺序表中第i个元素，它的左右孩子分别为 2*(i+1)-1 和 2*(i+1)
它的父辈节点为 (i-1)/2
堆--大根堆、小根堆（根和左右节点的比较）

*/