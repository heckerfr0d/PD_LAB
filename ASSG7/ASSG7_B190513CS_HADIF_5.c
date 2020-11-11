#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct string
{
    int top, n;
    char *A;
} *str;

int stackEmpty(str);
int stackFull(str);
char push(str, char);
char pop(str);
int isPalindrome(str, char*);

int main()
{
    str S;
    S = (str)malloc(sizeof(str));
    char c[100];
    scanf("%s", c);
    S->n = strlen(c);
    S->A = (char*)malloc((S->n/2)*sizeof(char));
    S->top = -1;
    printf("%d\n", isPalindrome(S, c));
    return 0;
}

int stackEmpty(str S)
{
    if(S->top==-1)
        return -1;
    return 1;
}

int stackFull(str S)
{
    if(S->top==S->n)
        return 1;
    return 0;
}

char push(str S, char k)
{
    if(!stackFull(S))
        return S->A[++S->top] = k;
    return -1;
}

char pop(str S)
{
    if(stackEmpty(S)!=-1)
        return S->A[S->top--];
    return -1;
}

int isPalindrome(str S, char *c)
{
    int i;
    for(i=0;i<S->n/2;i++)
        push(S, c[i]);
    i += S->n%2;
    while(i<S->n)
    {
        if(c[i++]!=pop(S))
            return 0;
    }
    return 1;
}