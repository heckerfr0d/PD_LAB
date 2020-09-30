#include<stdio.h>
#include<math.h>

int reverse(int);

int main()
{
    int n;
    scanf("%d", &n);
    n=reverse(n);

    printf("%d\n", n);

    return 0;
}

int reverse(int n)
{
    if(!n)
        return 0;
    int dig = (int)log10(n);
    return (n%10)*pow(10,dig) + reverse(n/10);
}