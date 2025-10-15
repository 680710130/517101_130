#include <stdio.h>

void main(){
    int n;
    scanf("%d",&n);
    int scores[n];
    for(int i = 0 ; i < n ; i++){
        scanf("%d",&scores[i]);
    }
    int eval = 0;
    int evbl = 0;
    for(int i = 0 ; i < n ; i++){
        int enScore;
        scanf("%d",&enScore);
        if(scores[i]>enScore){
            eval +=2;
        }
        else if(scores[i] < enScore){
            evbl +=2;
        }
        else{
            eval +=1;
            evbl +=1;
        }
        //printf("%d %d\n",eval,evbl);
    }
    if(evbl>eval){
        printf("Team 2 wins\nScore %d to %d",evbl,eval);
    }
    else if(evbl<eval){
        printf("Team 1 wins\nScore %d to %d",eval,evbl);
    }
    else{
        printf("Draw game\nScore %d to %d",eval,eval);
    }
}
