
#include <stdio.h>

#include <stdlib.h>

#define max 50

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

int push(const int value, int *sizeStack, int stack[])
{
	if (*sizeStack >= max)
		exit(1);
	else
	{
		*sizeStack++;

		stack[*sizeStack] = value;
	}
}

int pop(int *sizeStack, int stack[])
{
	if (*sizeStack < 1)
		exit(1);
	else
	{
		int cache = stack[*sizeStack];

		*sizeStack--;
	}

	return 0;
}

int main()
{
	int sizeStack = 0;

	int stack[max] = {0};
}