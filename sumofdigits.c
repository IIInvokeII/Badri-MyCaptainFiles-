//program to find the sum of digits recursively
#include<stdio.h>
int sumofdigits(int n);     //function prototype

int main()
{
  int n=0,sum=0;
  printf("Enter the number: ");
  scanf("%d",&n);     //taking input
  sum=sumofdigits(n);   //function call and storing the return value in another variable
  printf("The sum of the digits of %d = %d",n,sum);     //displaying sum of digits
  return 0;
}

int sumofdigits(int n)     //function definition
{
  if(n==0)
    return 0;
  else
    return (n%10 + sumofdigits(n/10));
}
