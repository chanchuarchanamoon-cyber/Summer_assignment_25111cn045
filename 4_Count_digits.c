#include <stdio.h>
int main()
{
    int n;
    printf("Enter numbers whose digits is to be counted:");
    scanf("%d",&n);
    int count=0;
    while(n!=0){
        n=n/10;
        count=count+1;
    }
    printf("Count of digits is %d",count);
    return 0;
}
