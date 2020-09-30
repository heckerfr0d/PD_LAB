#include<stdio.h>
#include<stdbool.h>

bool lsearch(int*, int, int);

int main()
{
    int m, n, i, k, mn, mx, *f, *o;
    scanf("%d %d", &m, &n);
    int a[m], b[n], c[m+n];
    for(i=0;i<m;i++)
        scanf("%d", &a[i]);
    for(i=0;i<n;i++)
        scanf("%d", &b[i]);
    mx = m>n?m:n;
    mn = m>n?n:m;
    f = m>n?a:b;
    o = m>n?b:a;

    for(i=0;i<mx;i++)
        c[i]=*(f+i);
    k=mx;
    for(i=0;i<mn;i++)
        if(!lsearch(f, mx, *(o+i)))
            c[k++]=*(o+i);
    
    for(i=0;i<k;i++)
        printf("%d ", c[i]);
    printf("\n");
    return 0;
}

bool lsearch(int *a, int n, int x)
{
    int i;
    for(i=0;i<n;i++)
        if(a[i]==x)
            return true;
    return false;
}