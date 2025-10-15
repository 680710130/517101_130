#include <stdio.h>
void merfe(float * arr,int n,int d){
    int h = n/2;
    if(n <= 1){
        return;
    }
    if(n == 2){
        if(arr[0] > arr[1]){
            arr[1] = arr[1] + arr[0];
            arr[0] = arr[1] - arr[0];
            arr[1] = arr[1] - arr[0];
            return;
        }
    }
    merfe(&arr[h],n-h,d+1);
    merfe(arr,h,d+1);
    float temp[n];
    int indexA = 0,indexB = h,curIndex = 0;
    while(curIndex < n){
        if(indexA>=h || arr[indexB]<=arr[indexA]){
            temp[curIndex] = arr[indexB];
            indexB++;
            curIndex++;
            continue;
        }
        if(indexB>=n || arr[indexA] <= arr[indexB]){
            temp[curIndex] = arr[indexA];
            indexA++;
            curIndex++;
            continue;
        }
    }
    for(int i = 0 ; i< n ;i ++){
        arr[i] = temp[i];
        printf("%f",temp[i]);
    }
    printf("\n");
}
void main(int argc ,char *argv[]){
    float arr[argc-1];
    for(int i = 1 ; i < argc; i ++){
        sscanf(argv[i],"%f",&arr[i-1]);
    }
    merfe((float*)arr,argc-1,0);
    printf("=============\n");
    for(int i = 0 ; i < argc-1; i++){
        printf("%f\n",arr[i]);
    }
}
