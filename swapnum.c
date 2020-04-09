#include<stdio.h>
#include<conio.h>
int main()
{
  int a=24,b=19;
  printf("a has %d",a);
  printf("b has %d",b);
  a=a+b;
  b=a-b;
  a=a-b;
  printf("Swapping numbers now....");
  printf("a now has %d",a);
  printf("b now has %d",b);
  return 0;
}
