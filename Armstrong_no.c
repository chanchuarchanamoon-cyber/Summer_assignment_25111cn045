#include <stdio.h>
int main()
{
int n;
printf("Enter any no:");
scanf("%d",&n);
int origNo;
n=origNo;
while(n>0){
    int ld=n%10;
    int armNo=n+(ld*ld*ld);
    n=n/10;
}
int armNo;
if(armNo==origNo){
    printf("No is armstromg");
}
else {
    printf("No is not armstrong");
}
return 0;
}
