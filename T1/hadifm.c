#include <stdio.h>

void read(int*, int*, int);
void locate_ISBN(int*, int*, int, int);
int lsearch(int*, int, int);
void swap(int*, int*);

int main()
{
    int n, i;
    scanf("%d %d", &n, &i);
    int A[n], B[n];
    read(A, B, n);
    locate_ISBN(A, B, n, i);
    return 0;
}

void read(int *A, int *B, int n)
{
    int i;
    for(i=0;i<n;i++)
        scanf("%d %d", &A[i], &B[i]);
}

void locate_ISBN(int *A, int *B, int n, int i)
{
    int k=lsearch(A, n, i);
    int k1=A[k], k2=B[k];
    int j=0;
    int l=j-1;
    for(j=0;j<n;j++)
    {
        if(B[j]<k2)
        {
            swap(&B[l+1], &B[j]);
            swap(&A[l+1], &A[j]);
            l++;
        }
    }
    k=lsearch(A, n, i);
    swap(&B[l+1], &B[k]);
    swap(&A[l+1], &A[k]);
    for(i=0;i<n;i++)
        printf("%d %d\n", A[i], B[i]);
}

void swap(int *a, int *b)
{
    int t = *b;
    *b = *a;
    *a = t;
}

int lsearch(int *a, int n, int x)
{
    int i;
    for(i=0;i<n;i++)
        if(a[i]==x)
            return i;
}