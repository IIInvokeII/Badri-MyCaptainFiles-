//This is a program for entering details into a score sheet, viewing score sheet and viewing all score sheet names
//More details in a score sheet can be added, but due to my poor knowledge of cricket I am unable to do so.

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

struct DATE
{
    int d,m,y;
};

struct cricket      //main structure
{
    char name_comp[30],name_venue[30],team1[30],team2[30],toss[30],results[10];
    int innings;
    struct DATE date;
    int runs[24];
}c;

void menu();          //function protoypes
void new_sheet();
void view_sheet();
void line()      //function to display line instantly
{
    int i=0;
    printf("\n");
    for(i=0;i<40;i++)
        printf("===");
    printf("\n");
}

void new_sheet()      //function to add new score sheet
{
    system("cls");
    int test=0; int t=0; char ch;
    char extn[]=".dat";
    char file[30]="",temp[30]="";
    printf("\nEnter name of the score sheet to store in file, without extension. ");
    printf("\nFor example, \"scores1\". Please enter file name: ");
    scanf("%s",temp);          //taking input for a custom file name
    strcpy(file,strcat(temp,extn));     //adding the file extension
    strcpy(temp,"");       //emptying the string
    FILE *fp;
    fp=fopen("filenames.txt","r");      //this file is exclusively used to store the names of the score sheets
    while(fscanf(fp,"%s",temp)!=EOF)
    {
        if(strcmp(file,temp)==0)
        {
            test=1;       //if the filename already exists, this condition is set
        }
    }
    fclose(fp);
    if(test==1)
    {
        printf("\nFile name already exists.");
    }
    else
    {
        fp=fopen("filenames.txt","a");
        fprintf(fp,"%s",file); fprintf(fp,"\n");       //the following lines are for taking input
        fclose(fp);
        fp=fopen(file,"w");
        printf("\nEnter The Name of the Competition: "); scanf("%s",c.name_comp);
        fprintf(fp,"%s",c.name_comp); fprintf(fp,"\n");
        printf("\nEnter The Name of the Venue: "); scanf("%s",c.name_venue);
        fprintf(fp,"%s",c.name_venue); fprintf(fp,"\n");
        printf("\nEnter Team 1 Name: "); scanf("%s",c.team1);
        fprintf(fp,"%s",c.team1); fprintf(fp,"\n");
        printf("\nEnter Team 2 Name: "); scanf("%s",c.team2);
        fprintf(fp,"%s",c.team2); fprintf(fp,"\n");
        do
        {
            printf("\nWhich Team won the toss, %s or %s?(1/2): ",c.team1,c.team2); scanf(" %c",&ch);
            if(ch=='1')
            {
                strcpy(c.toss,c.team1); break;
            }
            else if(ch=='2')
            {
                strcpy(c.toss,c.team2); break;
            }
            else
                printf("\nInvalid Option.");
        }while(t);
        fprintf(fp,"%s",c.toss); fprintf(fp,"\n");
        do
        {
            printf("\nWhat did %s pick, Batting(1) or Bowling(2)?(1/2): ",c.toss); scanf(" %c",&ch);
            if(ch=='1')
            {
                strcpy(c.results,"Batting"); break;
            }
            else if(ch=='2')
            {
                strcpy(c.results,"Bowling"); break;
            }
            else
                printf("\nInvalid Option.");
        }while(t);
        fprintf(fp,"%s",c.results); fprintf(fp,"\n");
        printf("\nEnter The Number of Innings Covered: "); scanf("%d",&c.innings);
        fprintf(fp,"%d",c.innings); fprintf(fp,"\n");
        printf("\nEnter The Date of the Match: "); scanf("%d/%d/%d", &c.date.d, &c.date.m, &c.date.y);
        fprintf(fp,"%d/%d/%d", c.date.d, c.date.m, c.date.y); fprintf(fp,"\n");
        printf("\nEnter the runs of each batsman in %s: ",c.team1);
        for(t=0;t<11;t++)       //the first 11 indices(0-10) store runs for team 1
        {
            printf("\nBatsman %d: ",t+1); scanf("%d",&c.runs[t]); fprintf(fp,"%d",c.runs[t]); fprintf(fp,"\n");
            c.runs[22]+=c.runs[t];
        }
        printf("\nEnter the runs of each batsman in %s: ",c.team2);
        for(t=11;t<22;t++)      /indices(11-21) store runs for team 2
        {
            printf("\nBatsman %d: ",t-10); scanf("%d",&c.runs[t]); fprintf(fp,"%d",c.runs[t]); fprintf(fp,"\n");
            c.runs[23]+=c.runs[t];
        }
        fprintf(fp,"%d",c.runs[22]); fprintf(fp,"\n");      //index 22 stores total runs for team 1
        fprintf(fp,"%d",c.runs[23]); fprintf(fp,"\n");      //index 23 stores total runs for team 2
        fclose(fp);
    }
    getch();
}

