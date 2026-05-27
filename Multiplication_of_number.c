#include <stdio.h>
int main()
{
int n;
printf("Enter the digit whose multiplication is to be eveluated:");
scanf("%d",&n);
int p=1;
for(int i=1;i<=10;i++){
    p=n*i;
}
printf("%d*%d=%d",p);
return 0;
}







