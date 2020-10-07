#include<stdio.h>

int heapsize, n, c=0;
void max_heapify(int*, int);
void build_max_heap(int*);
void heapsort(int*);
void swap(int*, int*);
void print(int*);

int main()
{
    int i;
    scanf("%d", &n);
    int a[n];
    heapsize = n;
    for(i=0;i<n;i++)
        scanf("%d", &a[i]);
    heapsort(a);
    print(a);
    return 0;
}

void max_heapify(int *A, int i)
{
    int l=2*i+1;
    int largest = l<heapsize && ++c && A[l]>A[i] ? l : i;
    largest = l+1<heapsize && ++c && A[largest]<A[l+1] ? l+1 : largest;
    if(largest!=i)
    {
        swap(A+largest, A+i);
        max_heapify(A, largest);
    }
}

void build_max_heap(int *A)
{
    int i;
    for(i=(n-1)/2;i>=0;i--)
        max_heapify(A, i);
}

void heapsort(int *A)
{
    int i;
    build_max_heap(A);
    for(i=n-1;i>0;i--)
    {
        swap(A, A+i);
        heapsize--;
        max_heapify(A, 0);
    }
}

void print(int *A)
{
    int i;
    for(i=0;i<n;i++)
        printf("%d ", A[i]);
    printf("\n%d\n", c);
}

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}