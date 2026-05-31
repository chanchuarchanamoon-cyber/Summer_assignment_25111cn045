#include <stdio.h>
int main(){
int n;
printf("Enter any number");
scanf("%d",&n);
if(n<1){
    printf("Please enter a number greater than 0");
}
else
printf("Factors are");
printf("%d",1);
for(int divisor=2;divisor<=n/2;divisor++){
    if(n%divisor==0){
        printf("%d",divisor);
    }
}
printf("%d",n);
return 0;
}