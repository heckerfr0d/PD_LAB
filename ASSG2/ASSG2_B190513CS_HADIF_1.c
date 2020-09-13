#include<stdio.h>

int abs(int);
int gcd(int, int);

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", gcd(abs(a), abs(b)));
    return 0;
}

int abs(int n)
{
    return n>=0?n:-n;
}

int gcd(int a, int b)
{
    return !a&&!b?-1:!a?b:!b?a:a>b?gcd(a%b, b):gcd(a, b%a);
}