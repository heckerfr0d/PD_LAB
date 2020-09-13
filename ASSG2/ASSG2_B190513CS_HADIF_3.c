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

    return x==a[mid]?mid:x<a[mid]?bsearch(a, low, mid-1, x):bsearch(a, mid+1, up, x);
}