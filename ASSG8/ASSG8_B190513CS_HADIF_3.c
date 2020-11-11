#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct node{
    char data;
    struct node *left;
    struct node *right;
} *node;

typedef struct expTree{
    node root;
} *tree;

typedef struct stack{
    node *a;
    int top;
} *stack;

node createNode(char, node, node);
node constructTree(char*);
node pop(stack);
void inOrder(tree);
void preOrder(tree);
void postOrder(tree);
void push(stack, node);
int stackEmpty(stack);
int getsize(char*);

int main()
{
    tree T = (tree)malloc(sizeof(tree));
    T->root = NULL;
    char s[100], c;
    do
    {
        scanf("%c", &c);
        switch(c)
        {
        case 'e':
            scanf("%s", s);
            T->root = constructTree(s);
            break;
        case 'i':
            inOrder(T);
            printf("\n");
            break;
        case 'p':
            preOrder(T);
            printf("\n");
            break;
        case 's':
            postOrder(T);
            printf("\n");
        }
    } while (c != 't');
    return 0;
}

node constructTree(char* s)
{
    stack S = (stack)malloc(sizeof(stack));
    S->a = (node*)malloc(getsize(s)*sizeof(node));
    S->top = -1;
    for(int i=0;s[i];i++)
    {
        if(isalpha(s[i]))
            push(S, createNode(s[i], NULL, NULL));
        else
        {
            node rc = pop(S), lc = pop(S);
            push(S, createNode(s[i], lc, rc));
        }
    }
    return pop(S);
}

void inOrder(tree T)
{
    if(!T->root)
        return;
    struct expTree t = *T;
    if(T->root->left)
    {
        t.root = T->root->left;
        inOrder(&t);
    }
    printf("%c", T->root->data);
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
    struct expTree t = *T;
    printf("%c", T->root->data);
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
    struct expTree t = *T;
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
    printf("%c", T->root->data);
}

node createNode(char c, node lc, node rc)
{
    node x = (node)malloc(sizeof(node));
    x->data = c;
    x->left = lc;
    x->right = rc;
    return x;
}

int stackEmpty(stack S)
{
    if(S->top==-1)
        return 1;
    return 0;
}

void push(stack S, node k)
{
    S->a[++S->top] = k;
}

node pop(stack S)
{
    if(!stackEmpty(S))
        return S->a[S->top--];
    return NULL;
}

int getsize(char *s)
{
    int i = 0, size = 0;
    while(s[i])
        if(isalpha(s[i++]))
            size++;
    return size;
}