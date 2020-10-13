#include<stdio.h>
#include<stdlib.h>

typedef struct heap{
    int *a;
    int heapsize;
} queue;

int heap_min(queue*);
int heap_extract_min(queue*);
void min_heapify(queue*, int);
void min_heap_insert(queue*, int);
void heap_decrease_key(queue*, int, int);
void swap(int*, int*);

int main()
{
    char c;
    queue *q;
    q->a = NULL;
    q->heapsize = 0;
    int j, k;
    do
    {
        scanf("%c", &c);
        switch(c)
        {
        case 'i':
            scanf("%d", &k);
            q->a = (int*)realloc(q->a, (++q->heapsize)*sizeof(int));
            min_heap_insert(q, k);
            break;
        case 'e':
            printf("%d\n", heap_extract_min(q));
            break;
        case 'm':
            printf("%d\n", heap_min(q));
            break;
        case 'd':
            scanf("%d%d", &j, &k);
            heap_decrease_key(q, j, k);
        }
    }   while(c!='s');
    free(q->a);
    return 0;
}

int heap_min(queue* Q)
{
    return Q->heapsize ? Q->a[0] : -1;
}

int heap_extract_min(queue* Q)
{
    if(Q->heapsize)
    {
        int min = Q->a[0];
        Q->a[0] = Q->a[--Q->heapsize];
        min_heapify(Q, 0);
        return min;
    }
    else
        return -1;
}

void min_heapify(queue* Q, int i)
{
    int l=2*i+1;
    int smallest = l<Q->heapsize && Q->a[l]<Q->a[i] ? l : i;
    smallest = l+1<Q->heapsize && Q->a[smallest]>Q->a[l+1] ? l+1 : smallest;
    if(smallest!=i)
    {
        swap(Q->a+smallest, Q->a+i);
        min_heapify(Q, smallest);
    }
}

void min_heap_insert(queue* Q, int k)
{
    Q->a[Q->heapsize-1] = 1000000;
    heap_decrease_key(Q, Q->heapsize-1, k);
}

void heap_decrease_key(queue* Q, int i, int k)
{
    if(k>Q->a[i])
        printf("Cannot increase priority\n");
    else
    {
        Q->a[i] = k;
        int v = (i-1)/2;
        while(i>0 && Q->a[v]>Q->a[i])
        {
            swap(Q->a+v, Q->a+i);
            i=v;
            v = (i-1)/2;
        }
    }
}

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
