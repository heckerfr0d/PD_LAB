#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct cstack{
    char *a;
    int top;
} *cstack;

typedef struct node{
    char data;
    struct node *left;
    struct node *right;
} *node;

typedef struct expTree{
    node root;
} *tree;

typedef struct nstack{
    node *a;
    int top;
} *nstack;

node createNode(char, node, node);
node constructTree(char*);
node npop(nstack);
void inOrder(tree);
void npush(nstack, node);
int nstackEmpty(nstack);
int ngetsize(char*);

int cgetsize(char*);
int isp(char);
int icp(char);
void cpush(cstack, char);
char cpop(cstack);
int cstackEmpty(cstack);

int main()
{
    FILE *fin = fopen("input.txt", "r");
    if(!fin)
        exit(1);
    tree T = (tree)malloc(sizeof(tree));
    char s[100];
    while(fgets(s, 100, fin))
    {
        T->root = constructTree(s);
        inOrder(T);
        printf("\n");
    }
    fclose(fin);
    return 0;
}

node constructTree(char* s)
{
    nstack N = (nstack)malloc(sizeof(nstack));
    N->a = (node*)malloc(ngetsize(s+2)*sizeof(node));
    cstack C = (cstack)malloc(sizeof(cstack));
    C->a = (char*)malloc(cgetsize(s+2)*sizeof(char));
    N->top = C->top = -1;
    int i = 2;
    while(s[i]!=';')
    {
        if(s[i]=='(')
            cpush(C, s[i]);
        else if(isalpha(s[i]))
            npush(N, createNode(s[i], NULL, NULL));
        else if(s[i]==')')
        {
            while(C->a[C->top]!='(')
            {
                node a2 = npop(N);
                node a1 = npop(N);
                npush(N, createNode(cpop(C), a1, a2));
            }
            cpop(C);
        }
        else if(icp(s[i])>isp(C->a[C->top]))
            cpush(C, s[i]);
        else
        {
            while(icp(s[i])<=isp(C->a[C->top]))
            {
                node a2 = npop(N);
                node a1 = npop(N);
                npush(N, createNode(cpop(C), a1, a2));
            }
            cpush(C, s[i]);
        }
        i++;
    }
    while(!cstackEmpty(C))
    {
        node a2 = npop(N);
        node a1 = npop(N);
        npush(N, createNode(cpop(C), a1, a2));
    }
    node t = npop(N);
    free(N->a);
    free(C->a);
    free(N);
    free(C);
    return createNode('=', createNode(s[0], NULL, NULL), t);
}

void inOrder(tree T)
{
    if(!T->root)
        return;
    struct expTree t;
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

node createNode(char c, node lc, node rc)
{
    node x = (node)malloc(sizeof(node));
    x->data = c;
    x->left = lc;
    x->right = rc;
    return x;
}

int nstackEmpty(nstack S)
{
    if(S->top==-1)
        return 1;
    return 0;
}

void npush(nstack S, node k)
{
    S->a[++S->top] = k;
}

node npop(nstack S)
{
    if(!nstackEmpty(S))
        return S->a[S->top--];
    return NULL;
}

int cstackEmpty(cstack S)
{
    if(S->top==-1)
        return 1;
    return 0;
}

void cpush(cstack S, char k)
{
    S->a[++S->top] = k;
}

char cpop(cstack S)
{
    if(!cstackEmpty(S))
        return S->a[S->top--];
    return -1;
}

int isp(char c)
{
    switch(c)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '(':
        return 0;
    }
}

int icp(char c)
{
    switch(c)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '(':
        return 3;
    }
}

int ngetsize(char *s)
{
    int i = 0, size = 0;
    while(s[i])
        if(isalpha(s[i++]))
            size++;
    return size;
}

int cgetsize(char *s)
{
    int i = 0, size = 0;
    while(s[i])
        if(!isalnum(s[i++]))
            size++;
    return size;
}