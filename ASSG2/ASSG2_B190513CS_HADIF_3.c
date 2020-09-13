#include<stdio.h>

int bsearch(int*, int, int, int);

int main()
{
    int n, i, x;

    scanf("%d", &n);

    int a[n];

    for(i=0;i<n;i++)
        scanf("%d", &a[i]);

    scanf("%d", &x);

    printf("%d\n", bsearch(a, 0, n-1, x));

    return 0;
}

int bsearch(int *a, int low, int up, int x)
{
    if(low>up)
        return -1;

    int mid = (low+up)/2;

    if(x==a[mid])
        return mid;

    if(x<a[mid])
        return bsearch(a, low, mid-1, x);

    if(x>a[mid])
        return bsearch(a, mid+1, up, x);
}