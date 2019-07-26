#include"Stack.h"

int main()
{
	Stack ps;

	StackInit(&ps, 100);

	StackPush(&ps, 5);
	StackPush(&ps, 4);
	StackPush(&ps, 3);
	StackPush(&ps, 2);
	StackPush(&ps, 1);

	printf("%d\n", StackPop(&ps));
	printf("%d\n", StackPop(&ps));
	printf("%d\n", StackPop(&ps));
	printf("%d\n", StackPop(&ps));
	printf("%d\n", StackPop(&ps));
//	printf("%d\n", StackPop(&ps));



	StackDestory(&ps);
	system("pause");
	return 0;
}