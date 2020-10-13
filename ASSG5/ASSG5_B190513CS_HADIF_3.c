#include<stdio.h>
#include<stdlib.h>

typedef struct heap{
    int *a;
    int heapsize;
} queue;

int get_next_patient(queue*);
int extract_next_patient(queue*);
void insert_patient(queue*, int);
void change_token_number(queue*, int, int);
void display_queue(queue*);
void min_heapify(queue*, int);
int swap(int*, int*);

int main()
{
    char c;
    queue *q;
    q->a = NULL;
    q->heapsize = 0;
    int j, k;
    do
    {
        scanf("%c", &c);
        switch(c)
        {
        case 'i':
            scanf("%d", &k);
            q->a = (int*)realloc(q->a, (++(q->heapsize))*sizeof(int));
            insert_patient(q, k);
            break;
        case 'e':
            printf("%d\n", extract_next_patient(q));
            break;
        case 'm':
            printf("%d\n", get_next_patient(q));
            break;
        case 'c':
            scanf("%d%d", &j, &k);
            change_token_number(q, j, k);
            break;
        case 'd':
            display_queue(q);
        }
    }   while(c!='s');
    free(q->a);
    return 0;
}

int get_next_patient(queue *Q)
{
    return Q->heapsize ? Q->a[0] : -1;
}

int extract_next_patient(queue *Q)
{
    if(Q->heapsize)
    {
        int min = swap(Q->a, Q->a+--(Q->heapsize));
        min_heapify(Q, 0);
        return min;
    }
    else
        return -1;
}

void insert_patient(queue *Q, int k)
{
    Q->a[Q->heapsize-1] = 1000000;
    change_token_number(Q, Q->heapsize-1, k);
}

void change_token_number(queue *Q, int i, int k)
{
    if(k>Q->a[i])
        printf("Error: Increasing token number angers the patient!\n");
    else
    {
        Q->a[i] = k;
        int v = (i-1)/2;
        while(i>0 && Q->a[v]>Q->a[i])
        {
            swap(Q->a+v, Q->a+i);
            i=v;
            v = (i-1)/2;
        }
    }
}

void display_queue(queue *Q)
{
    int n = Q->heapsize, i;
    while(Q->heapsize)
        printf("%d ", extract_next_patient(Q));
    printf("\n");
    Q->heapsize = n;
    for(i=(Q->heapsize-1)/2;i>=0;i--)
        min_heapify(Q, i);
}

void min_heapify(queue *Q, int i)
{
    int l=2*i+1;
    int smallest = l<Q->heapsize && Q->a[l]<Q->a[i] ? l : i;
    smallest = l+1<Q->heapsize && Q->a[smallest]>Q->a[l+1] ? l+1 : smallest;
    if(smallest!=i)
    {
        swap(Q->a+smallest, Q->a+i);
        min_heapify(Q, smallest);
    }
}

int swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
    return t;
}
