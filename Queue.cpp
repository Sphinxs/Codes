

#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#define lenStr 50

static int sizeQueue = 0;

typedef struct
{
	char nick[lenStr], element[lenStr];
	int strength;
} Info;

typedef struct no
{
	Info fighter;
	struct no *next;
} Node;

typedef struct
{
	Node *home;
	Node *end;
} Queue;

void initialize(Queue *q)
{
	q->home = NULL;

	q->end = NULL;
}

int empty(Queue *q)
{
	if (q->home == NULL && q->end == NULL)
		return 1;

	return 0;
}

Node *createNode()
{
	Node *cache = (Node *)calloc(1, sizeof(Node));

	return cache;
}

int add(Queue *q, Info data)
{
	Node *cache = createNode();

	if (cache == NULL)
		return 0;

	cache->fighter = data;

	cache->next = NULL;

	if (empty(q))
	{
		q->home = cache;

		q->end = cache;

		sizeQueue++;

		return 1;
	}

	q->end->next = cache;

	q->end = cache;

	sizeQueue++;

	return 1;
}

Info remove(Queue *q)
{
	Info cache;

	cache.strength = -1;

	if (empty(q))
		return cache;

	cache = q->home->fighter;

	if (q->home == q->end)
	{
		free(q->home);

		initialize(q);

		sizeQueue--;
	}
	else
	{
		Node *aux = q->home;

		q->home = q->home->next;

		free(aux);

		sizeQueue--;
	}

	return cache;
}

void show(Queue *q)
{
	if (empty(q))
		return;

	Queue temp;

	Info cache;

	while (empty(q) != 1)
	{
		cache = remove(q);

		printf("\n\t%s - %s - %d\n", cache.nick, cache.element, cache.strength);

		add(&temp, cache);
	}

	while (empty(&temp) != 1)
	{
		cache = remove(&temp);

		add(q, cache);
	}
}

int main()
{
	return 0;
}