#include <stdio.h>
#include <math.h>
int fibo(int n){
    if(n==0) return 0;
    if(n==1) return 1;
    if(n>0) return fibo(n-1)+fibo(n-2);
}
int main(){
int n;
printf("Enter any number");
scanf("%d",&n);
if(n<0){
    printf("Series does not exist");
}
else{
    printf("Series is %d=%d",n,fibo);
}
return 0;
}
