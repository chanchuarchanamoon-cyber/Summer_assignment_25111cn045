#include <stdio.h>
int main(){
    int n;
    printf("Enter any number");
    scanf("%d",&n);
    int sum=0,rem;
    while(n>0){
        rem=n%10;
        sum=sum+rem;
        n=n/10;
    }
    printf("Sum of digits %d" is %d",n,sum);
    return 0;
}
