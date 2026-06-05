#include <stdio.h>
#include <math.h>
int factorial(int n){
    if(n==1) return 0;
    if(n>0) return n*factorial(n-1);
}
int main(){
int n;
printf("Enter any number");
scanf("%d",&n);
if(n>0){
    printf("Factorial of number is %d=%d" ,n,factorial(n));

}
return 0;
}