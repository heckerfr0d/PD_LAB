#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct stack{
    char *a;
    int top;
} *stack;

char* inFixToPostFix(char*);
int isp(char);
int icp(char);
void push(stack, char);
char pop(stack);
int stackEmpty(stack);
int getsize(char*);

int main()
{
    char s[100];
    scanf("%s", s);
    printf("%s", inFixToPostFix(s));
    return 0;
}

char* inFixToPostFix(char *s)
{
    char *s1 = (char*)malloc(strlen(s)*sizeof(char));
    stack op = (stack)malloc(sizeof(struct stack));
    op->a = (char*)malloc(getsize(s)*sizeof(char));
    op->top = -1;
    int i, j = 0;
    for(i=0;s[i];i++)
    {
        if(isalpha(s[i]))
            s1[j++] = s[i];
        else if(s[i]==')')
        {
            while(!stackEmpty(op) && op->a[op->top]!='(')
                s1[j++] = pop(op);
            if(pop(op) != '(')
                exit(1);
        }
        else if(stackEmpty(op) || icp(s[i])>isp(op->a[op->top]))
            push(op, s[i]);
        else
        {
            while(!stackEmpty(op) && icp(s[i])<=isp(op->a[op->top]))
                s1[j++] = pop(op);
            push(op, s[i]);
        }
    }
    while(!stackEmpty(op))
        s1[j++] = pop(op);
    return s1;
}

int stackEmpty(stack S)
{
    if(S->top==-1)
        return 1;
    return 0;
}

void push(stack S, char k)
{
    S->a[++S->top] = k;
}

char pop(stack S)
{
    if(!stackEmpty(S))
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

int getsize(char *s)
{
    int i = 0, size = 0;
    while(s[i])
        if(!isalnum(s[i++]))
            size++;
    return size;
}