#include <stdio.h>
#include <math.h>
int isArmstrong(int num){
    int originalNum=num;
    int sum=0;
    int digits=0;
    while(originalNum!=0){
        digits++
        originalNum=originalNum/10;
    }
    originalNum=num;
    while(originalNum!=0){
        int remainder=originalNum%10;
        sum=sum+round(pow(remainder,digits));
        originalNum=originalNum/10;
    }
int main(){
    int isArmstrong=1;
    int start,end;
    printf("Enter lower and upper limit of range");
    printf("Armstrong numbers between %d and %d are %d", start,end);
    if(isArmstrong(i)){
        printf("%d",i);
        count++
}
return 0;
}