void view_sheet()      //function to view the full score sheet 
{
    system("cls");
    int test=0;
    char file[30]="",temp[30]="",extn[]=".dat";
    printf("\nEnter the name of the score sheet without extension to view: ");
    scanf("%s",file);
    strcat(file,extn);
    FILE *fp;
    fp=fopen("filenames.txt","r");
    while(fscanf(fp,"%s",temp)!=EOF)
    {
        if(strcmp(file,temp)==0)
        {
            test=1;       //if file exists, this condition is set
        }
    }
    fclose(fp);
    if(test==1)
    {
        int i=0;
        fp=fopen(file,"r");
        fscanf(fp,"%s %s %s %s %s %s %d %d/%d/%d", c.name_comp, c.name_venue, c.team1, c.team2, c.toss, c.results, &c.innings, &c.date.d, &c.date.m, &c.date.y);
        line();
        printf("\nCompetition Name: %s",c.name_comp);
        printf("\nVenue: %s\t\tDate: %d/%d/%d",c.name_venue,c.date.d, c.date.m, c.date.y);
        printf("\nMatch: %s Vs. %s",c.team1,c.team2);
        printf("\n%s won the toss, and chose %s.",c.toss,c.results);
        printf("\nThe Match lasted for %d innings.",c.innings);
        line();
        for(i=0;i<24;i++)
        {
            fscanf(fp,"%d",&c.runs[i]);
        }
        printf("\n%s\t\t\t||%s",c.team1,c.team2);
        for(i=0;i<11;i++)
        {
            printf("\nBatsman %d: %d\t\t||Batsmen %d: %d",i+1,c.runs[i],i+1,c.runs[i+11]);
        }
        line();
        printf("\n%s scored %d runs and %s scored %d runs.",c.team1,c.runs[22],c.team2,c.runs[23]);
        if(c.runs[22]>c.runs[23])
        {
            printf("\n%s wins by %d runs.",c.team1,(c.runs[22]-c.runs[23]));
        }
        else if(c.runs[22]<c.runs[23])
        {
            printf("\n%s wins by %d runs.",c.team2,(c.runs[23]-c.runs[22]));
        }
        else
            printf("\nIt was a draw.");
        fclose(fp);
    }
    else
    {
        printf("\nNo such score sheet exists.");
    }
    getch();
}

void view_all()      //function to view the file names of the score sheets
{
    system("cls");
    line();
    char file[30]=""; int i=1;
    FILE *fp;
    fp=fopen("filenames.txt","r");
    while(fscanf(fp,"%s",file)!=EOF)
    {
        printf("\n\t%d. %s",i,file);
        i++;
    }
    fclose(fp);
    line();
    getch();
}

void menu()      //menu function 
{
    char choice;
    do
    {
        system("cls");
        printf("\nCricket Score Sheet");
        printf("\n1. Create New Sheet");
        printf("\n2. View Existing Sheet");
        printf("\n3. View Filenames storing Score Sheets");
        printf("\n4. Exit");
        printf("\nEnter Your Choice(1/2/3): "); choice=getche(); getch();
        switch(choice)
        {
            case '1': new_sheet(); menu(); break;
            case '2': view_sheet(); menu(); break;
            case '3': view_all(); menu(); break;
            case '4': printf("\n\nThank You for using this application.\n\n"); exit(0); break;
            default: printf("\nInvalid Choice."); getch();
        }
    }while(choice);
}

int main()      //main function 
{
    system("color 2");
    menu();
    return 0;
}
