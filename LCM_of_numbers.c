#include <stdio.h>
int main()
{
    int a;
    printf("Enter first no:");
    scanf("%d",&a);
    int b;
    printf("Enter second no:");
    scanf("%d",&b);
    int n;
    int hf=1;
    for(int i=1;i<=n-1;i++){
        if(n%i==0) hf=i;
    }
    int LCM=1;
    LCM=a*b%hf;
    printf("LCM of number is %d", LCM);
    return 0;
}