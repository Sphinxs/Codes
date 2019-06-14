// Sort by length: https://www.urionlinejudge.com.br/judge/en/problems/view/1244

#include <stdio.h>

#include <string.h>

#include <stdlib.h>

#include <stdbool.h>

#include <time.h>

#define max 51

typedef struct
{
    char text[max];
    unsigned length;
} Word;

typedef struct Node
{
    Word *word;
    struct Node *left;
    struct Node *right;
} Node;

Node *nodeCreate()
{
    Node *node = (Node *)calloc(1, sizeof(Node *));

    if (!node)
    {
        printf("\033[31mError\033[m on file %s line %d at %s\n", __FILE__, __LINE__, __TIME__);

        return NULL;
    }

    node->left = NULL;

    node->right = NULL;

    node->word = NULL;

    return (node);
}

Word *nodeAddWord(Node *node, const Word *word)
{
    node->word = (Word *)calloc(1, sizeof(Word));

    strcpy(node->word->text, word->text);

    node->word->length = word->length;

    return (node->word);
}

bool nodeEmpty(Node *node)
{
    if (!node->word && !node->left && !node->right)
        return true;
    
    return false;
}

Node *nodeAdd(Node *node, const Word *word)
{
    if (nodeEmpty(node))
    {
        nodeAddWord(node, word);

        return (node);
    }

    Node *newNode = nodeCreate();

    nodeAddWord(newNode, word);

    Node *helper = node;

    Node *tracker = NULL;

    while (helper)
    {
        tracker = helper;

        if (word->length > helper->word->length)
        {
            helper = helper->right;
        }
        else
        {
            helper = helper->left;
        }
    }

    if (word->length > tracker->word->length)
    {
        tracker->right = newNode;
    }
    else
    {
        tracker->left = newNode;
    }

    return (node);
}

void nodeShow(Node *node)
{
    if (!node || !node->word)
        return;

    nodeShow(node->right);

    printf("%s, %u\n", node->word->text, node->word->length);

    nodeShow(node->left);
}

Node *split(char string[])
{
    char pattern[] = " ";

    char *token;

    char cache[max];

    strcpy(cache, string);

    token = strtok(cache, pattern);

    Node *rootString = nodeCreate();

    while (token)
    {
        Word *word = (Word *)calloc(1, sizeof(Word));

        word->length = (unsigned)strlen(token);

        strcpy(word->text, token);

        nodeAdd(rootString, word);

        token = strtok(NULL, pattern);
    }

    return (rootString);
}

void main(const int argc, const char *argv[], const char *envp[])
{
    // Disable buffer
    setbuf(stdin, NULL);

    // DDDD BBB CCC BB BB A
    char test[] = "A DDDD BB BB BBB CCC";

    // Its necessary to free each node and word
    Node *root = split(test);

    nodeShow(root);
}
