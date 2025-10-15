#include <stdio.h>
typedef struct coord {
    int x;
    int y;
    int order;
} coord_t;
int main(){
    int n,m,o;
    scanf("%d %d %d",&n,&m,&o);
    coord_t coords[o];
    for(int i = 0; i < o; i++){
        int x,y;
        scanf("%d %d",&x,&y);
        coords[i].x = x-1;
        coords[i].y = y-1;
        coords[i].order = i+1;
    }
    for(int i = 0; i < n ; i++){
        for(int j = 0 ; j < m ; j ++){
            int match = 0;
            for(int k = 0; k < o; k++){
                if(i == coords[k].x && j == coords[k].y){
                    match = coords[k].order;
                }
            }
            printf("%d ",match);
        }
        printf("\n");
    }
    return 0;
}
