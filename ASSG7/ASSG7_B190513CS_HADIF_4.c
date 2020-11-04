#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
} * node;

typedef struct queue
{
	node head;
    node tail;
} * q;

node createNode(int);
node enQ(q, node);
int deQ(q);
int qEmpty(q);

int main()
{
	q Q = (q)malloc(sizeof(q));
	Q->head = NULL;
	Q->tail = NULL;
	char c;
	do
	{
		int x, y;
		scanf("%c", &c);
		switch (c)
		{
		case 'i':
			scanf("%d", &x);
			Q->tail = enQ(Q, createNode(x));
			break;
		case 'd':
			printf("%d\n", deQ(Q));
			break;
        case 'e':
			printf("%d\n", qEmpty(Q));
		}
	} while (c != 't');
	return 0;
}

node createNode(int k)
{
	node t;
	t = (node)malloc(sizeof(node));
	t->data = k;
	t->next = NULL;
	return t;
}

node enQ(q Q, node x)
{
	if(qEmpty(Q)==-1)
		Q->head = x;
	else
		Q->tail->next = x;
	return x;
}

int deQ(q Q)
{
	if (qEmpty(Q)==-1)
		return -1;
	node t = Q->head;
	Q->head = Q->head->next;
	int k = t->data;
	t->next = NULL;
	free(t);
	return k;
}

int qEmpty(q Q)
{
    if(Q->head)
        return 1;
    return -1;
}