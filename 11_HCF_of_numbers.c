#include <stdio.h>
int main(){
int n;
printf("Enter any number:");
scanf("%d",&n);
int hf=1;
for(int i=1;i<=n-1;i++){
    if(n%i==0) hf=i;
printf("Highest factor: %d",hf);
return 0;
}
