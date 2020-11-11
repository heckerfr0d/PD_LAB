#include<stdio.h>

int fibonacci(int n)
{
    return n<=1?n:fibonacci(n-1)+fibonacci(n-2);
}

int main()
{
    for(int i=0;i<10;i++)
        printf("%d ", fibonacci(i));
    printf("\n");
    return 0;
}