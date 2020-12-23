#include<stdio.h>

void visit_ward(int*, int*, int, int);
void display(int*, int);
void get_inspection_time(int*, int);

int main()
{
    int n, t;
    scanf("%d", &n);
    int D[n], C[n];
    get_inspection_time(D, n);
    scanf("%d", &t);
    visit_ward(D, C, n, t);
    display(C, n);
    return 0;
}

void get_inspection_time(int *D, int n)
{
    for(int i=0;i<n;i++)
        scanf("%d", D+i);
}

void display(int *C, int n)
{
    for(int i=0;i<n;i++)
        printf("%d ", C[i]);
    printf("\n");
}

void visit_ward(int *D, int *C, int n, int t)
{
    int nc=0, t1=0;
    while(nc<n)
    {
        for(int i=0;i<n;i++)
        {
            if(D[i]>t)
            {
                D[i]-=t;
                t1+=t;
            }
            else if(D[i]>0)
            {
                C[i]=t1+D[i];
                t1+=t;
                D[i]=0;
                nc++;
            }
        }
    }
}