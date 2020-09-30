#include<stdio.h>

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
    int i;
    for(i=0;i<n;i++)
        scanf("%d", D+i);
}

void get_times(int* D, int *T, int n)
{
    int i;
    for(i=0;i<n;i++)
        scanf("%d %d", T+i, D+i);
}

void display(int *C, int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%d ", C[i]);
    printf("\n");
}

void visit_ward(int *D, int *C, int *T, int n, int t)
{
    int flag, t1=0, i, k, min;
    loop:
    flag=0;
    for(i=0;i<n;i++)
    {
        if(T[i]<=t1 && D[i]>0)
        {
            min=D[i];
            int j;
            for(j=0;j<n;j++)
            {
                if(T[j]<=t1 && D[j]<min && D[j]>0)
                {
                    min=D[j];
                    k=j;
                }
            }
            if(D[k]>t)
            {
                D[k]-=t;
                t1+=t;
            }
            else if(D[k]>0)
            {
                C[k]=t1+D[k];
                t1+=D[k];
                D[k]=0;
            }
            if(!D[k])
            {
                if(!C[k])
                    C[k]=t1;
            }
            // display(D, n);
            // display(C, n);
            flag=1;
        }
    }
    if(flag)
        goto loop;
}