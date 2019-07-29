#include"SeqStack.h"

void testStack() 
{
	Stack *sk = (Stack *)malloc(sizeof(Stack));
	StackInit(sk);

	StackPush(sk, 10);
	StackPush(sk, 9);
	StackPush(sk, 8);
	StackPush(sk, 7);
	StackPush(sk, 6);
	StackPush(sk, 5);
	StackPush(sk, 4);
	StackPush(sk, 3);
	StackPush(sk, 2);
	StackPush(sk, 1);
	StackPush(sk, 0);
	printf("%d\n", StackSize(sk)); //11
	printf("%d\n", StackTop(sk));  //0
	StackPop(sk);
	StackPop(sk);
	printf("%d\n", StackTop(sk));  //2

	StackDestory(sk);
}

int main()
{
	testStack();

	return 0;
}