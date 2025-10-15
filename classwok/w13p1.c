#include <stdio.h>
typedef struct student
{
    int year;
    char name[30+1];
    char surname[50+1];
    char id[8+1];
} student_t;
void main()
{
    int n;
    scanf("%d",&n);
    student_t students[n];
    for(int i = 0 ; i < n; i ++)
    {
        scanf("%s %s %s %d",&students[i].id,&students[i].name,students[i].surname,&students[i].year);
    }
    int targ;
    scanf("%d",&targ);
    int found = 0;
    for(int i = 0; i < n ; i++)
    {
        if(students[i].year == targ)
        {
            printf("%s %s %s\n",students[i].id,students[i].name,students[i].surname);
            found =1;
        }
    }
    if(!found)
    {
        printf("None");
    }
}
