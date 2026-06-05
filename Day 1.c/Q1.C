#include <stdio.h>
int main(){
    int n;
    printf("Enter value of no up to which sum is to be calculated:");
    scanf("%d",&n);
    int sum=0;
    for(int i=1;i<=n;i++){
        sum=sum+i;
    }
printf("Sum of numbers is %d", sum);
return 0;
}





