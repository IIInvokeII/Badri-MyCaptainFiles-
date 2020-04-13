#include<stdio.h>
int main()
{
    //initialization of variables
    int choice=0,i=0,j=0;
    //according to the question, Gigabyte is Byte's love interest and he wanted our help to build stairs to get her down from a window
    printf("Quick! Gigabyte has to come down! Choose your staircase!");
    printf("\nChoice of Stairs \n1.Complete Triangle \n2.Angled");
    printf("\nEnter your choice: ");
    scanf("%d",&choice);
    //two different types of stairs through for loops
    if(choice==1)
    {
        for(i=0;i<6;i++)
        {
            for(j=0;j<=i;j++)
                printf("01");
            printf("\n");
        }
    }
    else if(choice==2)
    {
        for(i=0;i<6;i++)
        {
            for(j=0;j<i;j++)
                printf("  ");
            printf("01\n");
        }
    }
    else
    {
        printf("\nInvalid Choice."); //error handling code
    }
    return 0;
}
