#include <stdio.h>
#include <stdlib.h>
void main(){
    int *** y;

    int **x;
    x = malloc(sizeof(int*)*3);
    for(int i = 0 ; i < 3 ; i++){
        x[i] = malloc(sizeof(int)*3);
    }
    for(int i =0 ; i <3 ; i ++){
        for(int j = 0 ; j<3 ; j++){
            x[i][j] = 0;
            printf("%d",x[i][j]);
        }
    }
    y = &x;
    for(int i =0 ; i <3 ; i ++){
        for(int j = 0 ; j<3 ; j++){
            printf("%d",(*y)[i][j]);
        }
    }
}
