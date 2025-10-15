#include <stdio.h>
int debug = 0;
int main(){
    int n;
    scanf("%d",&n);
    int matrix[n][n];
    for(int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < n ; j++){
            scanf("%d",&matrix[i][j]);
        }
    }
    int sum = 0;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            if(i==j){continue;}
            if(debug)printf("(%d %d)(%d %d)\n",i,j,j,i);
            int diff = matrix[i][j] - matrix[j][i];
            sum += diff > 0 ? diff : -diff;
        }
    }
    printf("%d",sum);
    return 0;
}
