#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    int modelNo, price;
    char name[4];
    struct node *left, *right, *p;
} *node;

typedef struct bst{
    node root;
} *tree;

node createNode(int, char*, int);
node search(tree, int);
node min(node);
int delete(tree, node);
void insert(tree, node);
void transplant(tree, node, node);
void inOrder(tree);
void print(node);
void modify(tree, int, int);

int main()
{
    tree T = (tree)malloc(sizeof(tree));
    T->root = NULL;
    char c;
    do
    {
        scanf("%c", &c);
        int n, p;
        char s[4];
        switch(c)
        {
        case 'a':
            scanf("%d%s%d", &n, s, &p);
            insert(T, createNode(n, s, p));
            break;
        case 'd':
            scanf("%d", &n);
            delete(T, search(T, n));
            break;
        case 's':
            scanf("%d", &n);
            print(search(T, n));
            break;
        case 'i':
            inOrder(T);
            printf("\n");
            break;
        case 'm':
            scanf("%d%d", &n, &p);
            modify(T, n, p);
        }
    } while (c != 'e');
    return 0;
}

node createNode(int c, char* s, int p)
{
    node x = (node)malloc(sizeof(struct node));
    x->modelNo = c;
    x->price = p;
    strcpy(x->name, s);
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
        if(x->modelNo>t->modelNo)
            t = t->right;
        else
            t = t->left;
    }
    if(!y)
        T->root = x;
    else if(x->modelNo<y->modelNo)
        y->left = x;
    else
        y->right = x;
    x->p = y;
}

node search(tree T, int k)
{
    node t = T->root;
    while(t && t->modelNo!=k)
    {
        if(k>t->modelNo)
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
    if(!x);
    else if(!x->left)
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
    print(x);
    free(x);
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
    print(T->root);
    if(T->root->right)
    {
        t.root = T->root->right;
        inOrder(&t);
    }
}

void modify(tree T, int n, int p)
{
    node x = search(T, n);
    x->price = p;
}

void print(node x)
{
    if(x)
        printf("%d %s %d\n", x->modelNo, x->name, x->price);
    else
        printf("-1\n");
}