#include <stdio.h>
int main(){
int n;
printf("Enter any no");
scanf("%d",&n);
int fact=1;
int sum=0;
for(int i=1;i<=n;i++){
    fact=fact*i;
    sum=sum+fact;
}

if(sum==n){
    printf("Given no is strong");
}
else{
    printf("Given no is not strong");
}
return 0;
}





