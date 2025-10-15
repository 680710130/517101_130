#include <stdio.h>
void derivative(int* array, int *AOutput, const int N){
    AOutput[0]=0;
    for(int i = 0; i < N - 1; i++){
        AOutput[i+1]=array[i+1]-array[i];
    }
}
void printArr(int*array, const int N){
    for(int i = 0 ; i < N ; i++){
        printf("%d ",array[i]);
    }
}
void main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for( int i = 0 ; i < n ; i++){
        scanf("%d",&arr[i]);
    }
    int der[n];
    derivative(arr,der,n);
    printArr(der,n);
}
