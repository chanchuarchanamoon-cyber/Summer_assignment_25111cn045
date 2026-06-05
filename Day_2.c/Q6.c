#include<stdio.h>
int main(){
    int ld,r=0;
int n;
printf("Enter numbers to be reversed");
scanf("%d",&n);
while(n>0){
    int ld=n%10;
    n=n/10;
    r=r*10;
    r=+ld;
}
printf("Reverse of numbers is %d", r);
return 0;
}