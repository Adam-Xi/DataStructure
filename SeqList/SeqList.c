#include"SeqList.h"


// ������ɾ��Ľӿ� 
void SeqListInit(SeqList* psl, size_t capacity)  //����
{
	psl->array = (SLDataType *)calloc(capacity,sizeof(SLDataType));
	psl->size = 0;
	psl->capacity = capacity;
}

void SeqListDestory(SeqList* psl)  //����
{
	if (psl->array)
	{
		free(psl->array);
		psl->size = 0;
		psl->capacity = NULL;
	}
}

void CheckCapacity(SeqList* psl) //�����
{
	if (psl->size == psl->capacity)
	{
		psl->capacity *= 2;
		psl->array = (SLDataType *)realloc(psl->array, psl->capacity * sizeof(SLDataType));
	}
}

void SeqListPushBack(SeqList* psl, SLDataType x) //β��
{
	CheckCapacity(psl);

	psl->array[psl->size] = x;
	psl->size++;
}

void SeqListPopBack(SeqList* psl) //βɾ
{
	psl->size--;
}

void SeqListPushFront(SeqList* psl, SLDataType x) //ͷ��
{
	CheckCapacity(psl);

	int i;
	for (i = psl->size - 1; i >= 0; i--)
	{
		psl->array[i + 1] = psl->array[i];
	}
	psl->array[0] = x;
	psl->size++;
}

void SeqListPopFront(SeqList* psl) //ͷɾ
{
	int i;
	for (i = 0; i < psl->size - 1; i++)
	{
		psl->array[i] = psl->array[i + 1];
	}
	psl->size--;
}

int SeqListFind(SeqList* psl, SLDataType x) //��
{
	int i;
	for (i = 0; i < psl->size; i++)
	{
		if (psl->array[i] == x)
		{
			return i;
		}
	}
	return -1;
}

void SeqListInsert(SeqList* psl, size_t pos, SLDataType x) //posλ���x
{
	if (pos < 0 || pos >= psl->size)
	{
		return -1;
	}

	CheckCapacity(psl);

	int i;
	for (i = psl->size - 1; i >= pos; i--)
	{
		psl->array[i + 1] = psl->array[i];
	}
	psl->array[pos] = x;
	psl->size++;
}

void SeqListErase(SeqList* psl, size_t pos) //ɾ��posλ��ֵ
{
	if (pos < 0 || pos >= psl->size)
	{
		return -1;
	}

	int i;
	for (i = pos; i < psl->size - 1; i++)
	{
		psl->array[i] = psl->array[i + 1];
	}
	psl->size--;
}

void SeqListRemoveFirst(SeqList* psl, SLDataType x)//ɾ��ָ��ֵ(��һ��)��x
{
	if (SeqListFind(psl, x) != x)
	{
		SeqListErase(psl, SeqListFind(psl, x));
	}
}

#if 0
//ɾ�����е�ָ��ֵx
void SeqListRemoveAll(SeqList* psl, SLDataType x)//����1���ռ�O(1),O(n)
{
	int gap = 0;

	int i;
	for (i = 0; i < psl->size - gap; i++)
	{
		if (psl->array[i + gap] == x)
		{
			gap++;
			if (i + gap >= psl->capacity)  //���⼫������µ��������һλԽ��
			{
				break;
			}
		}
		psl->array[i] = psl->array[i + gap];
	}
	psl->size -= gap;
}
#else
void SeqListRemoveAll(SeqList* psl, SLDataType x)//����2���ռ�O(n)��ʱ��O(n)
{
	SLDataType *tmp = (SLDataType *)calloc(psl->capacity, sizeof(SLDataType));
	int i, j;

	for (i = 0, j = 0; i < psl->size; i++){
		if (psl->array[i] != x){
			tmp[j] = psl->array[i];
			j++;
		}
	}
	free(psl->array);
	psl->array = tmp;
	psl->size = j;
}
#endif

void SeqListModify(SeqList* psl, size_t pos, SLDataType x) //�޸� 
{
	if (pos >= 0 && pos < psl->size)
	{
		psl->array[pos] = x;
	}
}

void SeqListPrint(SeqList* psl)
{
	int i;
	for (i = 0; i < psl->size; i++)
	{
		printf("%d ", psl->array[i]);
	}
	printf("\n");
}

void SeqListBubbleSort(SeqList* psl)
{
	int i, j;
	SLDataType tmp;
	for (i = 0; i < psl->size; i++)
	{
		for (j = 0; j < psl->size - i; j++)
		{
			if (psl->array[j] > psl->array[j + 1])
			{
				tmp = psl->array[j];
				psl->array[j] = psl->array[j + 1];
				psl->array[j + 1] = tmp;
			}
		}
	}
}

int SeqListBinaryFind(SeqList* psl, SLDataType x)
{
	SLDataType start = psl->array[0];
	SLDataType end = psl->array[psl->size - 1];
	SLDataType mid;

	while (start <= end)
	{
		mid = (start + end) / 2;
		if (x < mid)
		{
			end = mid - 1;
		}
		else if (x > mid)
		{
			start = start + 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}