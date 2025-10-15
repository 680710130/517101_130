#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
int n = 10;
int m = 10;
int bomba = 25;
int debug = 1;
int tickPerSec = 5;
int matrix[20][30];
void mark(int x, int y)
{
    if(matrix[x][y]>=99)
    {
        matrix[x][y] -= 100;
        return;
    }
    matrix[x][y]+=100;
}
int reveal(int x, int y)
{
    if(matrix[x][y]%100 == 9)
    {
        return 9;
    }
    if(matrix[x][y]!= -1)
    {
        return 0;
    }
    int bombCount = 0;
    for(int i = x-1 ; i <= x+1 ; i++)
    {
        for(int j = y-1; j <= y+1; j++)
        {
            if(i<0||i>=n || j<0 ||j>=m)
            {
                continue;
            }
            if(matrix[i][j]%100 == 9)
            {
                bombCount +=1;
            }
        }
    }
    matrix[x][y] = bombCount;
    if(bombCount == 0)
    {
        for(int i = x-1 ; i <= x+1 ; i++)
        {
            for(int j = y-1; j <= y+1; j++)
            {
                if(i<0||i>=n || j<0 ||j>=m)
                {
                    continue;
                }
                reveal(i,j);
            }
        }
    }
    return bombCount;
}

void clearMattrix()
{
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            matrix[i][j] = -1;
        }
    }
};
void display()
{
    for(int i = 0 ; i < n ; i ++)
    {
        printf("==",i);
    }
    printf("\n");
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            if(matrix[i][j]>-1 && matrix[i][j] < 9)
            {
                printf("%d ",matrix[i][j]);
            }
            else if (matrix[i][j]>=99)
            {
                printf("x ");
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
}
void main()
{
    srand(time(NULL));
    clearMattrix();
    int initX,initY;
    scanf("d %d %d",&initX,&initY);
    int bombacount = 1;
    while(bombacount != 0)
    {
        clearMattrix();
        for(int i = 0;  i < bomba; i++)
        {
            while(1)
            {
                int newX = rand()%n, newY = rand()%m;
                if(matrix[newX][newY] == 9)
                {
                    continue;
                }
                else
                {
                    matrix[newX][newY] = 9 ;
                    break;
                }
            }
        }
        bombacount = reveal(initX,initY);
        printf("%d\n",bombacount);
    }
    display();
    while(1)
    {
        int x,y;
        char m;
        scanf("%c %d %d",&m,&x,&y);
        if(m == 'd')
        {
            if(reveal(x,y)==9)printf("that bomb");
        }
        if(m == 'm')
        {
            mark(x,y);
        }
        display();
    }
}
