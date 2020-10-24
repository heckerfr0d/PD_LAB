#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
    float *cgpa;
    int length;
} L;

void insert(L, int, float);
void combine(L, L);
void print(L);

int main()
{
    int n1, n2, i;
    scanf("%d%d", &n1, &n2);
    L L1, L2;
    L1.cgpa = (float*)malloc((n1+n2)*sizeof(float));
    L2.cgpa = (float*)malloc(n2*sizeof(float));
    L1.length = n1+n2;
    L2.length = n2;
    for(i=0;i<n1;i++)
        scanf("%f", L1.cgpa+i);
    for(i=0;i<n2;i++)
        scanf("%f", L2.cgpa+i);
    combine(L1, L2);
    print(L1);
    return 0;
}

void insert(L L1, int pos, float val)
{
    if(pos<=L1.length)
        L1.cgpa[pos] = val;
}

void combine(L L1, L L2)
{
    int i = L1.length - L2.length - 1, j = L2.length - 1, n = L1.length - 1;
    while(j>=0)
    {
        if(L2.cgpa[j]>=L1.cgpa[i])
            insert(L1, n--, L2.cgpa[j--]);
        else
            insert(L1, n--, L1.cgpa[i--]);
    }
}

void print(L L1)
{
    int i;
    for(i=0;i<L1.length;i++)
        printf("%.2f ", L1.cgpa[i]);
}