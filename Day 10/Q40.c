#include <stdio.h>
int mmain(){
    for(int i=0;i<=5;i++){
        for(int j=0;j <4-i){
            printf(" ")
        }
    }
    for(int j=0;j<-i;j++){
        printf("%c",j+64);
    }
    for(int j=i-1;j>=0;j--){
        printf("%c",j+64);
    }
    printf("\n");
}
return 0;
}