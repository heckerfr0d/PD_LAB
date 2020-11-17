#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int key;
    struct node *left, *right, *p;
} *node;

typedef struct bst{
    node root;
} *tree;

node createNode(int);
node search(tree, int);
node min(node);
int delete(tree, node);
void insert(tree, node);
void transplant(tree, node, node);
void inOrder(tree);
void preOrder(tree);
void postOrder(tree);

int main()
{
    tree T = (tree)malloc(sizeof(tree));
    T->root = NULL;
    char c;
    do
    {
        scanf("%c", &c);
        int k;
        switch(c)
        {
        case 'a':
            scanf("%d", &k);
            insert(T, createNode(k));
            break;
        case 'd':
            scanf("%d", &k);
            printf("%d\n", delete(T, search(T, k)));
            break;
        case 's':
            scanf("%d", &k);
            search(T, k) ? printf("1\n") : printf("-1\n");
            break;
        case 'i':
            inOrder(T);
            printf("\n");
            break;
        case 'p':
            preOrder(T);
            printf("\n");
            break;
        case 't':
            postOrder(T);
            printf("\n");
        }
    } while (c != 'e');
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

node search(tree T, int k)
{
    node t = T->root;
    while(t && t->key!=k)
    {
        if(k>t->key)
            t = t->right;
        else
            t = t->left;
    }
    return t;
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

void preOrder(tree T)
{
    if(!T->root)
        return;
    struct bst t;
    printf("%d ", T->root->key);
    if(T->root->left)
    {
        t.root = T->root->left;
        preOrder(&t);
    }
    if(T->root->right)
    {
        t.root = T->root->right;
        preOrder(&t);
    }
}

void postOrder(tree T)
{
    if(!T->root)
        return;
    struct bst t;
    if(T->root->left)
    {
        t.root = T->root->left;
        postOrder(&t);
    }
    if(T->root->right)
    {
        t.root = T->root->right;
        postOrder(&t);
    }
    printf("%d ", T->root->key);
}