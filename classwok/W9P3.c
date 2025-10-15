#include <stdio.h>
void main(){
    int n = 0;
    scanf("%d",&n);
    for(int i = 0 ; i < n ; i++){
        scanf("%d",&x[i]);
    }
    int t = 0;
    scanf("%d",&t);
    int found = 0;
    for(int i = 0 ; i < n ; i++){
        if(t == x[i]){
            printf("%d ",i+1);
            found =1;
        }
    }
    if(!found){
        printf("0");
    }
}
