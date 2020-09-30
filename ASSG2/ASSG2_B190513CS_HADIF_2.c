#include<stdio.h>

long fact(int);

int main()
{
    int n;
    scanf("%d", &n);

    if(n>=0)
        printf("%ld\n", fact(n));
    else if(n>20)
        printf("This program currently only supports values from 0-20.\n");
    else
        printf("Factorial is not defined for negative integers.\n");

    return 0;
}

long fact(int n)
{
    return n<2 ? 1 : n*fact(n-1);
}