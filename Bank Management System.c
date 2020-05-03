//NOTE : PASSWORD IS "qwerty". 

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

void menu();     //prototype for menu

struct date     //structure to hold date
{
    int d,m,y;
};

struct bank     //main structure
{
    char name[30];
    int acc_no;
    float amt;
    struct date dob;
}add,b;

int l=0,i=0;     //global variables for looping

void new_acc()     //function to create a new account
{
    FILE *fp,*fc; int acc=0,test=0;
    fc=fopen("count.dat","r");       //this file is exclusively for keeping track of the amount of accounts and retaining it.
    fscanf(fc,"%d",&l);
    fclose(fc);
    printf("\nEnter account number to check availability: "); scanf("%d",&acc);
    fp=fopen("Bank.dat","r");
    if(l==0)
        test=1;
    for(i=0;i<=l-1;i++)     //for reading into file
    {
            fscanf(fp,"%s",b.name);
            fscanf(fp,"%d",&b.acc_no);
            fscanf(fp,"%f",&b.amt);
            fscanf(fp,"%d/%d/%d",&b.dob.d,&b.dob.m,&b.dob.y);
            if(b.acc_no==acc)      //checks if the account number already exists
            {
                printf("\nAccount Number already exists, please try a different number."); getch(); menu(); break;
            }
    }
    test=1;     //after checking all records, test=1 is initialised. if record already exists, function goes back to menu
    fclose(fp);
    if(test==1)
    {
        fp=fopen("Bank.dat","a");
        printf("\nAccount Number available. Enter details: \n");
        printf("Enter name: "); scanf("%s",add.name); fprintf(fp,"%s",add.name); fprintf(fp,"\n");
        add.acc_no=acc; fprintf(fp,"%d",add.acc_no); fprintf(fp,"\n");
        printf("Enter amount: $"); scanf("%f",&add.amt); fprintf(fp,"%f",add.amt); fprintf(fp,"\n");
        printf("Enter today's date: "); scanf("%d/%d/%d",&add.dob.d,&add.dob.m,&add.dob.y);
        fprintf(fp,"%d/%d/%d",add.dob.d,add.dob.m,add.dob.y); fprintf(fp,"\n");
        fclose(fp);
        l++;
        FILE *fc;
        fc=fopen("count.dat","w");     //updating number of records
        fprintf(fc,"%d",l);
        fclose(fc);
        getch();
    }
}

void edit_acc()      //function to edit existing accounts
{
    FILE *fp,*newfile,*fc;
    int acc_check=0,test=0;
    fc=fopen("count.dat","r");
    fscanf(fc,"%d",&l);
    fclose(fc);
    int lc=l;
    printf("\nEnter the account number of the file to edit: "); scanf("%d",&acc_check);
    fp=fopen("Bank.dat","r");
    newfile=fopen("Temp.dat","a");
    //next few lines are basically for deleting the record, and if a record is deleted successfully a new one is added 
    for(i=0;i<lc;i++)
    {
        fscanf(fp,"%s",add.name);
        fscanf(fp,"%d",&add.acc_no);
        fscanf(fp,"%f",&add.amt);
        fscanf(fp,"%d/%d/%d",&add.dob.d,&add.dob.m,&add.dob.y);
        if(add.acc_no!=acc_check)
        {
            fprintf(newfile,"%s",add.name); fprintf(newfile,"\n");
            fprintf(newfile,"%d",add.acc_no); fprintf(newfile,"\n");
            fprintf(newfile,"%f",add.amt); fprintf(newfile,"\n");
            fprintf(newfile,"%d/%d/%d",add.dob.d,add.dob.m,add.dob.y); fprintf(newfile,"\n");
        }
        else
        {
            FILE *fc;
            l-=1;
            fc=fopen("count.dat","w");
            fprintf(fc,"%d",l);
            fclose(fc);
            test=1;
        }
    }
    fclose(newfile); fclose(fp);
    if(test==1)
    {
        fp=fopen("Bank.dat","a");
        printf("Enter name: "); scanf("%s",add.name); fprintf(fp,"%s",add.name); fprintf(fp,"\n");
        add.acc_no=acc_check; fprintf(fp,"%d",add.acc_no); fprintf(fp,"\n");
        printf("Enter amount: $"); scanf("%f",&add.amt); fprintf(fp,"%f",add.amt); fprintf(fp,"\n");
        printf("Enter today's date: "); scanf("%d/%d/%d",&add.dob.d,&add.dob.m,&add.dob.y);
        fprintf(fp,"%d/%d/%d",add.dob.d,add.dob.m,add.dob.y); fprintf(fp,"\n");
        fclose(fp);
    }
    else
    {
        printf("\nNo such record exists to modify."); getch(); menu();
    }
}

