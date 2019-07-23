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


//有序链表的查重
void ListDistinct(List* plist)
{
	ListNode *cur;
	for (cur = plist->_head->_next; cur != plist->_head->_prev; cur = cur->_next)
	{
		if (cur->_data == cur->_next->_data)
		{
			ListErase(cur->_next);
		}
		else
		{
			cur = cur->_next;
		}
	}
}


//将两个有序链表合并成一个新的有序列表
ListNode* ListMerge(List *plist1, List *plist2)
{
	ListNode *cur1 = plist1->_head->_next;
	ListNode *cur2 = plist2->_head->_next;
	ListNode *tmp1;
	ListNode *tmp2;

	while (cur1!=plist1->_head && cur2!=plist2->_head)  //双链表遍历的跳出条件
	{
		if (cur1->_data > cur2->_data)  //链表一当前节点数据比链表二当前数据大，说明链表二的当前节点应插入链表一的当前节点的前面
		{
			tmp1 = cur1->_prev;
			tmp2 = cur2->_next;

			cur1->_prev = cur2;
			cur2->_next = cur1;
			tmp1->_next = cur2;
			cur2->_prev = tmp1;

			cur2 = tmp2;

			//ListInsertFront(cur1, cur2->_prev->_data);
		}
		else 
		{
			cur1 = cur1->_next;
		}
	}
	if (cur1 == plist1->_head)
	{
		tmp2 = plist2->_head->_prev;

		cur2->_prev = cur1->_prev;
		cur1->_prev->_next = cur2;

		tmp2->_next = cur1;
		cur1->_prev = tmp2;
	}

	free(plist2->_head);
}

void ListMerge2(List* plist1, List* plist2)
{
	ListNode* p1 = plist1->_head->_next;
	ListNode* p2 = plist2->_head->_next;
	ListNode* pt2 = p2->_next;
	while (p2 != plist2->_head&&p1 != plist1->_head)
	{
		if (p1->_data > p2->_data)
		{
			p1->_prev->_next = p2;
			p2->_prev = p1->_prev;
			p2->_next = p1;
			p1->_prev = p2;
			p2 = pt2;
			pt2 = p2->_next;
		}
		else
		{
			p1 = p1->_next;
		}
	}
	if (p2 != plist2->_head)
	{
		plist1->_head->_prev->_next = p2;
		p2->_prev = plist1->_head->_prev;
		plist2->_head->_prev->_next = plist1->_head;
		plist1->_head->_prev = plist2->_head->_prev;
	}
}
