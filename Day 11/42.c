#include <stdio.h>

int max(int a,int b){
    if(a>b) return a;
    else return b;
}
int  main(){
    int x;
    printf("x:");
    scanf("%d",&x);
    int y;
    printf("y:");
    scanf("%d",&y);
    int M=max(x,y);
    printf("Max  no  is %d",M);
    
return 0;
}