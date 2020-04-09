#include<stdio.h>
int main()
{
  int a=24,b=19;      //initialising numbers
  printf("a has %d",a);    // displaying current values
  printf("b has %d",b);
  a=a+b;     //swapping 
  b=a-b;
  a=a-b;
  printf("Swapping numbers now....");
  printf("a now has %d",a);       //displaying swapped values
  printf("b now has %d",b);
  return 0;
}
