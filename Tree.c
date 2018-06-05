
#include <stdio.h>

#include <string.h>

#include <stdlib.h>

#define sizeStr 50

typedef struct
{
	int id;
	char name[sizeStr], course[sizeStr], mail[sizeStr];
} Info;

typedef struct no
{
	Info person;
	struct no *left, *right;
} Node;

void initialize(Node **root)
{
	(*root) = NULL;
}

int empty(const Node **root)
{
	if ((*root) == NULL)
		return 1;

	return 0;
}

Node *createNo()
{
	Node *cache = (Node *)calloc(1, sizeof(Node));

	if (cache == NULL)
		exit(1);

	return cache;
}

void add(Node **root, const Info cell)
{
	if (empty(root))
	{

		(*root) = createNo();

		(*root)->left = NULL;

		(*root)->right = NULL;

		(*root)->person = cell;
	}
	else
	{
		if (cell.id < (*root)->person.id)
			add(&(*root)->left, cell);
		else
			add(&(*root)->right, cell);
	}
}

void show(Node **root)
{
	if ((*root))
	{
		show(&(*root)->left);

		printf("\n%s | %s | %d | %s\n", (*root)->person.name, (*root)->person.course, (*root)->person.id, (*root)->person.mail);

		show(&(*root)->right);

	}
}

Node *search(Node **root, const int id)
{
	Node *cache = NULL;

	if (!(*root))
		return NULL;

	if ((*root)->person.id == id)
		return (*root);

	cache = search(&(*root)->left, id);

	if (cache)
		return cache;

	return search(&(*root)->right, id);
}

int updateCourse(Node **root, const int id, char *course)
{
	Node *cache = search(root, id);

	if (!cache)
		return 0;

	strcpy(cache->person.course, course);

	return 1;
}

int main()
{
	return 0;
}