void transact()      //function for transactions
{
    float w=0.0;
    FILE *fp,*fc;
    int acc_check=0,choice=0,test=0;
    fc=fopen("count.dat","r");
    fscanf(fc,"%d",&l);
    fclose(fc);
    int lc=0;
    printf("\nEnter the account number for transaction: "); scanf("%d",&acc_check);
    fp=fopen("Bank.dat","r");
    for(i=0;i<l;i++)
    {
        fscanf(fp,"%s",add.name);
        fscanf(fp,"%d",&add.acc_no);
        fscanf(fp,"%f",&add.amt);
        fscanf(fp,"%d/%d/%d",&add.dob.d,&add.dob.m,&add.dob.y);
        lc=sizeof(add.name) + 20;      //this is used to return the file pointer to the beginning of the record to modify values
        if(add.acc_no==acc_check)
        {
            fseek(fp,-lc,SEEK_CUR);     //going back "lc" bytes from current position, effectively to the beginning of the record
            printf("\n1. Withdraw\n2. Deposit");
            printf("\nEnter your choice"); scanf("%d",&choice);
            if(choice==1)
            {
                printf("\nEnter the amount to withdraw: "); scanf("%f",&w);
                w=(-w);
            }
            if(choice==2)
            {
                printf("\nEnter amount to deposit: "); scanf("%f",&w);
            }
            fprintf(fp,"%s",add.name); fprintf(fp,"\n");
            fprintf(fp,"%d",add.acc_no); fprintf(fp,"\n");
            fprintf(fp,"%f",add.amt+w); fprintf(fp,"\n");     //amount is updated
            fprintf(fp,"%d/%d/%d",add.dob.d,add.dob.m,add.dob.y); fprintf(fp,"\n");
            fclose(fp);
            test=1;
            break;
        }
    }
    if(test==1)
    {
        printf("\nTransaction successful!");
    }
    else
    {
        printf("\nAccount not found.");
    }
}

void check()     //to check individual account
{
    FILE *fp,*fc;
    fc=fopen("count.dat","r");
    fscanf(fc,"%d",&l);
    fclose(fc);
    int i=0;
    int choice=0,acc_check,test=0;
    char name_check[30]="";
    fp=fopen("Bank.dat","r");
    if(fp==NULL)
    {
        printf("\nNo record was added."); getch();
    }
    else
    {
        printf("\nSearch by 1. Account Number 2. Name");
        printf("\nEnter your choice: "); scanf("%d",&choice);
        if(choice==1)
        {
            printf("\nEnter account number to find: "); scanf("%d",&acc_check);
             for(i=0;i<l;i++)
             {
                 fscanf(fp,"%s",add.name);
                 fscanf(fp,"%d",&add.acc_no);
                 fscanf(fp,"%f",&add.amt);
                 fscanf(fp,"%d/%d/%d",&add.dob.d,&add.dob.m,&add.dob.y);
                 if(add.acc_no==acc_check)
                 {
                     test=1;
                     printf("\nAccount No: %d",add.acc_no);
                     printf("\nName: %s",add.name);
                     printf("\nAmount: %f",add.amt);
                     printf("\nDOB: %d/%d/%d",add.dob.d,add.dob.m,add.dob.y);
                     getch();
                     break;
                 }
             }
             if(test==0)
             {
                 printf("\nRecord Not Found."); getch();
             }
        }
        else if(choice==2)
        {
            printf("\nEnter Account Name to find: "); scanf("%s",name_check);
             for(i=0;i<l;i++)
             {
                 fscanf(fp,"%s",add.name);
                 fscanf(fp,"%d",&add.acc_no);
                 fscanf(fp,"%f",&add.amt);
                 fscanf(fp,"%d/%d/%d",&add.dob.d,&add.dob.m,&add.dob.y);
                 if(strcmp(add.name,name_check)==0)
                 {
                     test=1;
                     printf("\nAccount No: %d",add.acc_no);
                     printf("\nName: %s",add.name);
                     printf("\nAmount: %f",add.amt);
                     printf("\nDOB: %d/%d/%d",add.dob.d,add.dob.m,add.dob.y);
                     getch();
                     break;
                 }
             }
             if(test==0)
             {
                 printf("\nRecord Not Found.");
                 getch();
             }
        }
        else
        {
            printf("\nInvalid Choice."); getch();
        }
    }
    fclose(fp);
}

