//program to check if a number is prime or not using recursion
#include<stdio.h>
int primecheck(int n,int i);     //function prototype

int main()
{
        int n=0,check=0,i=2;
        printf("Enter the number: ");
        scanf("%d",&n);
        check=primecheck(n,i);     //function call
        if(check==1)      //if return value is true
            printf("%d is a prime number.",n);
        else      //if return value is false
            printf("%d is not a prime number.",n);
        return 0;
}

int primecheck(int n, int i )
{
    if(n==0 || n==1)     // 0 and 1 are not prime numbers
        return 0;
    if(n==2)     //2 is prime
        return 1;
    if(n%i==0)     //n is divided by i to check if divisible
        return 0;
    if(i*i>n)      //at this point, there was no number n could be divided by to be composite, so it is prime
        return 1;
    return primecheck(n,i+1);    //recursive call with incremented i to check the divisibility
}
