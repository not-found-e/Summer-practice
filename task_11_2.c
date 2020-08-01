#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
typedef struct
{
    double price;
    char name[30];
} goods;

void push_table(goods *a,int n)
{

    char s1[] = "       name ";
    char s2[] = "priece";
    for (int i = 0; i < n; i+=2)
    {
        if (i == 0)
        {
            printf("\n\t+--+--------------+-------+  "); printf("+--+--------------+-------+  ");//24
            printf("\n\t|# |%-14s|%-7s|  ", s1, s2);     printf("|# |%-14s|%-7s|  ", s1, s2);
            printf("\n\t+--+--------------+-------+  "); printf("+--+--------------+-------+  ");//24
        }
            printf("\n\t|%-2d|%-14s|%.2lf   |  ", i+1,a[i].name,a[i].price);printf("|%-2d|%-14s|%.2lf   |", i+2,a[i+1].name,a[i+1].price);
            printf("\n\t+--+--------------+-------+  "); printf("+--+--------------+-------+  ");//24


    }
}
int main()
{
    goods a[20];
    const int n = 20;
    srand(time(NULL));
    strcpy(a[0].name, "good #1");
    strcpy(a[1].name, "good #2");
    strcpy(a[2].name, "good #3");
    strcpy(a[3].name, "good #4");
    strcpy(a[4].name, "good #5");
    strcpy(a[5].name, "good #6");
    strcpy(a[6].name, "good #7");
    strcpy(a[7].name, "good #8");
    strcpy(a[8].name, "good #9");
    strcpy(a[9].name, "good #10");
    strcpy(a[10].name, "good #11");
    strcpy(a[11].name, "good #12");
    strcpy(a[12].name, "good #13");
    strcpy(a[13].name, "good #14");
    strcpy(a[14].name, "good #15");
    strcpy(a[15].name, "good #16");
    strcpy(a[16].name, "good #17");
    strcpy(a[17].name, "good #18");
    strcpy(a[18].name, "good #19");
    strcpy(a[19].name, "good #20");
    for (int i = 0; i < n; i++)
    {
        a[i].price = (double)(rand()%100+1)/10;
    }
    for(;;)
    {
        system("cls");
        push_table(a,n);\
        double p1,p2;
        char s1[10],s2[10];
        int k = -1, k2 = -1;
        printf("\nchoose good for compare ");
        scanf("%d",&k);
        p1=a[k-1].price;
        strcpy(s1,a[k-1].name);
        printf("\nchoose good for compare ");
        scanf("%d",&k2);
        p2=a[k2-1].price;
        strcpy(s2,a[k2-1].name);
        if(p1>p2) 
            printf("%s (%d) > %s (%d)",s1,p1,s2,p2);
        else if (p1==p2)
             printf("%s (%d) = %s (%d)",s1,p1,s2,p2);
             else  printf("%s (%.2lf) < %s (%.2lf)",s1,p1,s2,p2);
        getch();
        if(k == 0) break;
    }
    system("pause");
    return 0;
}