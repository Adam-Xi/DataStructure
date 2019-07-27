#include"BTree.h"
#include"Queue.h"


int main()
{
	BTNode * testTree = BinaryTreeCreate("ABD##E#H##CF##G##");

	/*
	BinaryTreePrevOrder(testTree);
	putchar('\n');
	BinaryTreeInOrder(testTree);
	putchar('\n');
	BinaryTreePostOrder(testTree);
	putchar('\n');

	BinaryTreeLevelOrder(testTree);
	putchar('\n');

	printf("%d\n", BinaryTreeSize(testTree));
	printf("%d\n", BinaryTreeLeafSize(testTree));
	*/
//	BinaryTreePrevOrderNonR(testTree);
	putchar('\n');
	BinaryTreeInOrderNonR(testTree);
	putchar('\n');
	BinaryTreePostOrderNonR(testTree);


	system("pause");
	return 0;
}