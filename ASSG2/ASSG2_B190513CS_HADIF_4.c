#include<stdio.h>

int bsearch(int*, int, int, int, char);
int lim(int*, int);

int main()
{
    int n, i, x, f1, l;

    scanf("%d", &n);

    int a[n];

    for(i=0;i<n;i++)
        scanf("%d", &a[i]);

    scanf("%d", &x);
    l = lim(a,n);
    f1 = bsearch(a, 0, l-1, x, 'a');
    if(f1==-1)
        printf("%d\n", bsearch(a, l, n-1, x, 'd'));
    else
        printf("%d\n", f1);

    return 0;
}

int lim(int *a, int n)
{
    int i;
    for(i=0;i<n;i++)
        if(a[i+1]<a[i])
            return i+1;
}

int bsearch(int *a, int low, int up, int x, char m)
{
    if(low>up)
        return -1;

    int mid = (low+up)/2;
    if(m=='a')
        return x==a[mid]?mid:x<a[mid]?bsearch(a, low, mid-1, x, 'a'):bsearch(a, mid+1, up, x, 'a');
    if(m=='d')
        return x==a[mid]?mid:x>a[mid]?bsearch(a, low, mid-1, x, 'd'):bsearch(a, mid+1, up, x, 'd');
}