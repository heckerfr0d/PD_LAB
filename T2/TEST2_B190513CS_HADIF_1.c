#include<stdio.h>
#include<string.h>

typedef struct imDb
{
    char M_id[8];
    float rating;
} mDb;

void store_Db(mDb*, int);
int list_Db(mDb*, int);
float popular_rating(mDb*, int);
float best_r(mDb*, mDb*, mDb*, int, int);

int main()
{
    char c;
    int n, s;
    scanf("%d", &n);
    mDb E[n+1], H[n+1], M[n+1];
    E[n].rating = H[n].rating = M[n].rating = 0;
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
                printf("%.2f\n", popular_rating(E, n));
            else if(s==2)
                printf("%.2f\n", popular_rating(H, n));
            else if(s==3)
                printf("%.2f\n", popular_rating(M, n));
            break;
        case 'b':
            scanf("%d", &s);
            printf("%.2f\n", best_r(E, H, M, n, s));
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
        scanf("%s %f", Db[i].M_id, &Db[i].rating);
}

int list_Db(mDb *Db, int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%s %.2f\n", Db[i].M_id, Db[i].rating);
        if(Db[i+1].rating==Db[i].rating && Db[n].rating)
            n++;
    }
    return n;
}

float popular_rating(mDb *Db, int n)
{
    int c=1, maxc=1, i;
    float mode = Db[0].rating;
    for(i=0;i<n-1;i++)
    {
        if(Db[i+1].rating==Db[i].rating)
            c++;
        else
        {
            if(c>maxc)
            {
                maxc = c;
                mode = Db[i].rating;
            }
            c = 1;
        }
    }
    return mode;
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
            Db[m++].rating = E[i++].rating;
        }
        else if(H[j].rating>=E[i].rating && H[j].rating>=M[k].rating)
        {
            strcpy(Db[m].M_id, H[j].M_id);
            Db[m++].rating = H[j++].rating;
        }
        else
        {
            strcpy(Db[m].M_id, M[k].M_id);
            Db[m++].rating = M[k++].rating;
        }
    }
    r = list_Db(Db, r)-1;
    return Db[r].rating;
}
