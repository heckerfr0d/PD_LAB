#include<stdio.h>

int partition(int*, int, int, int);
void qsort(int*, int, int);
void print(int*, int);
void swap(int*, int*);

int c=0;
int main()
{
    int  i, n;
    scanf("%d", &n);

    int A[n];
    for(i=0;i<n;i++)
        scanf("%d", &A[i]);

    qsort(A, 0, n-1);

    print(A, n);
    printf("%d\n", c);

    return 0;
}

void qsort(int *A, int p, int r)
{
    if(p<r)
    {
        int q = partition(A, p, q, r);

        qsort(A, p, q-1);
        qsort(A, q+1, r);
    }
}

int partition(int *A, int p, int q, int r)
{
    q = p-1;
    int j;

    for(j=p;j<r;j++)
        if(++c && A[j]<=A[r])
            if(++q!=j)
                swap(&A[q], &A[j]);

    swap(&A[++q], &A[r]);

    return q;
}

void print(int *A, int n)
{
    for(int i=0;i<n;i++)
        printf("%d ", A[i]);
    printf("\n");
}

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}