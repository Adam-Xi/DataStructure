#include"SeqList.h"

int main()
{
	SeqList test;

	//˳���Ĵ���
	SeqListInit(&test, 15);
	//β��
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
	//βɾ
	SeqListPopBack(&test);
	SeqListPopBack(&test);
	SeqListPrint(&test);
	printf("\n");
	//ͷɾ
	SeqListPopFront(&test);
	SeqListPopFront(&test);
	SeqListPopFront(&test);
	SeqListPrint(&test);
	printf("\n");
	//ͷ��
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
	//˳���Ĳ���
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

	//Ϊ��֤�����ɾ��������׼ȷ��
	SeqListPushFront(&test, 1);
	SeqListPushFront(&test, 1);
	SeqListPushFront(&test, 1);
	SeqListPushFront(&test, 1);
	SeqListPrint(&test);
	printf("\n");
	//ɾ����һ��ֵΪ1��Ԫ��
	SeqListRemoveFirst(&test, 1);
	SeqListPrint(&test);
	printf("\n");
	//ɾ������ֵΪ1��Ԫ��
	SeqListRemoveAll(&test, 1);
	SeqListPrint(&test);
	printf("\n");

	//����posλ��ֵ�޸�Ϊx
	SeqListModify(&test, 1, 100);
	SeqListPrint(&test);
	printf("\n");
	//ð������
	SeqListBubbleSort(&test);
	SeqListPrint(&test);
	printf("\n");
	//���ֲ���
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