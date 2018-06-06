
#include <stdio.h>

void construct(int *sizeStack)
{
	*sizeStack = -1;
}

int empty(int *sizeStack)
{
	if (*sizeStack == -1)
		return 1;
	else
		return 0;
}

int push(const int value, int *sizeStack, int stack[], const int max)
{
	if (*sizeStack >= max)
		return 1;
	else
	{
		*sizeStack++;

		stack[*sizeStack] = value;
	}

	return 0;
}

int pop(int *sizeStack, int stack[])
{
	int cache

	if (*sizeStack <= -1)
		return 1;
	else
	{
		cache = stack[*sizeStack];

		*sizeStack--;
	}

	return cache;
}

int main()
{
}