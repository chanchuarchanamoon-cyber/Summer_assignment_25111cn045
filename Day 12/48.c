#include <stdio.h>
int isPerfectNo(int n){
    int sum=0;
    for(int i=1;i<n;i++){
        if(n%i==0){
            sum+=i;
        }
    }
    if(sum==n) return 1;
    else return 0;
}
int main(){
    int n;
    printf("Enter a number:");
    scanf("%d",&n);
    if(isPerfectNo(n)){
        printf("%d is a perfect number",n);
    }
    else{
        printf("%d is not a perfect number",n);
    }
}
return 0;
}