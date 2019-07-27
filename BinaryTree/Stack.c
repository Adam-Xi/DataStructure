#include"Stack.h"


// ������ɾ��Ľӿ� 
void StackInit(Stack* psl, size_t capacity)  //����
{
	psl->array = (SLDataType *)calloc(capacity,sizeof(SLDataType));
	psl->size = 0;
	psl->capacity = capacity;
}

void StackDestory(Stack* psl)  //����
{
	if (psl->array)
	{
		free(psl->array);
		psl->size = 0;
		psl->capacity = 0;
	}
}

void CheckCapacity(Stack* psl) //�����
{
	if (psl->size == psl->capacity)
	{
		psl->capacity *= 2;
		psl->array = (SLDataType *)realloc(psl->array, psl->capacity * sizeof(SLDataType));
	}
}

void StackPush(Stack* psl, SLDataType x) //β��
{
	CheckCapacity(psl);

	psl->array[psl->size] = x;
	psl->size++;
}

void StackPop(Stack* psl) //βɾ
{
	if (psl == NULL)
	{
		return;
	}
	psl->size--;
}


int StackIsEmpty(Stack* psl)
{
	if (psl->size == 0)
		return 1;
	return 0;
}

SLDataType StackFront(Stack* psl)
{
	if (!StackIsEmpty(psl))
	{
		return psl->array[psl->size - 1];
	}
	return NULL;
}