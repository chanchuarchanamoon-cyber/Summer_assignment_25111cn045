#include <stdio.h>
int main()
{
int n;
printf("Enter any number");
scanf("%d",&n);
int originalnum=n;
while(n>0){
int remainder=n%10;
int reverseNo=reverseNo*10+remainder;
n=n/10;
}
int reverseNo;
if(originalnum==reverseNo){
    printf("No is pallindrome");
}
else{
    printf("No is not pallindrome");
}
return 0;
}









