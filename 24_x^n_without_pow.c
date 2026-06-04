#include <stdio.h>
int pow(int x,int y){
    if(y==0) {return 1;}
    else{
        return x*power(x,y-1);
    }

}
int main(){
int a;
printf("Enter base");
scanf("%d",&a);
int b;
printf("Enter power");
scanf("%d",&b);
int result=power(a,b);
printf("Answer is %d over %d is %d",a,b,result);
return 0;
}