#include<stdio.h>
#include<stdlib.h>
typedef struct queue{
    int i;
    struct queue * next;
} queue_t;
typedef struct head{
    struct queue * next;
} head_t;
void main(){
    head_t head;
    queue_t * cursor = NULL;
    int x = 0;
    int n = 0;
    scanf("%d",&x);
    while(x>=0&&x<10){
        n+=1;
        queue_t * node = malloc(sizeof(queue_t));
        node->i = x;
        node->next = NULL;
        if(cursor!=NULL){
            cursor->next = node;
        }else
        {
            head.next = node;
        }
        cursor = node;
        scanf("%d",&x);
    }
    cursor = head.next;
    int nMax = n;
    while(cursor!= NULL){
        for(int i = 0 ; i < n -1 ; i++){
            printf("-");
        }
        for(int i = 0 ;i < nMax-n +1;i++){
            printf("%d",cursor->i);
        }
        cursor=cursor->next;
        n--;
        printf("\n");
    }
}
