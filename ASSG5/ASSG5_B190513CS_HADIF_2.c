#include<stdio.h>
#include<stdlib.h>

int heapsize=0;
int heap_min(int*);
int extract_heap_min(int*);
void min_heapify(int*, int);
void min_heap_insert(int*, int);
void heap_decrease_key(int*, int, int);
void swap(int*, int*);

int main()
{
    char c;
    int *q = (int*)malloc(0);
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
            printf("%d\n", extract_heap_min(q));
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

void min_heapify(int *A, int i)
{
    int l=2*i+1;
    int smallest = l<heapsize && A[l]<A[i] ? l : i;
    smallest = l+1<heapsize && A[smallest]>A[l+1] ? l+1 : smallest;
    if(smallest!=i)
    {
        swap(A+smallest, A+i);
        min_heapify(A, smallest);
    }
}

int heap_min(int *A)
{
    return heapsize>0 ? A[0] : -1;
}

int extract_heap_min(int *A)
{
    if(heapsize>0)
    {
        int min = A[0];
        A[0] = A[--heapsize];
        min_heapify(A, 0);
        return min;
    }
    else
        return -1;
}

void heap_decrease_key(int *A, int i, int k)
{
    if(k>A[i])
        printf("Cannot increase priority\n");
    else
    {
        A[i] = k;
        int v = i%2 ? (i-1)/2 : i/2-1;
        while(i>0 && A[v]>A[i])
        {
            swap(A+v, A+i);
            i=v;
            v = i%2 ? (i-1)/2 : i/2-1;
        }
    }
}


void min_heap_insert(int *A, int k)
{
    A[heapsize-1] = 1000000;
    heap_decrease_key(A, heapsize-1, k);
}

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
