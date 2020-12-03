#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct customer{
    int acc_no;
    char cust_name[80];
    float balance;
} *C;

void read_and_store(C, int);
void sort_records(C, int);
int search_record(C, int);
void display(C, int);

int main()
{
    char c;
    int n, a;
    C c1;
    do
    {
        scanf("%c", &c);
        switch (c)
        {
        case 'r':
            scanf("%d", &n);
            c1 = (C)malloc(n*sizeof(struct customer));
            read_and_store(c1, n);
            break;
        case 's':
            sort_records(c1, n);
            break;
        case 'f':
            scanf("%d", &a);
            printf("%d\n", search_record(c1, a));
            break;
        case 'd':
            display(c1, n);
        }
    } while (c!='e');
    return 0;
}

void read_and_store(C c1, int n)
{
    for(int i=0;i<n;i++)
        scanf("%d%s%f", &c1[i].acc_no, c1[i].cust_name, &c1[i].balance);
}

void sort_records(C c1, int n)
{
    int i, j, ta;
    float tb;
    char tc[80];
    for(i=1;i<n;i++)
    {
        ta = c1[i].acc_no;
        tb = c1[i].balance;
        strcpy(tc, c1[i].cust_name);
        j = i-1;
        while(j>=0 && c1[j].acc_no>ta)
        {
            c1[j+1].acc_no = c1[j].acc_no;
            c1[j+1].balance = c1[j].balance;
            strcpy(c1[j+1].cust_name, c1[j].cust_name);
            j--;
        }
        c1[j+1].acc_no = ta;
        c1[j+1].balance = tb;
        strcpy(c1[j+1].cust_name, tc);
    }
}

int search_record(C c1, int a)
{
    for(int i=0;c1[i].acc_no;i++)
        if(c1[i].acc_no==a)
            return i;
    return -1;
}
void display(C c1, int n)
{
    for(int i=0;i<n;i++)
        printf("%d %s %.2f\n", c1[i].acc_no, c1[i].cust_name, c1[i].balance);
}