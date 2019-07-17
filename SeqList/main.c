#include"SeqList.h"

int main()
{
	SeqList test;

	//顺序表的创建
	SeqListInit(&test, 15);
	//尾插
	SeqListPushBack(&test, 1);
	SeqListPushBack(&test, 2);
	SeqListPushBack(&test, 3);
	SeqListPushBack(&test, 4);
	SeqListPushBack(&test, 5);
	SeqListPushBack(&test, 6);
	SeqListPushBack(&test, 7);
	SeqListPushBack(&test, 8);
	SeqListPushBack(&test, 9);
	SeqListPushBack(&test, 10);
	SeqListPrint(&test);
	printf("\n");
	//尾删
	SeqListPopBack(&test);
	SeqListPopBack(&test);
	SeqListPrint(&test);
	printf("\n");
	//头删
	SeqListPopFront(&test);
	SeqListPopFront(&test);
	SeqListPopFront(&test);
	SeqListPrint(&test);
	printf("\n");
	//头插
	SeqListPushFront(&test, 11);
	SeqListPushFront(&test, 12);
	SeqListPushFront(&test, 13);
	SeqListPushFront(&test, 14);
	SeqListPushFront(&test, 15);
	SeqListPrint(&test);
	printf("\n");

	SeqListPopFront(&test);
	SeqListPopFront(&test);
	SeqListPrint(&test);
	printf("\n");
	//顺序表的查找
	int res1 = SeqListFind(&test, 5);
	if (res1 == -1)
	{
		printf("error\n");
	}
	else
	{
		printf("Find it! The pos is: %d\n", res1);
	}

	SeqListInsert(&test, 5, 100);
	SeqListPrint(&test);
	printf("\n");

	SeqListErase(&test, 5);
	SeqListPrint(&test);
	printf("\n");

	//为保证后面的删除函数的准确性
	SeqListPushFront(&test, 1);
	SeqListPushFront(&test, 1);
	SeqListPushFront(&test, 1);
	SeqListPushFront(&test, 1);
	SeqListPrint(&test);
	printf("\n");
	//删除第一个值为1的元素
	SeqListRemoveFirst(&test, 1);
	SeqListPrint(&test);
	printf("\n");
	//删除所有值为1的元素
	SeqListRemoveAll(&test, 1);
	SeqListPrint(&test);
	printf("\n");

	//将第pos位的值修改为x
	SeqListModify(&test, 1, 100);
	SeqListPrint(&test);
	printf("\n");
	//冒泡排序
	SeqListBubbleSort(&test);
	SeqListPrint(&test);
	printf("\n");
	//二分查找
	int res2 = SeqListBinaryFind(&test, 5);
	if (-1 == res2)
	{
		printf("error\n");
	}
	else
	{
		printf("Find it! The pos is: %d\n", res2);
	}
	printf("\n");




	SeqListDestory(&test);




	system("pause");
	return 0;
}