void del()
{
    FILE *fp,*newfile,*fc;
    int test=0,lc=0;
    fc=fopen("count.dat","r");
    fscanf(fc,"%d",&l);
    fclose(fc);
    lc=l;
    int acc_check=0;
    printf("\nEnter the account number to search for and delete: "); scanf("%d",&acc_check);
    fp=fopen("Bank.dat","r+");
    newfile=fopen("Temp.dat","a+");
    for(i=0;i<lc;i++)     //traversing the file
    {
        fscanf(fp,"%s",add.name);
        fscanf(fp,"%d",&add.acc_no);
        fscanf(fp,"%f",&add.amt);
        fscanf(fp,"%d/%d/%d",&add.dob.d,&add.dob.m,&add.dob.y);     //reading the elements
        if(add.acc_no!=acc_check)     //checking if the account is to be deleted, if not write into new file
        {
            fprintf(newfile,"%s",add.name); fprintf(newfile,"\n");
            fprintf(newfile,"%d",add.acc_no); fprintf(newfile,"\n");
            fprintf(newfile,"%f",add.amt); fprintf(newfile,"\n");
            fprintf(newfile,"%d/%d/%d",add.dob.d,add.dob.m,add.dob.y); fprintf(newfile,"\n");
        }
        else      //if account is to be deleted it is simply not written
        {
            FILE *fc;
            l-=1;
            fc=fopen("count.dat","w");       //file counter reduced by one since we are deleting
            fprintf(fc,"%d",l);
            fclose(fc);
            test=1;
        }
    }
    fclose(newfile);
    fclose(fp);
    remove("Bank.dat");
    rename("Temp.dat","Bank.dat");     //removing and renaming the files
    if(test==1)
    {
        printf("\nRecord successfully deleted."); getch();
    }
    else
    {
        printf("\nNo such record exists to delete."); getch();
    }
}

void viewall()      //function to display all records at once
{
    FILE *fp,*fc;
    int j=0;
    fc=fopen("count.dat","r");
    fscanf(fc,"%d",&l);
    fclose(fc);
    fp=fopen("Bank.dat","r");
    printf("\n\nACCOUNT NO.\t\tNAME\t\tAMOUNT\t\t\tDATE\n");
    for(i=0;i<l;i++)
    {
        printf("\n");
        for(j=0;j<15;j++)
            printf("-----");
        fscanf(fp,"%s",add.name);
        fscanf(fp,"%d",&add.acc_no);
        fscanf(fp,"%f",&add.amt);
        fscanf(fp,"%d/%d/%d",&add.dob.d,&add.dob.m,&add.dob.y);
        printf("\n%d\t\t\t%s\t\t%f\t\t%d/%d/%d\n",add.acc_no,add.name,add.amt,add.dob.d,add.dob.m,add.dob.y);
        for(j=0;j<15;j++)
            printf("-----");
    }
    fclose(fp);
    getch();
}

void menu()     //menu function
{
    FILE *fc;
    fc=fopen("count.dat","r");
    fscanf(fc,"%d",&l);
    fclose(fc);
    int choice;
    system("cls");
    system("color 1");
    printf("\nl=%d",l);
    printf("\nBANK MANAGEMENT SYSTEM");
    printf("\n1. Create New Account");
    printf("\n2. Update Information of Existing Account");
    printf("\n3. Perform Transaction");
    printf("\n4. Check Details of an Existing Account");
    printf("\n5. Remove Existing Account");
    printf("\n6. View List of Accounts");
    printf("\n7. Exit");
    printf("\nEnter your choice(1-7): "); scanf("%d",&choice);
    switch(choice)
    {
        case 1: new_acc(); menu(); break;
        case 2: edit_acc(); menu(); break;
        case 3: transact(); break;
        case 4: check(); menu(); break;
        case 5: del(); menu(); break;
        case 6: viewall(); menu(); break;
        case 7: printf("\n\nThank You for using Bank Management System.\n\n");exit(0); break;
        default: printf("Invalid Choice."); getch();menu();
    }
}

int main()
{
    int c=0; char password[10]="qwerty";
    do
    {
        char pass[10]="";
        system("cls");
        printf("\nEnter password: ");
        scanf(" %s",pass);
        if(strcmp(pass,password)==0)
        {
            system("cls");
            printf("Password is correct !");
            getch();
            menu();
            break;
        }
        else
        {
            printf("\nWrong Password.");
            printf("\nEnter 1 (Try Again) or 0 (Exit): ");
            scanf("%d",&c);
        }
    }while(c==1);
    return 0;
}
