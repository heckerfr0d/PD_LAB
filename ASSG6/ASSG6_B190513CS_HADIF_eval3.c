#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    float cgpa;
    char name[32];
    struct node *next;
} *node;

typedef struct list
{
	node head;
    node tail;
} * L;

int n1, n2;

node createNode(float, char*);
node insert(L, node);
node insertAfter(L, node, node);
void combine(L, L);
void print(L);

int main()
{
	L L1 = (L)malloc(sizeof(L));
    L L2 = (L)malloc(sizeof(L));
	L1->head = L1->tail = NULL;
    L2->head = L2->tail = NULL;
	int i;
    scanf("%d%d", &n1, &n2);
    for(i=0;i<n1;i++)
    {
        float cgp;
        char s[32];
        scanf("%s %f", s, &cgp);
        L1->tail = insert(L1, createNode(cgp, s));
    }
    for(i=0;i<n2;i++)
    {
        float cgp;
        char s[32];
        scanf("%s %f", s, &cgp);
        L2->tail = insert(L2, createNode(cgp, s));
    }
    combine(L1, L2);
    print(L1);
	return 0;
}

node createNode(float c, char* n)
{
	node t;
	t = (node)malloc(sizeof(node));
	t->cgpa = c;
	strcpy(t->name, n);
	t->next = NULL;
	return t;
}

node insert(L L, node x)
{
    if(!L->head)
    {
        L->head = x;
        L->tail = x;
        return L->head;
    }
	L->tail->next = x;
    L->tail = x;
    L->tail->next = NULL;
	return L->tail;
}

node insertAfter(L L1, node x, node y)
{
    if(x && y)
    {
	    x->next = y->next;
	    y->next = x;
    }
	return x;
}

void combine(L L1, L L2)
{
    node t1 = L1->head;
    node t2 = L2->head;
    node temp = NULL;
    if(t1->cgpa>t2->cgpa)
    {
        temp = t2->next;
        L1->head = t2;
        L1->head->next = t1;
        t2 = temp;
    }
    while(t1->next && t2)
    {
        if(t1->next->cgpa>t2->cgpa)
        {
            temp = t2->next;
            t1 = insertAfter(L1, t2, t1)->next;
            t2 = temp;
        }
        else
            t1 = t1->next;
    }
    if(t2)
        L1->tail = t1;
    while(t2)
    {
        temp = t2->next;
        L1->tail = insert(L1, t2);
        t2 = temp;
    }

}

void print(L L1)
{
    node t = L1->head;
    while(t!=L1->tail->next)
    {
        printf("\n%s %.2f", t->name, t->cgpa);
        t = t->next;
    }
}