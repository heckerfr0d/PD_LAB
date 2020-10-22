#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int key;
	struct node *next;
} * node;

typedef struct linkedList
{
	node head;
} * lL;

node createNode(int);
node insertFront(lL, node);
node insertTail(lL, node);
node insertAfter(lL, node, node);
node insertBefore(lL, node, node);
int listDelete(lL, node);
int deleteFirst(lL);
int deleteLast(lL);
node listSearch(lL, int);

int main()
{
	lL L = (lL)malloc(sizeof(lL));
	L->head = NULL;
	char c;
	do
	{
		int x, y;
		scanf("%c", &c);
		switch (c)
		{
		case 'f':
			scanf("%d", &x);
			L->head = insertFront(L, createNode(x));
			break;
		case 't':
			scanf("%d", &x);
			L->head = insertTail(L, createNode(x));
			break;
		case 'a':
			scanf("%d%d", &x, &y);
			L->head = insertAfter(L, createNode(x), listSearch(L, y));
			break;
		case 'b':
			scanf("%d%d", &x, &y);
			L->head = insertBefore(L, createNode(x), createNode(y));
			break;
		case 'd':
			scanf("%d", &x);
			printf("%d\n", listDelete(L, createNode(x)));
			break;
		case 'i':
			printf("%d\n", deleteFirst(L));
			break;
		case 'l':
			printf("%d\n", deleteLast(L));
			break;
		case 's':
			scanf("%d", &x);
			listSearch(L, x) ? printf("1\n") : printf("-1\n");
		}
	} while (c != 'e');
	return 0;
}

node createNode(int k)
{
	node t;
	t = (node)malloc(sizeof(node));
	if (!t)
	{
		printf("Error Creating Node. Out of Memory?\n");
		exit(1);
	}
	t->key = k;
	t->next = NULL;
	return t;
}

node insertFront(lL L, node x)
{
	x->next = L->head;
	L->head = x;
	return L->head;
}

node insertTail(lL L, node x)
{
	if (!L->head)
	{
		L->head = x;
		return L->head;
	}
	node t = L->head;
	while (t->next)
		t = t->next;
	t->next = x;
	return L->head;
}

node insertAfter(lL L, node x, node y)
{
	if (!y)
		return L->head;
	x->next = y->next;
	y->next = x;
	return L->head;
}

node insertBefore(lL L, node x, node y)
{
	if (!L->head)
	{
		L->head = x;
		return L->head;
	}
	node t = L->head, p = NULL;
	while (t->next && t->key != y->key)
	{
		p = t;
		t = t->next;
	}
	if (t->key != y->key)
		return NULL;
	y = t;
	if(p)
		p->next = x;
	else
		L->head = x;
	x->next = y;
	return L->head;
}

int listDelete(lL L, node x)
{
	if (!L->head)
		return -1;
	node t = L->head, p = NULL;
	while (t->next && t->key != x->key)
	{
		p = t;
		t = t->next;
	}
	if (t->key != x->key)
		return -1;
	x = t;
	int k = x->key;
	if (p)
		p->next = x->next;
	else
		L->head = L->head->next;
	x->next = NULL;
	free(x);
	return k;
}

int deleteFirst(lL L)
{
	if (!L->head)
		return -1;
	node t = L->head;
	L->head = L->head->next;
	int k = t->key;
	t->next = NULL;
	free(t);
	return k;
}

int deleteLast(lL L)
{
	if (!L->head)
		return -1;
	node t = L->head, p = NULL;
	while (t->next)
	{
		p = t;
		t = t->next;
	}
	int k = t->key;
	if (p)
		p->next = NULL;
	else
		L->head = NULL;
	free(t);
	return k;
}

node listSearch(lL L, int k)
{
	if (!L->head)
		return NULL;
	node t = L->head;
	while (t && t->key != k)
		t = t->next;
	return t;
}
