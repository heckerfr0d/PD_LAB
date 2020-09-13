#include<stdio.h>

int fact(int);

int main()
{
    int n;
    scanf("%d", &n);

    if(n>=0)
        printf("%d\n", fact(n));
    else
        printf("Factorial for negative integers is not defined.\n");

    return 0;
}

int fact(int n)
{
    return n<2?1:n*fact(n-1);
}