#include <stdio.h>
int main(){
    int num;
    printf("Enter any number");
    scanf("%d",&num);
    int lpf;
    for(int i=1;i<=num;i++){
        if(num%i==0) lpf=i;
    }
printf("Largest prime factor is %d",lpf);
return 0;
}