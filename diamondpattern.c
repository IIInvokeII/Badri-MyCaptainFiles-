#include<stdio.h>
int main() //program to display diamond
{
    int i=0,j=0,n=0;
    printf("\nEnter the maximum stars you want to see in a row: ");
    scanf("%d",&n);
    printf("\nBehold ! A Diamond !\n");
    //for loop for upper half
    for(i=0;i<n;i++)  
    {
        for(j=0;j<n-i;j++)
            printf(" ");
        for(j=0;j<=i;j++)
            printf("* ");
        printf("\n");
    }
    //for loop for lower half
    for(i=n-2;i>=0;i--)
    {
        for(j=0;j<n-i;j++)
            printf(" ");
        for(j=0;j<=i;j++)
            printf("* ");
        printf("\n");
    }
    return 0;
}
