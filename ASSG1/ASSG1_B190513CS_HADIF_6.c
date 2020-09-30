#include<stdio.h>

int count(int*, int, int);

int majorityElement(int*, int );


int main()
{
    int i, n;
    scanf("%d", &n);
    int a[n];
    for(i=0;i<n;i++)
        scanf("%d", &a[i]);

    printf("%d\n", majorityElement(a, n));
    return 0;
}

int count(int *a, int n, int x)
{
    int i, c=0;
    for(i=0;i<n;i++)
        if(a[i]==x)
            c++;
    return c;
}

int majorityElement(int* nums, int numsSize)
{
    int i, suf=0;
    int c;
    for(i=0;i<numsSize;i++)
    {
        if(suf==0)
        c=nums[i];    
        nums[i]==c?suf++:suf--;
    }
    if(count(nums, numsSize, c)>numsSize/2)
        return c;
    else
        return -1;
}