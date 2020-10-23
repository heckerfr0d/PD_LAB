#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct PCB
{
	int process_id;
    char state[11];
	struct PCB *next;
} * process;

typedef struct PCBlist
{
	process head;
} * pL;

process createPCB(int, char*);
process insert(pL, process);
int delete(pL, process);
char* getState(int, pL);
int listWaitingP(pL);
process updateState(pL, int, char*);
process listSearch(pL, int);

int main()
{
	pL L = (pL)malloc(sizeof(pL));
	L->head = NULL;
	char c;
	do
	{
		int x;
        char *s;
		scanf("%c", &c);
		switch (c)
		{
		case 'i':
			scanf("%d %s", &x, s);
			L->head = insert(L, createPCB(x, s));
			break;
		case 'd':
			scanf("%d", &x);
			printf("%d\n", delete(L, createPCB(x, "")));
			break;
		case 'g':
			scanf("%d", &x);
			printf("%s\n", getState(x, L));
			break;
		case 'l':
			if(listWaitingP(L))
				printf("-1\n");
			break;
		case 'u':
			scanf("%d %s", &x, s);
			L->head = updateState(L, x, s);
        }
	} while (c != 'e');
	return 0;
}

process createPCB(int k, char* s)
{
	process t;
	t = (process)malloc(sizeof(process));
	t->process_id = k;
	strcpy(t->state, s);
	t->next = NULL;
	return t;
}

process insert(pL L, process x)
{
	x->next = L->head;
	L->head = x;
	return L->head;
}

int delete(pL L, process x)
{
	if (!L->head)
		return -1;
	process t = L->head, p = NULL;
	while (t->next && t->process_id != x->process_id)
	{
		p = t;
		t = t->next;
	}
	if (t->process_id != x->process_id)
		return -1;
	x = t;
	int k = x->process_id;
	if(p)
		p->next = x->next;
	else
		L->head = NULL;
	x->next = NULL;
	free(x);
	return k;
}

char* getState(int k, pL L)
{
    process t = listSearch(L, k);
    if(!t)
        return "-1";
    return t->state;
}

int listWaitingP(pL L)
{
    if(!L->head)
        return 1;
    int f=1;
    process t = L->head;
    while(t->next)
    {
        if(!strcmp(t->state, "waiting"))
        {
            printf("%d ", t->process_id);
            f=0;
        }
		t = t->next;
    }
    return f;
}

process updateState(pL L, int k, char* s)
{
    process t = listSearch(L, k);
    if(t)
        strcpy(t->state, s);
    return L->head;
}

process listSearch(pL L, int k)
{
	if (!L->head)
		return NULL;
	process t = L->head;
	while (t && t->process_id != k)
		t = t->next;
	return t;
}
