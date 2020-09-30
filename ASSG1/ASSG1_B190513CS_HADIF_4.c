#include<stdio.h>
#include<stdlib.h>

int* rot(int*, int *, int, int);

int main()
{
    int n, i, k;
    scanf("%d %d", &n, &k);
    int a[n];
    int *b;
    for(i=0;i<n;i++)
        scanf("%d", &a[i]);
    if(k<n)
    {
        b=rot(a, b, n, k);
    }
    else
    {
        k%=n;
        b=rot(a, b, n, k);
    }

    for(i=0;i<n;i++)
        printf("%d ", b[i]);
    
    return 0;
}

int* rot(int *a, int *b, int n, int k)
{
    int i;
    b=malloc(n*sizeof(int));
    for(i=0;i<n;i++)
        b[i]=a[(i+k+1)%n];
    return b;
}