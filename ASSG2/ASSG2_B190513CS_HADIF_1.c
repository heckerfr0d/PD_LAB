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
    if(n>=0)
        return n;
    else
        return -n;
}

int gcd(int a, int b)
{
    if(!a&&!b)
        return -1;
    else if(!a)
        return b;
    else if(!b)
        return a;
    else if(a>b)
        return gcd(a%b, b);
    else
        return gcd(a, b%a);
}