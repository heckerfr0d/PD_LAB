#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct str
{
    char word[8];
} string;

typedef struct imDb
{
    int n;
    string *M_id;
    float *rating;
} mDb;

int m, h;

void heapsort(mDb);
void buildminheap(mDb);
void minheapify(mDb, int);
void merge(mDb*);
void strswap(string*, string*);
void swap(float*, float*);

int main()
{
    int i, j;
    scanf("%d%d", &m, &h);
    mDb A[m];
    for(i=0;i<m;i++)
    {
        scanf("%d", &A[i].n);
        A[i].M_id = (string*)malloc(A[i].n*sizeof(string));
        A[i].rating = (float*)malloc((A[i].n+1)*sizeof(float));
        A[i].rating[A[i].n] = -1;
        for(j=0;j<A[i].n;j++)
            scanf("%s %f", A[i].M_id[j].word, A[i].rating+j);
        heapsort(A[i]);
    }
    merge(A);
    return 0;
}

void heapsort(mDb A)
{
    int i;
    buildminheap(A);
    for(i=A.n-1;i>0;i--)
    {
        swap(A.rating, A.rating+i);
        strswap(A.M_id, A.M_id+i);
        A.n--;
        minheapify(A, 0);
    }
}

void buildminheap(mDb A)
{
    int i, k = (A.n-(A.n%h ? A.n%h : h))/h;
    for(i=k;i>=0;i--)
        minheapify(A, i);
}

void minheapify(mDb A, int i)
{
    int j;
    int smallest = i;
    for(j=2*i+1;j<=2*i+h;j++)
    {
        if(j<A.n && A.rating[j]<A.rating[smallest])
            smallest = j;
    }
    if(smallest!=i)
    {
        swap(A.rating+smallest, A.rating+i);
        strswap(A.M_id+smallest, A.M_id+i);
        minheapify(A, smallest);
    }
}

void merge(mDb A[])
{
    int i, j[m], n1=0, k=0, large=0;
    for(i=0;i<m;i++)
    {
        n1+=A[i].n;
        j[i]=0;
    }
    mDb B[n1];
    for(i=0;i<n1;i++)
    {
        B[i].M_id = (string*)malloc(sizeof(string));
        B[i].rating = (float*)malloc(sizeof(float));
    }
    while(k<n1)
    {
        for(i=m-1;i>=0;i--)
        {
            if(A[i].rating[j[i]]>=A[large].rating[j[large]])
                large=i;
        }
        strcpy(B[k].M_id->word, A[large].M_id[j[large]].word);
        *B[k].rating = A[large].rating[j[large]];
        k++;
        j[large]++;
    }
    for(i=0;i<n1;i++)
        printf("\n%s %.2f", B[i].M_id->word, *B[i].rating);
}

void strswap(string *A, string *B)
{
    char t;
    int i;
    for(i=4;i<7;i++)
    {
        t = A->word[i];
        A->word[i] = B->word[i];
        B->word[i] = t;
    }
}

void swap(float *a, float *b)
{
    float t = *a;
    *a = *b;
    *b = t;
}