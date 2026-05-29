#include <stdio.h>
int main()
{
int n;
printf("Enter any no");
scanf("%d",&n);
int sum=0;
for(int i=1;i<n;i++){
    if(n%i==0) {
        sum=sum+i;
    }
if(n==sum){
    printf("No is perfect");
}
else{
    printf("Given no is not perfect");
}
return 0;
}
