#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list
{
    float cgpa;
    char name[32];
} L;

int n1, n2;

void insert(L[], int, L);
void combine(L[], L[]);
void print(L[]);

int main()
{
    int i;
    scanf("%d%d", &n1, &n2);
    L L1[n1+n2], L2[n1];
    for(i=0;i<n1;i++)
        scanf("%s %f", L1[i].name, &L1[i].cgpa);
    for(i=0;i<n2;i++)
        scanf("%s %f", L2[i].name, &L2[i].cgpa);
    combine(L1, L2);
    print(L1);
    return 0;
}

void insert(L L1[], int pos, L L2)
{
    if(pos<=n1+n2)
    {
        L1[pos].cgpa = L2.cgpa;
        strcpy(L1[pos].name, L2.name);
    }
}

void combine(L L1[], L L2[])
{
    int i = n1 - 1, j = n2 - 1, n = n1 + n2 - 1;
    while(j>=0)
    {
        if(L2[j].cgpa>=L1[i].cgpa)
            insert(L1, n--, L2[j--]);
        else
            insert(L1, n--, L1[i--]);
    }
}

void print(L L1[])
{
    int i;
    for(i=0;i<n1+n2;i++)
        printf("\n%s %.2f", L1[i].name, L1[i].cgpa);
}