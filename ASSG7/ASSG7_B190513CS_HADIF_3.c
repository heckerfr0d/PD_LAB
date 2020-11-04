#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
    int head, tail, n;
    int *A;
} *q;

int qEmpty(q);
int qFull(q);
void enq(q, int);
int deq(q);

int main()
{
    q Q;
    char c;
    int x, n;
    scanf("%d", &Q->n);
    Q->head = -1;
    Q->tail = -1;
    Q->A = (int*)malloc(Q->n*sizeof(int));
    do
    {
        scanf("%c", &c);
        switch (c)
        {
        case 'i':
            scanf("%d", &x);
            enq(Q, x);
            break;
        case 'd':
            printf("%d\n", deq(Q));
            break;
        case 'f':
            printf("%d\n", qFull(Q));
            break;
        case 'e':
            printf("%d\n", qEmpty(Q));
        }
    } while (c!='t');
    return 0;
}

int qEmpty(q Q)
{
    if(Q->head==-1)
        return -1;
    return 1;
}

int qFull(q Q)
{
    if(Q->head==Q->tail && Q->head!=-1)
        return -1;
    return 1;
}

void enq(q Q, int k)
{
    if(qEmpty(Q)==-1)
    {
        Q->A[++Q->head] = k;
        Q->tail = 1;
    }
    else if(qFull(Q)!=-1)
    {
        Q->A[Q->tail] = k;
        Q->tail = (Q->tail+1)%Q->n;
    }
    else
        printf("-1\n");
}

int deq(q Q)
{
    if(qEmpty(Q)!=-1)
    {
        int t = Q->head;
        Q->head = (Q->head+1)%Q->n;
        if(Q->head==Q->tail)
            Q->head = Q->tail = -1;
        return Q->A[t];
    }
    return -1;
}