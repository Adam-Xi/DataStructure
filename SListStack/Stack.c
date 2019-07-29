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
	//ÅÐÂú
	if (ps->top == ps->capacity - 1)
	{
		printf("Õ»Âú\n");
		return;
	}
	ps->top++;
	ps->a[ps->top] = x;
}

STDataType StackPop(Stack* ps)
{
	//ÅÐ¿Õ
	if (StackEmpty(ps))
	{
		printf("Õ»¿Õ\n");
		return 0;
	}
	return ps->a[ps->top--];
}

STDataType StackTop(Stack* ps)
{
	//ÅÐ¿Õ
	if (StackEmpty(ps))
	{
		printf("Õ»¿Õ\n");
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