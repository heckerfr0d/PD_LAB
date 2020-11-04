#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
} * node;

typedef struct stack
{
	node top;
} * stack;

node createNode(int);
node push(stack, node);
int pop(stack);
int stackEmpty(stack);

int main()
{
	stack S = (stack)malloc(sizeof(stack));
	S->top = NULL;
	char c;
	do
	{
		int x, y;
		scanf("%c", &c);
		switch (c)
		{
		case 'i':
			scanf("%d", &x);
			S->top = push(S, createNode(x));
			break;
		case 'd':
			printf("%d\n", pop(S));
			break;
        case 'e':
			printf("%d\n", stackEmpty(S));
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

node push(stack S, node x)
{
	x->next = S->top;
	return x;
}

int pop(stack S)
{
	if (stackEmpty(S)==-1)
		return -1;
	node t = S->top;
	S->top = S->top->next;
	int k = t->data;
	t->next = NULL;
	free(t);
	return k;
}

int stackEmpty(stack S)
{
    if(S->top)
        return 1;
    return -1;
}