#include <stdio.h>
void main()
{
    int n;
    int c;
    scanf("%d %d",&n,&c);
    int arr[c];
    int maxNum = 1;
    int maxCount = 0;
    for(int i = 0 ; i < c ; i++)
    {
        scanf("%d",&arr[i]);
    }
    for(int i = 0; i < n ; i++)
    {
        int curCount = 0;
        for(int j = 0 ; j < c ; j ++)
        {
            if(i+1==arr[j])
            {
                curCount+=1;
            }
        }
        if(curCount > maxCount)
        {
            maxCount = curCount;
            maxNum = i+1;
        }
    }
    printf("%d\n%d",maxNum,maxCount);
}
