#include<stdio.h>
#include<string.h>

struct emp_deets
{
    char name[32];
    int salary;
    int leave;
    int workpd;
};

void insert(struct emp_deets*, int);
void print_noincrement(struct emp_deets*, int);
void print_finalsalary(struct emp_deets*, int);
void print_workperday(struct emp_deets*, int, int);
int computeDeductions(struct emp_deets*, char*, int);

int main()
{
    struct emp_deets emp[10];
    char ename[32];
    char c;
    int i=0;
    do
    {
        int w;
        scanf("%c", &c);
        switch(c)
        {
        case 'r':
            insert(emp, i);
            i++;
            break;
        case 'i':
            print_noincrement(emp, i);
            break;
        case 'f':
            print_finalsalary(emp, i);
            break;
        case 'w':
            scanf("%d", &w);
            print_workperday(emp, w, i);
            break;
        case 'c':
            scanf(" %s", ename);
            printf("%s %d\n", ename, computeDeductions(emp, ename, i));
            break;
        }
    }   while(c!='t');
    return 0;
}

void insert(struct emp_deets *emp, int i)
{
    scanf(" %s%d%d", emp[i].name, &emp[i].leave, &emp[i].workpd);
    emp[i].salary = 30000 - (emp[i].leave>5 ? (emp[i].leave-5)*1000 : 0);
}

void print_noincrement(struct emp_deets *emp, int n)
{
    int i;
    for(i=0;i<n;i++)
        if(emp[i].workpd<8)
            printf("%s %d\n", emp[i].name, emp[i].salary);
}

void print_finalsalary(struct emp_deets *emp, int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        emp[i].salary += emp[i].workpd>=8 ? emp[i].workpd<10 ? 50 : emp[i].workpd==10 ? 100 : 150 : 0;
        printf("%s %d\n", emp[i].name, emp[i].salary);
    }
}

void print_workperday(struct emp_deets *emp, int w, int n)
{
    int i=0;
    for(i=0;i<n;i++)
        if(emp[i].workpd==w)
            printf("%s %d\n", emp[i].name, emp[i].salary);
}

int computeDeductions(struct emp_deets *emp, char *ename, int n)
{
    int i;
    for(i=0;i<n;i++)
        if(!strcmp(ename, emp[i].name))
            return emp[i].leave>5 ? (emp[i].leave-5)*1000 : 0;
    return -1;
}