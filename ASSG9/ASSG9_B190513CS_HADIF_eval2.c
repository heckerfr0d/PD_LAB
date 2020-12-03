#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct node{
    int key;
    struct node *left, *right, *p;
} *node;

typedef struct bst{
    node root;
} *tree;

node createNode(int);
tree combine1(tree, int, tree);
tree combine2(tree, tree);
node min(node);
node max(node);
int delete(tree, node);
void transplant(tree, node, node);
void insert(tree, node);
void inOrder(tree);


int main()
{
    tree T1 = (tree)malloc(sizeof(tree));
    tree T2 = (tree)malloc(sizeof(tree));
    tree T = (tree)malloc(sizeof(tree));
    T1->root = T2->root = NULL;
    int i, k;
    char c, c1[100], c2[100];
    fgets(c1, 100, stdin);
    fgets(c2, 100, stdin);
    for(i=0;c1[i];i++)
    {
        if(isdigit(c1[i]))
        {
            int num = 0;
            while(isdigit(c1[i]))
                num = num*10 + (c1[i++] - '0');
            insert(T1, createNode(num));
        }
    }
    for(i=0;c2[i];i++)
    {
        if(isdigit(c2[i]))
        {
            int num = 0;
            while(isdigit(c2[i]))
                num = num*10 + (c2[i++] - '0');
            insert(T2, createNode(num));
        }
    }
    T = combine2(T1, T2);
    inOrder(T);
    printf("\n");
    return 0;
}

node createNode(int c)
{
    node x = (node)malloc(sizeof(struct node));
    x->key = c;
    x->left = NULL;
    x->right = NULL;
    x->p = NULL;
    return x;
}

void insert(tree T, node x)
{
    node y = NULL, t = T->root;
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

tree combine1(tree T1, int k, tree T2)
{
    tree T = (tree)malloc(sizeof(tree));
    T->root = createNode(k);
    T->root->left = T1->root;
    if(T1->root)
        T1->root->p = T->root;
    T->root->right = T2->root;
    if(T2->root)
        T2->root->p = T->root;
    T1->root = NULL;
    T2->root = NULL;
    return T;
}

node min(node x)
{
    node t = x;
    while(t->left)
        t = t->left;
    return t;
}

void transplant(tree T, node x, node y)
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

int delete(tree T, node x)
{
    if(!x)
        return -1;
    if(!x->left)
        transplant(T, x, x->right);
    else if(!x->right)
        transplant(T, x, x->left);
    else
    {
        node y = min(x->right);
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
    free(x);
    return k;
}

node max(node x)
{
    node t = x;
    while(t->right)
        t = t->right;
    return t;
}

tree combine2(tree T1, tree T2)
{
    int k;
    if(T1->root)
        k = delete(T1, max(T1->root));
    else
        k = delete(T2, min(T2->root));
    return combine1(T1, k, T2);
}

void inOrder(tree T)
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
