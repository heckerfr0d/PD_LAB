#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
    set t = S;
    t->next = C->head;
    C->head = t;
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

void deleteSet(list C, int k)
{
    set t = findSet(C, k);
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
        // free(t);
    }
    else
    {
        t->root = t->next->root;
        set v = t->next;
        t->next = v->next;
        v->next = NULL;
        // free(v);
    }
}

void insert(set T, bst x)
{
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
}

bst min(bst x)
{
    bst t = x;
    while(t->left)
        t = t->left;
    return t;
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

int delete(set T, bst x)
{
    if(!x)
        return -1;
    if(!x->left)
        transplant(T, x, x->right);
    else if(!x->right)
        transplant(T, x, x->left);
    else
    {
        bst y = min(x->right);
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
    int k = x->key;
    // free(x);
    return k;
}

void mergeSets(list C, int k1, int k2)
{
    set s1 = findSet(C, k1);
    set s2 = findSet(C, k2);
    while(s2->root)
    {
        bst t = min(s2->root);
        insert(s1, t);
        delete(s2, t);
    }
    if(!s2)
        return;
    if(!s2->next)
    {
        set u = C->head, p = NULL;
        while(u->next)
        {
            p = u;
            u = u->next;
        }
        p->next = NULL;
        // free(s2);
    }
    else
    {
        s2->root = s2->next->root;
        set v = s2->next;
        s2->next = v->next;
        v->next = NULL;
        // free(v);
    }
}

void inOrder(set T)
{
    if(!T->root)
        return;
    struct bst t;
    if(T->root->left)
    {
        t.root = T->root->left;
        inOrder(&t);
    }
    printf("%d ", T->root->key);
    if(T->root->right)
    {
        t.root = T->root->right;
        inOrder(&t);
    }
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


int main()
{
    char c;
    int n, a, i;
    list l = (list)malloc(sizeof(struct ll));
    struct bst s[10000];
    int k=0;
    l->head = NULL;
    do
    {
        s[k].root = NULL;
        s[k].next = NULL;
        scanf("%c", &c);
        switch (c)
        {
        case 'i':
            scanf("%d", &n);
            for(i=0;i<n;i++)
            {
                scanf("%d", &a);
                insert(&s[k], createNode(a));
            }
            insertSet(l, &s[k]);
            ++k;
            break;
        case 'd':
            scanf("%d", &a);
            deleteSet(l, a);
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

