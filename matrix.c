//program to enter, display and calculate sum of diagonals for a matrix
#include<stdio.h>
int newmat(int arr[3][3]);     //function prototype

int main()
{
    //1. initializing the variables needed
    int arr[3][3]={{12,23,34},{45,56,67},{78,89,90}};      //default initialization. tried initializing this way and it worked!
    int i=0,j=0,choice=0;
    int *p=arr;      //initializing pointer arrays
    //2. taking input for all elements
    printf("\n1.Enter New Matrix \n2.Use Default Matrix");      //choice to enter your own matrix or use the default one
    printf("\nEnter your Choice: "); scanf("%d",&choice);
    if(choice==1)
        newmat(arr);     //function call
    else if(choice!=2)
        printf("\nInvalid Choice. Using default matrix.");
    else
        printf("\nUsing Default Matrix.");
    //3. printing elements using pointers
    printf("\nThe Matrix is: ");
    for(i=0;i<3;i++)
    {
        printf("\n");
        for(j=0;j<3;j++)
        {
            printf("%d  ",*p);
            p++;
        }
    }
    //4. printing the sum of the diagonals
    printf("\nSum of the Diagonals: ");
    int sum1=0,sum2=0;
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
        {
            if(i==j)     //i==j is the general condition for primary diagonal in a matrix
                sum1=sum1+arr[i][j];
        }
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
        {
            if(i+j==2)     //condition for secondary diagonal
                sum2=sum2+arr[i][j];
        }
    printf("\nSum of Diagonal 1: %d",sum1);
    printf("\nSum of Diagonal 2: %d",sum2);
    return 0;
}

int newmat(int arr[3][3])      //function to input elements into matrix
{
    int i=0,j=0;
    printf("\nEnter the elements of the matrix: ");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("\nEnter element [%d,%d]: ",i+1,j+1); scanf("%d",&arr[i][j]);
        }
    }
    return arr;
}
