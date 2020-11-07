#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct PCB
{
	int process_id;
    char priority[8];
	struct PCB *next;
} * process;

typedef struct PCBlist
{
	process head;
    process tail;
} * pL;

process createPCB(int, char*);
void insertReady(pL, process);
void insertTail(pL, process);
void insertT(pL, process);
void insert(pL, process);
int listProcesses(pL);
void updateState(int, pL, pL);
process schedule(process, pL);

int main()
{
	pL N = (pL)malloc(sizeof(pL));
	pL R = (pL)malloc(sizeof(pL));
	pL T = (pL)malloc(sizeof(pL));
	pL W = (pL)malloc(sizeof(pL));
    process p = NULL, t = NULL;
	N->head = N->tail = R->head = R->tail = T->head = T->tail = W->head = W->tail = NULL;
	char c;
	do
	{
		int x;
        char s1[8], s2[8];
		scanf("%c", &c);
		switch (c)
		{
		case 'c':
			scanf("%s", s1);
            if(!T->head)
            {
                if(!N->tail)
                    insertTail(N, createPCB(1, s1));
                else
                    insertTail(N, createPCB(N->tail->process_id+1, s1));
            }
            else if(N->tail && N->tail->process_id+1<T->head->process_id)
                insertTail(N, createPCB(N->tail->process_id+1, s1));
            else
            {
                insertTail(N, createPCB(T->head->process_id, s1));
                T->head->process_id = 999;
                if(T->head->next)
                {
                    t = T->head;
                    T->head = T->head->next;
                    T->tail->next=t;
                    t->next = NULL;
                }
            }
			break;
		case 'l':
			scanf("%d", &x);
			switch (x)
            {
            case 1:
                if(listProcesses(N))
                    printf("-1\n");
                break;
            case 2:
                if(listProcesses(R))
                    printf("-1\n");
                break;
            case 3:
                if(listProcesses(W))
                    printf("-1\n");
                break;
            case 4:
                if(listProcesses(T))
                    printf("-1\n");
                break;
            }
			break;
		case 'u':
			scanf("%d %s %s", &x, s1, s2);
            if(s1[0]=='r' && s1[1]=='u' && s2[0]=='w')
            {
                insertTail(W, p);
                p = NULL;
                p = schedule(p, R);
            }
            else if(s1[0]=='n' && s2[0]=='r' && s2[1]=='e')
                updateState(x, N, R);
            else if(s1[0]=='w' && s2[0]=='r' && s2[1]=='e')
                updateState(x, W, R);
			break;
		case 's':
            p = schedule(p, R);
			break;
		case 't':
			printf("%d\n", p->process_id);
            insertT(T, p);
            p = NULL;
            p = schedule(p, R);
            break;
        }
	} while (c != 'e');
	return 0;
}

process createPCB(int k, char* s)
{
	process t = (process)malloc(sizeof(process));
	t->process_id = k;
	strcpy(t->priority, s);
	t->next = NULL;
	return t;
}

void insertReady(pL L, process x)
{
    if(!L->head || L->tail->priority[0]+L->tail->priority[1]<=x->priority[0]+x->priority[1])
        insertTail(L, x);
    else if(x->priority[0]+x->priority[1]<L->head->priority[0]+L->head->priority[1])
        insert(L, x);
    else
    {
        process t = L->head;
        while(t->next && t->next->priority[0]+t->next->priority[1]<=x->priority[0]+x->priority[1])
            t = t->next;
        x->next = t->next;
        t->next = x;
    }
}

void insertTail(pL L, process x)
{
    if(!L->head)
        L->head = L->tail = x;
    else
    {
        L->tail->next = x;
        L->tail = x;
    }
}

void insert(pL L, process x)
{
    if(!L->head)
        L->tail = x;
	x->next = L->head;
	L->head = x;
}

void insertT(pL T, process p)
{
    if(!T->head)
        T->head = T->tail = p;
    else if(T->head->process_id>p->process_id)
    {
        p->next = T->head;
        T->head = p;
    }
    else
    {
        process t = T->head;
        while(t->next && t->next->process_id<p->process_id)
            t = t->next;
        p->next = t->next;
        t->next = p;
        if(!p->next)
            T->tail = p;
    }
    p = NULL;
}

int listProcesses(pL L)
{
    if(!L->head)
        return 1;
    process t = L->head;
    while(t)
    {
        printf("%d ", t->process_id);
		t = t->next;
    }
    printf("\n");
    return 0;
}

void updateState(int k, pL L1, pL L2)
{
    process t = L1->head;
    process prev = NULL;
    while(t && t->process_id!=k)
    {
        prev = t;
        t = t->next;
    }
    if(t)
    {
        if(!prev)
            L1->head = L1->head->next;
        else
            prev->next = t->next;
        if(t==L1->tail)
            L1->tail = prev;
        t->next = NULL;
        insertReady(L2, t);
    }
}

process schedule(process p, pL R)
{
    if(!R->head)
        printf("-1\n");
    else
    {
        if(p)
            insertReady(R, p);
        p = R->head;
        R->head = R->head->next;
        p->next = NULL;
    }
    return p;
}
