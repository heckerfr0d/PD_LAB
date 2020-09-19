#include<stdio.h>
#include<stdlib.h>

void merge(int*, int, int, int);
void merge_sort(int*, int, int);
void print(int*, int);

int c=0;

int main()
{
    int n, i;
    scanf("%d", &n);

    int *a = (int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
        scanf("%d", a+i);
    merge_sort(a, 0, n-1);
    print(a, n);
    printf("%d\n", c);
    return 0;
}

void merge_sort(int *a, int p, int r)
{
    if(p<r)
    {
        int q = p+(r-p)/2;
        merge_sort(a, p, q);
        merge_sort(a, q+1, r);
        merge(a, p, q, r);
    }
}

void merge(int *a, int p, int q, int r)
{
    int i, j, n1=q-p+1, n2=r-q;
    int L[n1], R[n2];
    for(i=0;i<n1;i++)
        L[i]=*(a+p+i);
    for(i=0;i<n2;i++)
        R[i]=*(a+q+1+i);
    i=j=0;
    int k = p;
    while(i<n1 && j<n2)
    {
        if(L[i]<R[j])
        {
            *(a+k)=L[i++];
            k++;
        }
        else
        {
            *(a+k)=R[j++];
            k++;
        }
        c++;
    }
    while(i<n1)
    {
        *(a+k)=L[i++];
        k++;
        c++;
    }
    while(j<n2)
    {
        *(a+k)=R[j++];
        k++;
        c++;
    }
}

void print(int *a, int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%d ", *(a+i));
    printf("\n");
}