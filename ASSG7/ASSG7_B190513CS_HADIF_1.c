#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int top, n;
    int *A;
} *stack;

int stackEmpty(stack);
int stackFull(stack);
int push(stack, int);
int pop(stack);

int main()
{
    stack S;
    char c;
    int x, n;
    scanf("%d", &S->n);
    S->top = -1;
    S->A = (int*)malloc(S->n*sizeof(int));
    do
    {
        scanf("%c", &c);
        switch (c)
        {
        case 'i':
            scanf("%d", &x);
            push(S, x);
            break;
        case 'd':
            printf("%d\n", pop(S));
            break;
        case 'e':
            printf("%d\n", stackEmpty(S));
        }
    } while (c!='t');
    return 0;
}

int stackEmpty(stack S)
{
    if(S->top==-1)
        return -1;
    return 1;
}

int stackFull(stack S)
{
    if(S->top==S->n)
        return 1;
    return 0;
}

int push(stack S, int k)
{
    if(!stackFull(S))
        return S->A[++S->top] = k;
    return -1;
}

int pop(stack S)
{
    if(stackEmpty(S)!=-1)
        return S->A[S->top--];
    return -1;
}