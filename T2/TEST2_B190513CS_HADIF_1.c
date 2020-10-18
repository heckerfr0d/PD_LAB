#include<stdio.h>
#include<string.h>

typedef struct imDb
{
    char M_id[8];
    float rating;
} mDb;

void store_Db(mDb*, int);
int list_Db(mDb*, int);
void popular_rating(mDb*, int);
float best_r(mDb*, mDb*, mDb*, int, int);
int max(int*, int);

int main()
{
    char c;
    int n, s;
    scanf("%d", &n);
    mDb E[n+1], H[n+1], M[n+1];
    E[n].rating = H[n].rating = M[n].rating = -1;
    do
    {
        scanf("%c", &c);
        switch(c)
        {
        case 's':
            scanf("%d", &s);
            if(s==1)
                store_Db(E, n);
            else if(s==2)
                store_Db(H, n);
            else if(s==3)
                store_Db(M, n);
            break;
        case 'p':
            scanf("%d", &s);
            if(s==1)
                popular_rating(E, n);
            else if(s==2)
                popular_rating(H, n);
            else if(s==3)
                popular_rating(M, n);
            break;
        case 'b':
            scanf("%d", &s);
            best_r(E, H, M, n, s);
            break;
        case 'l':
            scanf("%d", &s);
            if(s==1)
                list_Db(E, n);
            else if(s==2)
                list_Db(H, n);
            else if(s==3)
                list_Db(M, n);
        }
    } while (c!='t');
    
    return 0;
}

void store_Db(mDb *Db, int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%s %f", Db[i].M_id, &Db[i].rating);
    }
}

int list_Db(mDb *Db, int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%s ", Db[i].M_id);
        printf("%.2f\n", Db[i].rating);
        if(Db[i+1].rating==Db[i].rating && Db[n].rating>0 && Db[n].rating<10)
            n++;
    }
    return n;
}

void popular_rating(mDb *Db, int n)
{
    int C[n], i, j;
    for(i=0;i<n;i++)
        C[i]=1;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(Db[j].rating==Db[i].rating)
                C[i]++;
        }
    }
    int m = max(C, n);
    for(i=0;i<n;i++)
        if(C[i]==m)
            printf("%.2f\n", Db[i].rating);
}

float best_r(mDb *E, mDb *H, mDb *M, int n, int r)
{
    int i=0, j=0, k=0, m=0, n1=3*n;
    mDb Db[n1];
    while(m<n1)
    {
        if(E[i].rating>=H[j].rating && E[i].rating>=M[k].rating)
        {
            strcpy(Db[m].M_id, E[i].M_id);
            Db[m].rating = E[i].rating;
            m++;
            i++;
        }
        else if(H[j].rating>=E[i].rating && H[j].rating>=M[k].rating)
        {
            strcpy(Db[m].M_id, H[j].M_id);
            Db[m].rating = H[j].rating;
            m++;
            j++;
        }
        else
        {
            strcpy(Db[m].M_id, M[k].M_id);
            Db[m].rating = M[k].rating;
            m++;
            k++;
        }
    }
    r = list_Db(Db, r)-1;
    printf("%.2f\n", Db[r].rating);
}

int max(int *C, int n)
{
    int i, max=C[0];
    for(i=0;i<n;i++)
        if(C[i]>max)
            max = C[i];
    return max;
}