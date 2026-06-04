#include <stdio.h>
#include <math.h>
int SumDigits(int n){
    int sum=0;
    int rem;
    if(n>0)
    return rem=n%10,sum=sum+rem,n=n/10;
}
int main(){
    int sum=0;
int n;
printf("Enter any number");
scanf("%d",&n);
printf("Sum of digits is %d is %d",n,sum);
return 0;
}