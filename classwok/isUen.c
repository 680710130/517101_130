#include <stdio.h>
int isUnique(int arr[], int n){
    for(int i = 0 ; i < n ; i++){
        for(int j = i+1; j < n ; j++){
            if(arr[i]==arr[j]){
                return 0;
            }
        }
    }
    return 1;
}
void main(){
    int n = 0;
    scanf("%d",&n);
    int arr[n];
    for(int i = 0 ; i < n ; i++){
        scanf("%d",&arr[i]);
    }
    printf("%d",isUnique(arr,n));
}
