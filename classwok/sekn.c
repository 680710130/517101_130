#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int initX = 10,initY = 10;
int displaySizeX = 20, displaySizeY = 20;
int tickPerSec = 10;
typedef struct body
{
    int x;
    int y;
    struct body * next;
} body_t;

void extendBody(body_t ** headptr)
{
    body_t * newHead = malloc(sizeof(body_t));
    newHead->x = (*headptr)->x;
    newHead->y = (*headptr)->y;
    newHead->next = *headptr;
    *headptr = newHead;
}


void printBody(body_t *head)
{
    while(head != NULL)
    {
        printf("%d %d\n",head->x,head->y);
        head = head->next;
    }
}
void moveBody(body_t * cursor)
{
    if(cursor->next != NULL)
    {
        if(cursor->x != cursor->next->x || cursor->y != cursor->next->y)
        {
            moveBody(cursor->next);
            cursor->next->x = cursor->x;
            cursor->next->y = cursor->y;
        }
        else
        {
            moveBody(cursor->next);
        }
    }
}
void moveHead(body_t * head, int x, int y)
{
    if(head == NULL)
    {
        return;
    }
    body_t * cursor = head;
    moveBody(cursor);
    head->x += x;
    head->y += y;
}

int fruitX,fruitY,existFruit = 0;

void display(body_t* head)
{
    for(int i = 0 ; i < displaySizeY; i++)
    {
        for(int j = 0 ; j < displaySizeX; j++)
        {
            int isthere = 0;
            body_t * cursor = head;
            while(cursor != NULL)
            {
                if(cursor->x == j && cursor->y == i)
                {
                    isthere = 1;
                    break;
                }
                cursor = cursor->next;
            }
            if(isthere)
            {
                printf("#");
            }
            else if(j == fruitX && i == fruitY)
            {
                printf("x");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}
void makeFruit();
int fruitCount =0;
void fruitCheck(body_t ** headptr)
{
    body_t * head = *headptr;
    while(head != NULL)
    {
        if(head->x == fruitX && head->y == fruitY)
        {
            extendBody(headptr);
            makeFruit();
            fruitCount +=1;
            break;
        }
        head = head->next;
    }
}
int deadCheck(body_t* head)
{
    int headX = head->x, headY = head->y;
    head = head->next;
    while(head != NULL)
    {
        if(head->x == headX&& head->y == headY)
        {
            return 1;
        }
        head = head->next;
    }
    if(headX <0 || headX > displaySizeX || headY < 0 || headY > displaySizeY)
    {
        return 1;
    }
    return 0;
}
void makeFruit()
{
    fruitX = rand()%20;
    fruitY = rand()%20;
    existFruit = 1;
}
int main()
{
    body_t * head = malloc(sizeof(body_t));
    head->x = initX;
    head->y = initY;
    head->next = NULL;
    scanf("%d",&tickPerSec);
    for(int i = 0; i < 5 ; i++)
    {
        extendBody(&head);
    }
    display(head);
    int last = clock();
    int queueX = 0, queueY = 1;

    makeFruit();
    while(1)
    {
        printf("\033[20A");
        display(head);
        if(kbhit())
        {
            char c = getch();
            switch(c)
            {
            case('w'):
                if(queueY == 1)
                {
                    break;
                }
                queueX = 0;
                queueY = -1;
                break;
            case('a'):
                if(queueX == 1)
                {
                    break;
                }
                queueX = -1;
                queueY = 0;
                break;
            case('s'):
                if(queueY == -1)
                {
                    break;
                }
                queueX = 0;
                queueY = 1;
                break;
            case('d'):
                if(queueX == -1)
                {
                    break;
                }
                queueX = 1;
                queueY = 0;
                break;
            }
        }
        if((clock()-last) > CLOCKS_PER_SEC/tickPerSec)
        {
            last = clock();
            moveHead(head,queueX,queueY);
            if(deadCheck(head))
            {
                break;
            }
            fruitCheck(&head);
        }
    }
    printf("%d x %d : %d",fruitCount,tickPerSec,fruitCount * tickPerSec);
    return 0;
}
