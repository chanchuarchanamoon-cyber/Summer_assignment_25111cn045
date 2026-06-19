#include <stdio.h>

int sum(int a,int b){
    return a+b;
}
int main(){
int x;
printf("a");
scanf("%d",x);
int y;
printf("b");
scanf("%d",&y);
 int Sum=sum(x,y);
printf("Sum is %d", Sum);
return 0;
}