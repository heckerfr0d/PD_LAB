#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct stack{
    int *a;
    int top;
} *stack;

int evaluatePostFix(char*);
int stackEmpty(stack);
void push(stack, int);
int pop(stack);
int getsize(char*);

int main()
{
    char s[100];
    scanf("%[^\n]", s);
    printf("%d\n", evaluatePostFix(s));
    return 0;
}

int evaluatePostFix(char *s)
{
    stack op = (stack)malloc(sizeof(stack));
    op->a = (int*)malloc(getsize(s)*sizeof(int));
    op->top = -1;
    for(int i=0;s[i];i++)
    {
        if(s[i]==' ')
            continue;
        else if(isdigit(s[i]))
        {
            int num =0;
            while(isdigit(s[i]))
                num = num*10 + (s[i++] - '0');
            push(op, num);
        }
        else
        {
            int v2 = pop(op), v1 = pop(op);
            switch(s[i])
            {
            case '+':
                push(op, v1+v2);
                break;
            case '-':
                push(op, v1-v2);
                break;
            case '*':
                push(op, v1*v2);
                break;
            case '/':
                push(op, v1/v2);
            }
        }
    }
    return pop(op);
}

int stackEmpty(stack S)
{
    if(S->top==-1)
        return 1;
    return 0;
}

void push(stack S, int k)
{
    S->a[++S->top] = k;
}

int pop(stack S)
{
    if(!stackEmpty(S))
        return S->a[S->top--];
    return -1;
}

int getsize(char *s)
{
    int i = 0, size = 0;
    while(s[i])
        if(isdigit(s[i++]))
            size++;
    return size;
}