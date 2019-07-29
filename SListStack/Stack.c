#include"Stack.h"

void StackInit(Stack* ps, int size)
{
	ps->capacity = size;
	ps->top = -1;
}

void StackDestory(Stack* ps)
{
	ps->top = -1;
	ps->capacity = 0;
}

void StackPush(Stack* ps, STDataType x)
{
	//����
	if (ps->top == ps->capacity - 1)
	{
		printf("ջ��\n");
		return;
	}
	ps->top++;
	ps->a[ps->top] = x;
}

STDataType StackPop(Stack* ps)
{
	//�п�
	if (StackEmpty(ps))
	{
		printf("ջ��\n");
		return 0;
	}
	return ps->a[ps->top--];
}

STDataType StackTop(Stack* ps)
{
	//�п�
	if (StackEmpty(ps))
	{
		printf("ջ��\n");
		return 0;
	}
	return ps->a[ps->top];
}

int StackEmpty(Stack* ps)
{
	if (ps->top == -1)
	{
		return 1;
	}
	return 0;
}

int StackSize(Stack* ps)
{
	int size = 0;
	if (!StackEmpty(ps))
	{
		while (ps->top != 0)
		{
			ps->top--;
			size++;
		}
	}
	return size;
}