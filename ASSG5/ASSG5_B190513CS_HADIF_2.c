#include<stdio.h>
#include<stdlib.h>

int heapsize=0;
int heap_min(int*);
int heap_extract_min(int*);
void min_heapify(int*, int);
void min_heap_insert(int*, int);
void heap_decrease_key(int*, int, int);
void swap(int*, int*);

int main()
{
    char c;
    int *q = NULL;
    int j, k;
    do
    {
        scanf("%c", &c);
        switch(c)
        {
        case 'i':
            scanf("%d", &k);
            q = (int*)realloc(q, (++heapsize)*sizeof(int));
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
    free(q);
    return 0;
}

int heap_min(int *Q)
{
    return heapsize ? Q[0] : -1;
}

int heap_extract_min(int *Q)
{
    if(heapsize)
    {
        int min = Q[0];
        Q[0] = Q[--heapsize];
        min_heapify(Q, 0);
        return min;
    }
    else
        return -1;
}

void min_heapify(int *Q, int i)
{
    int l=2*i+1;
    int smallest = l<heapsize && Q[l]<Q[i] ? l : i;
    smallest = l+1<heapsize && Q[smallest]>Q[l+1] ? l+1 : smallest;
    if(smallest!=i)
    {
        swap(Q+smallest, Q+i);
        min_heapify(Q, smallest);
    }
}

void min_heap_insert(int *Q, int k)
{
    Q[heapsize-1] = 1000000;
    heap_decrease_key(Q, heapsize-1, k);
}

void heap_decrease_key(int *Q, int i, int k)
{
    if(k>Q[i])
        printf("Cannot increase priority\n");
    else
    {
        Q[i] = k;
        int v = i%2 ? (i-1)/2 : i/2-1;
        while(i>0 && Q[v]>Q[i])
        {
            swap(Q+v, Q+i);
            i=v;
            v = i%2 ? (i-1)/2 : i/2-1;
        }
    }
}

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
