#include<stdio.h>

int insertion_sort(int*, int);
void print(int*, int);

int main()
{
    int n, k;
    scanf("%d", &n);
    int a[n];
    for(k=0; k<n; k++)
        scanf("%d", &a[k]);
    k = insertion_sort(a, n);
    print(a, n);
    printf("\n%d\n", k);
    return 0;
}

int insertion_sort(int *a, int n)
{
    int i, j, t, c=0;
    for(i=1;i<n;i++)
    {
        t=a[i];
        j=i-1;
        while(j>=0 && ++c && a[j]>t)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=t;
    }
    return c;
}

void print(int *a, int n)
{
    for(int i=0;i<n;i++)
        printf("%d ", a[i]);
}