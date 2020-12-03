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
    scanf("%d", &k);
    T = combine1(T1, k, T2);
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
