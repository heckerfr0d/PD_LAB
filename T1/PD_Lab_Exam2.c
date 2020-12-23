#include<stdio.h>
#include<stdlib.h>

void visit_ward(int*, int*, int*, int, int);
void display(int*, int);
void get_times(int*, int*, int);

int main()
{
    int n, t;
    scanf("%d", &n);
    scanf("%d", &t);
    int D[n], C[n], T[n];
    get_times(D, T, n);
    visit_ward(D, C, T, n, t);
    display(C, n);
    return 0;
}

void get_inspection_time(int *D, int n)
{
    for(int i=0;i<n;i++)
        scanf("%d", D+i);
}

void get_times(int* D, int *T, int n)
{
    for(int i=0;i<n;i++)
        scanf("%d%d", T+i, D+i);
}

void print(int *a, int n)
{
    for(int i=0;i<n;i++)
        printf("%d ", a[i]);
    printf("\n");
}

void display(int *C, int n)
{
    int i, j, t, a[n];
    a[0] = 1;
    for(i=1;i<n;i++)
    {
        a[i] = i+1;
        t = C[i];
        j = i-1;
        while(j>=0 && C[j]>t)
        {
            C[j+1] = C[j];
            a[j+1] = a[j];
            j--;
        }
        C[j+1] = t;
        a[j+1] = i+1;
    }
    for(int i=0;i<n;i++)
        printf("%d %d\n", a[i], C[i]);
    printf("\n");
}

void visit_ward(int *D, int *C, int *T, int n, int t)
{
    int t1=0, nc=0;
    while(nc<n)
    {
        int mt=9999, ri=-1;
        for(int i=0;i<n;i++)
        {
            if(T[i]<=t1 && D[i]>0)
            {
                if(D[i]<mt)
                {
                    mt = D[i];
                    ri = i;
                }
                else if(D[i]==mt && T[i]<T[ri])
                    ri = i;
            }
        }
        if(ri!=-1)
        {
            if(D[ri]>t)
            {
                D[ri] -= t;
                t1 += t;
            }
            else
            {
                t1 += D[ri];
                C[ri] = t1;
                D[ri] = 0;
                nc++;
            }
        }
    }
}