#include <stdio.h>
int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int length = sizeof(arr) / sizeof(arr[0]); 
    for(int i=0;i<length;i++){
        max=arr[0];
        if(arr[i]>max){
            max=arr[i];
        }
        min=arr[0];
        if(arr[i]<min){
            min=arr[i];
        }
        return 0;
    }