#include<stdio.h>
//program to read contents from a file and print in reverse order, and copying contents from one file to another
int main()
{
    char ch[30]="",input[30]="",ch2[30]="";     //declaring character arrays
    int i=0,l=0;     //integer variables for looping and file size
    FILE *fp1,*fp2;     //file pointers
    fp1=fopen("test1.txt","w+");     //opening file in a mode that allows both reading and writing
    fp2=fopen("test2.txt","w+");
    printf("Enter text to write into file: "); gets(input);     //user inputs
    fprintf(fp1,"%s",input);     //writing input into file
    fseek(fp1,0,SEEK_END);       //seeking out 0 bytes from the end of the file
    l=ftell(fp1);      //gives the total number of bytes
    printf("\nSize of the file: %d",l);
    fseek(fp1,0,SEEK_SET);     //seeking out 0 bytes from the beginning of the file
    for(i=l-1;i>=0;i--)
    {
        ch[i]=fgetc(fp1);     //storing the character in a reverse index format
        fputc(ch[i],fp2);     //writing into the new file at the same time
    }
    printf("\n%s",ch);     //displaying the contents in the file in reverse order
    fseek(fp2,0,SEEK_SET);     //fp2 has traversed the test2.txt file, so we are going back to the beginning
    for(i=0;i<l;i++)
    {
        ch2[i]=fgetc(fp2);     //reading character by character from the new file
    }
    printf("\nThe text in the new file is: %s",ch2);      //displaying content from the new file
    fclose(fp2);
    fclose(fp1);     //closing files in a nested manner
    return 0;
}
