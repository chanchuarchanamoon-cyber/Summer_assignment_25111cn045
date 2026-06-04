#include <stdio.h>
#include <math.h>
int fibo(int n){
    if (n==0) return 0;
    if(n==1) return 1;
    if(n>0) return int fibo=fibo(n-1)+fibo(n-2);
}
int main(){
    int n;
    printf("Enter any number");
    scanf("%d",&n);
    printf("Fibonacci series is %d",fibo(n));
    return 0;
}