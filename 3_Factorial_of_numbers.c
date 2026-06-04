#include <stdio.h>
int main()
{
    int n;
    printf("Enter number whose factorial is bo find:");
    scanf("%d",&n);
    int p=1;
    for(int i=1;i<=n;i++){
        p=p*i;
    }
    printf("Factorial of number is %d",p);
    return 0;
}
