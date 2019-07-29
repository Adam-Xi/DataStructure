#include"SeqStack.h"

void StackInit(Stack *sk)
{
	sk->_top = -1;
	sk->_capacity = STACKSIZE;
}

void StackDestory(Stack *sk)
{
	sk->_top = -1;
	sk->_capacity = 0;
}

void StackPush(Stack *sk, STDataType x)
{
	if (sk->_top == sk->_capacity) //栈溢出
	{
		return;
	}
	sk->_top++;
	sk->array[sk->_top] = x;
}
void StackPop(Stack *sk)
{
	sk->_top--;
}
STDataType StackTop(Stack *sk)
{
	return sk->array[sk->_top];
}
int StackIsEmpty(Stack *sk)
{
	if (sk->_top == -1)
	{
		return 1;
	}
	return 0;
}
int StackSize(Stack *sk)
{
	return sk->_top + 1;
}
