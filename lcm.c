//program to find the LCM of two numbers using recursion
#include<stdio.h>
int gcd(int a,int b);     //function prototype

int main()
{
    int a=0,b=0,c=0;
    printf("Enter the 1st number: "); scanf("%d",&a);
    printf("Enter the 2nd number: "); scanf("%d",&b);
    c=a*b/gcd(a,b);     //formula: a*b = lcm(a,b) * gcd(a,b)
    printf("The LCM of %d and %d : %d",a,b,c);
    return 0;
}

int gcd(int a,int b)     //function definition
{
    if(a==0)
        return b;
    return gcd(b%a,a);  //takes all cases; gcd(15,5) becomes gcd(5,15)--gcd(0,5)--returns 5
}
