#include"List.h"


int main()
{
	List list;
	ListInit(&list);

	ListPushFront(&list, 2);
	ListPushFront(&list, 1);
	ListPushFront(&list, 0);
	ListPushBack(&list, 3);
	ListPushBack(&list, 4);
	ListPushBack(&list, 5);
	ListPrint(&list);

	ListPopFront(&list);
	ListPrint(&list);

	ListPopBack(&list);
	ListPrint(&list);

	ListRemove(&list, 3);
	ListPrint(&list);


	ListDestory(&list);

	system("pause");
	return 0;
}