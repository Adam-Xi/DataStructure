#include"List.h"

void ListInit(List* plist)
{
	plist->_head = (ListNode *)malloc(sizeof(ListNode));
	plist->_head->_prev = plist->_head;
	plist->_head->_next = plist->_head;
}

void ListDestory(List* plist)
{
	while (plist->_head != plist->_head->_next)
	{
		ListPopFront(plist);
	}
	free(plist->_head);
	plist->_head = NULL;
}

void ListPushBack(List* plist, LTDataType x)
{
	ListInsertFront(plist->_head, x);
}

void ListPopBack(List* plist)
{
	ListErase(plist->_head->_prev);
}

void ListPushFront(List* plist, LTDataType x)
{
	ListInsertAfter(plist->_head, x);
}

void ListPopFront(List* plist)
{
	ListErase(plist->_head->_next);
}

ListNode* ListFind(List* plist, LTDataType x) 
{
	ListNode * cur;
	for (cur = plist->_head->_next; cur != plist->_head; cur = cur->_next)
	{
		if (cur->_data == x)
		{
			return cur;
		}
	}
	return NULL;
}

void ListInsertFront(ListNode* pos, LTDataType x)  //头插
{
	ListNode *cur = (ListNode *)malloc(sizeof(ListNode));
	ListNode *tmp = pos->_prev;
	cur->_data = x;

	pos->_prev = cur;
	cur->_next = pos;
	tmp->_next = cur;
	cur->_prev = tmp;
}

void ListInsertAfter(ListNode* pos, LTDataType x) //尾插
{
	ListNode *cur = (ListNode *)malloc(sizeof(ListNode));
	ListNode *tmp = pos->_next;
	cur->_data = x;

	pos->_next = cur;
	cur->_prev = pos;
	tmp->_prev = cur;
	cur->_next = tmp;
}

void ListErase(ListNode* pos) //删除第pos个节点
{
	pos->_next->_prev = pos->_prev;
	pos->_prev->_next = pos->_next;
	free(pos);
}

void ListRemove(List* plist, LTDataType x)
{
	ListNode *cur = ListFind(plist, x);
	if (cur)
	{
		ListErase(cur);
	}
}

void ListPrint(List* plist)
{
	ListNode *cur;
	printf("head->");
	for (cur = plist->_head->_next; cur != plist->_head; cur = cur->_next)
	{
		printf("%d->", cur->_data);
	}
	printf("head\n");
}
