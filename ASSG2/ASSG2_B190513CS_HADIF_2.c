#include<stdio.h>

int fact(int);

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", fact(n));
    return 0;
}

int fact(int n)
{
    if(n<2)
        return 1;
    else
        return n*fact(n-1);
}