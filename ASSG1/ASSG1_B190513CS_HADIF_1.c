#include<stdio.h>

void lsearch(int*, int, int);

int main()
{
    int n, i=0, x;

    scanf("%d", &n);

    int a[n];

    for(i=0;i<n;i++)
        scanf("%d", &a[i]);
    scanf("%d", &x);

    lsearch(a, n, x);

    return 0;
}

void lsearch(int *a, int n, int x)
{
    int i, r=-1;

    for(i=0;i<n;i++)
        if(a[i]==x)
            r = printf("%d ", i);

    if(r==-1)
        printf("%d ", r);
    printf("\n");
}