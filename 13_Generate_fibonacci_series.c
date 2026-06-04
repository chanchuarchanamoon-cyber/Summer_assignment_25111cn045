#include <stdio.h>
#include <math.h>
int fibo(int n){
if(n==1) return 1;
if(n==0) return 0;
if(n==2) return fibo(n-1)+fibo(n-2);
}
int main(){
    int l;
    printf("Enter any number");
    scanf("%d",l);
    int a=fibo(l);
    printf("Given number fibonacci series is %d",a);
    return 0;
}
