#include<stdio.h>
#include<string.h>

int find(char*, char*);

int main()
{
    char A[1000], B[500];
    gets(A);
    gets(B);

    int p = find(A, B);
    printf("%d\n", p);

    return 0;
}

int find(char *A, char *B)
{
    int n=strlen(A), m=strlen(B), i, j;

    for(i=0;i<n;i++)
    {
        if(A[i]==B[0])
        {
            for(j=1;j<m;j++)
                if(A[i+j]!=B[j])
                    break;
            if(j==m)
                return i;
        }
    }
    return -1;
}