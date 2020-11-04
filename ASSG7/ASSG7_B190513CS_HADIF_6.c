#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
	char system_id[10];
	char filename[5];
	float size;
	int numPages;
	struct Node *next;
} * node;

typedef struct queue
{
	node head;
    node tail;
} * q;

node createRequest(char*, char*, int, float);
node addRequest(q, node);
void extractNextRequest(q);
int qEmpty(q);
void listRequest(q);

int main()
{
	q Q = (q)malloc(sizeof(q));
	Q->head = NULL;
	Q->tail = NULL;
	char c;
	do
	{
		int n;
		char s1[9], s2[4];
		float x;
		scanf("%c", &c);
		switch (c)
		{
		case 'a':
			scanf("%s%s%d%f", s1, s2, &n, &x);
			Q->tail = addRequest(Q, createRequest(s1, s2, n, x));
			break;
		case 'e':
			extractNextRequest(Q);
			break;
        case 'l':
			listRequest(Q);
		}
	} while (c != 't');
	return 0;
}

node createRequest(char*s1, char*s2, int n, float x)
{
	node t = (node)malloc(sizeof(struct Node));
	t->numPages = n;
	t->size = x;
	strcpy(t->system_id, s1);
	strcpy(t->filename, s2);
	t->next = NULL;
	return t;
}

node addRequest(q Q, node x)
{
	if(qEmpty(Q)==-1)
		Q->head = x;
	else
		Q->tail->next = x;
	return x;
}

void extractNextRequest(q Q)
{
	if (qEmpty(Q)==-1)
		printf("-1\n");
	else
	{
		node t = Q->head;
		printf("%s\n", t->system_id);
		Q->head = Q->head->next;
		t->next = NULL;
		free(t);
	}
}

int qEmpty(q Q)
{
    if(Q->head)
        return 1;
    return -1;
}

void listRequest(q Q)
{
	if(!Q->head)
		printf("-1\n");
	else
	{
		node t = Q->head;
		while(t)
		{
			printf("%s %s %d %.1f\n", t->system_id, t->filename, t->numPages, t->size);
			t = t->next;
		}
	}
}