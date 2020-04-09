#include<stdio.h>
int main()
{
  int marks=0;
  printf("Enter the marks of the student: ");
  //taking input from user
  scanf("%d",&marks);     
  //beginning of if-else ladder
  if(marks<=100 && marks>=85)     
    printf("Student got Grade A.");
  else if(marks<85 && marks >=70)
    printf("Student got Grade B.");
  else if(marks<70 && marks >=55)
    printf("Student got Grade C.");
  else if(marks<55 && marks >=40)
    printf("Student got Grade D.");
  else if(marks<40 && marks >=0)
    printf("Student got Grade E.");
  //to handle error cases if input is not between 0-100  
  else                                      
    printf("Not within the valid range of marks.");  
  //end of if-else ladder
  return 0;
}
