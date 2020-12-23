#include <stdio.h>
#include <stdlib.h>

typedef struct bstnode{
    int key;
    struct bstnode *left, *right, *p;
} *bst;

typedef struct bst{
    bst root;
    struct bst* next;
} *set;

typedef struct ll{
    set head;
} *list;

bst createNode(int);
void insertSet(list, set);
bst search(set, int);
set findSet(list, int);
void deleteSet(list, set);
void insert(set, bst);
void transplant(set, bst, bst);
void delete(set, bst);
void PoMod(set, set);
void mergeSets(list, int, int);
void inOrder(set);
void printCollection(list);

int main()
{
    char c;
    int n, a, i;
    list l = (list)malloc(sizeof(struct ll));
    l->head = NULL;
    do
    {
        set s = (set)malloc(sizeof(struct bst));
        s->next = NULL;
        s->root = NULL;
        scanf("%c", &c);
        switch (c)
        {
        case 'i':
            scanf("%d", &n);
            for(i=0;i<n;i++)
            {
                scanf("%d", &a);
                insert(s, createNode(a));
            }
            insertSet(l, s);
            break;
        case 'd':
            scanf("%d", &a);
            set s = findSet(l, a);
            deleteSet(l, s);
            break;
        case 'f':
            scanf("%d", &a);
            findSet(l, a);
            break;
        case 'm':
            scanf("%d%d", &a, &i);
            mergeSets(l, a, i);
            break;
        case 'p':
            printCollection(l);
        }
    } while (c!='e');
    return 0;
}

bst createNode(int c)
{
    bst x = (bst)malloc(sizeof(struct bstnode));
    x->key = c;
    x->left = NULL;
    x->right = NULL;
    x->p = NULL;
    return x;
}

void insertSet(list C, set S)
{
    S->next = C->head;
    C->head = S;
}

bst search(set T, int k)
{
    bst t = T->root;
    while(t && t->key!=k)
    {
        if(k>t->key)
            t = t->right;
        else
            t = t->left;
    }
    return t;
}

set findSet(list C, int k)
{
    set t = C->head;
    while(t)
    {
        bst f = search(t, k);
        if(f)
            break;
        t = t->next;
    }
    if(t)
    {
        printf("%d\n", t->root->key);
        return t;
    }
    printf("-1\n");
    return NULL;
}

void deleteSet(list C, set t)
{
    if(!t)
        return;
    if(!t->next)
    {
        set u = C->head, p = NULL;
        while(u->next)
        {
            p = u;
            u = u->next;
        }
        p->next = NULL;
        free(t);
    }
    else
    {
        t->root = t->next->root;
        set v = t->next;
        t->next = v->next;
        v->next = NULL;
        free(v);
    }
}

void insert(set T, bst x)
{
    if(!x)
        return;
    bst y = NULL, t = T->root;
    while(t)
    {
        y = t;
        if(x->key>t->key)
            t = t->right;
        else
            t = t->left;
    }
    if(!y)
        T->root = x;
    else if(x->key<y->key)
        y->left = x;
    else
        y->right = x;
    x->p = y;
    x->left = x->right = NULL;
}

void transplant(set T, bst x, bst y)
{
    if(!x->p)
        T->root = y;
    else if(x==x->p->left)
        x->p->left = y;
    else
        x->p->right = y;
    if(y)
        y->p = x->p;
}

void delete(set T, bst x)
{
    if(!x)
        return;
    if(!x->left)
        transplant(T, x, x->right);
    else if(!x->right)
        transplant(T, x, x->left);
    else
    {
        bst y = x->right;
        while(y->left)
            y = y->left;
        if(y->p!=x)
        {
            transplant(T, y, y->right);
            y->right = x->right;
            y->right->p = y;
        }
        transplant(T, x, y);
        y->left = x->left;
        y->left->p = y;
    }
}

void PoMod(set T, set S)
{
    if(!T->root)
        return;
    struct bst t;
    t.root = T->root->left;
    PoMod(&t, S);
    t.root = T->root->right;
    PoMod(&t, S);
    t.root = T->root;
    delete(T, T->root);
    insert(S, t.root);
}

void mergeSets(list C, int k1, int k2)
{
    set s1 = findSet(C, k1);
    set s2 = findSet(C, k2);
    PoMod(s2, s1);
    deleteSet(C, s2);
}

void inOrder(set T)
{
    if(!T->root)
        return;
    struct bst t;
    t.root = T->root->left;
    inOrder(&t);
    printf("%d ", T->root->key);
    t.root = T->root->right;
    inOrder(&t);
}

void printCollection(list C)
{
    set t = C->head;
    while(t)
    {
        inOrder(t);
        printf("\n");
        t = t->next;
    }
}

