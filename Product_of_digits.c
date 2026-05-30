#include <stdio.h>
int main()
{
int n;
printf("Enter any number:");
scanf("%d",&n);
int ld=1;
int p=1;
while(n>0){
    ld=n%10;
    p=p*ld;
    n=n/10;
}
printf("Product of digits is: %d",p);
return 0;
}