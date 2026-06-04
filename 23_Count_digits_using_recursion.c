#include <stdio.h>
#include <math.h>
    int (int n,int countDigits){
        n=n/10;
        int countDigits=countDigits(n);
    }
    int main(){
        int countDigits;
        int n;
        printf("Enter value of n:");
        scanf("%d",&n);
        printf("Digits are given number is %d",countDigits);
return 0;
}
        