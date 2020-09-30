#include<stdio.h>
#include<math.h>

int main()
{
    int b, d=0, i=0;
    printf("Enter a binary number: ");
    scanf("%d", &b);
    while(b>0)
    {
        if(b%10)
            d+=pow(2, i);
        b/=10;
        i++;
    }
    printf(" The equivalent decimal number: %d\n", d);
    return 0;
}