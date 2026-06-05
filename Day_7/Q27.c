#include <stdio.h>
int sumOfDigit(int num){
    int rem;
    rem=num%10;
    int sum=rem;
    num=num/10;
    if(num>0) return sum+sumOfDigit(num);
    return sum;
}
int main(){
    int num;
    printf("Enter any number:");
    scanf("%d",num);
    printf("Sum of number is %d=%d",num,sumOfDigit(num));
return 0;
}