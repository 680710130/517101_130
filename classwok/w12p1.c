#include <stdio.h>
void main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i = 0 ; i < n ; i ++){
        scanf("%d",&arr[i]);
    }
    int m = 0;
    scanf("%d",&m);
    if(m>0){
        for(int i = 0 ; i < n ; i ++){
            printf("%d ",arr[i]+m);
        }
    }else if(m<0){
        for(int i = n -1 ; i >=0 ; i --){
            printf("%d ",arr[i]+m);
        }
    }
}
