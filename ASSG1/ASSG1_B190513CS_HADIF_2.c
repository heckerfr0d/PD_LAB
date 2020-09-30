#include<stdio.h>

void swap(int*, int*);
void b_sort(int*, int);

int main()
{
    int n, i;
    
    scanf("%d", &n);

    int a[n];
        
    for(i=0;i<n;i++)
        scanf("%d", &a[i]);
        
    b_sort(a, n);
        
    for(i=0;i<n;i++)
        printf("%d ", a[i]);
    printf("\n");

    return 0;
}

void swap(int *a, int *b)
{
    *a += *b;
    *b = *a - *b;
    *a -= *b;
}

void b_sort(int *a, int n)
{
    int i, j;

    for(i=0;i<n-1;i++)
        for(j=0;j<n-1-i;j++)
            if(a[j]>a[j+1])
                swap(&a[j], &a[j+1]);
}