#include<stdio.h>
#include<conio.h>     //for getch()
#include<stdlib.h>     //for clearing screen

struct employee     //structure initialization
{
    int no;
    char name[20];
    char dept[20];
    int salary;
}emp[20];     //array of structures

int c=0;     //counting variable for number of elements
void add()     //function to add an element to the array
{
    printf("\nEnter Employee No: "); scanf("%d",&emp[c].no);
    printf("\nEnter Employee Name: "); scanf("%s",emp[c].name);
    printf("\nEnter Employee Department: "); scanf("%s",emp[c].dept);
    printf("\nEnter Employee Salary: "); scanf("%d",&emp[c].salary);
    c++;     //incrementing the count variables
}
void display()     //function to display details
{
    int n=0;
    printf("\nEnter the index no. to view: "); scanf("%d",&n);
    if(n<0 || n>c-1)      //error handling condition
    {
        printf("Invalid index.");
        getch();
    }
    else
    {
        printf("\nEmployee No: %d",emp[n].no);
        printf("\nEnter Employee Name: %s",emp[n].name);
        printf("\nEnter Employee Department: %s",emp[n].dept);
        printf("\nEnter Employee Salary: %d",emp[n].salary);
        getch();
    }

}

void menu()
{
    int choice=0;
    while(choice!=3)      //loop until exit condition
    {      
    system("cls");
    printf("\nEMPLOYEE DETAILS");
    printf("\n%d details present.",c);
    printf("\n1.Add Details");
    printf("\n2.View Details");
    printf("\n3.Exit");
    printf("\nEnter your choice: ");
    scanf("%d",&choice);
    if(choice==1)
    {
        if(c==19)     //error condition
            printf("Cannot Add More Elements.");
        else
            add();     //function call
    }
    else if(choice==2)
        display();     //function call
    else if(choice==3)
        printf("Application Terminated");
    else
        printf("Invalid Choice.");
    }
}

int main()     //main function
{
    menu();     //calling menu function
    return 0;
}

