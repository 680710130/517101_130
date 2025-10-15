#include <stdio.h>
#include <string.h>
void main()
{
    //commente2
    char sig[100+1];
    scanf("%s",sig);
    int n;
    scanf("%d",&n);
    for(int i = 1 ; i < strlen(sig) ; i++)
    {
        for(int j = 0; j < n - 1; j++)
        {
            if(sig[i] == '1'||(sig[i]!=sig[i-1]&&j==0))
            {
                printf("X");
            }
            else
            {
                printf("_");
            }
        }
    }
    printf("\n");
    for(int i = 0 ; i < n -2 ; i++)
    {
        for (int j = 1 ; j < strlen(sig); j++)
        {
            for(int k = 0 ; k < n -1; k++)
            {
                if(sig[j]!=sig[j-1]&&k==0)
                {
                    printf("X");
                }
                else
                {
                    printf("_");
                }
            }
        }
        printf("\n");
    }
    for(int i = 1 ; i < strlen(sig) ; i++)
    {
        for(int j = 0; j < n -1; j++)
        {
            if(sig[i] == '0'||(sig[i]!=sig[i-1]&&j==0))
            {
                printf("X");
            }
            else
            {
                printf("_");
            }
        }
    }
}
