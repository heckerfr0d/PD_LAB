#include<stdio.h>
#include<stdlib.h>

typedef struct binaryHeap{
    int *a;
    int heapsize;
} heap;

int c=0;
void max_heapify(heap, int);
void build_max_heap(heap);
void heapsort(heap);
void swap(int*, int*);
void print(heap);

int main()
{
    heap h1;
    scanf("%d", &h1.heapsize);
    h1.a = (int*)malloc((h1.heapsize)*sizeof(int));
    for(int i=0;i<h1.heapsize;i++)
        scanf("%d", &h1.a[i]);
    heapsort(h1);
    print(h1);
    return 0;
}

void max_heapify(heap h, int i)
{
    int l=2*i+1;
    int largest = l<h.heapsize && ++c && h.a[l]>h.a[i] ? l : i;
    largest = l+1<h.heapsize && ++c && h.a[largest]<h.a[l+1] ? l+1 : largest;
    if(largest!=i)
    {
        swap(h.a+largest, h.a+i);
        max_heapify(h, largest);
    }
}

void build_max_heap(heap h)
{
    for(int i=(h.heapsize-2)/2;i>=0;i--)
        max_heapify(h, i);
}

void heapsort(heap h)
{
    build_max_heap(h);
    for(int i=h.heapsize-1;i>0;i--)
    {
        swap(h.a, h.a+i);
        h.heapsize--;
        max_heapify(h, 0);
    }
}

void print(heap h)
{
    for(int i=0;i<h.heapsize;i++)
        printf("%d ", h.a[i]);
    printf("\n%d\n", c);
}

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}