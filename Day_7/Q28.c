#include <stdio.h>
#include <math.h>
int ReverseOfNumbers(int n,int r){
    int ld;
    ld=n%10;
    n=n/10;
    r=r*10;
    r=+ld;
    if(n>0) return r+ld;
}
int main(){
    int r;
    int n;
    printf("Enter any number");
    scanf("%d",&n);
    printf("Reversed number is %d=%d",r);
    return 0;
}
