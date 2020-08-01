#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*5.	Створити однозв’язний лінійний список з 5-ти елементів, які мають одне інформаційне поле цілого типу 
(як додатні, так і від’ємні значення). На основі створеного списку створити ще 2 списки: в одному повинні міститися 
додатні елементи початкового списку, в іншому – від’ємні. Вивільнити динамічну пам’ять.*/
typedef struct El1
{
    int num;

    struct El1 *next;
} Elem;
void AddEnd(Elem **st, Elem **pt, int ran)
{
    Elem *dd = (Elem *)malloc(sizeof(Elem));
    dd->num = ran;
    if (*st == NULL)
    {
        dd->next = NULL;
        *st = dd;
        *pt = dd;
    }
    else
    {
        dd->next = NULL;
        (*pt)->next = dd;
        *pt = dd;
    }
}
void AddEnd__( Elem **st, Elem **pt, Elem **source)
{
Elem *dd = (Elem*)malloc(sizeof(Elem));
dd ->num = (*source)->num;
if ( *st == NULL)
{
dd->next = NULL;
*st = dd;
*pt = dd;
}
else
{
dd->next = NULL;
(*pt)->next = dd;
*pt = dd;
}
}
int main()
{
    Elem *st = NULL, *pt = NULL, *st_pos = NULL, *st_neg = NULL, *pt_pos = NULL, *pt_neg = NULL;
    const int n = 5;
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {int ran;
        ran = rand()%20-10;
        AddEnd(&st, &pt,ran);
    }
    pt = st;
    for (int i = 0; i < n; i++)
    {
        if (pt->num > 0)
        {
            AddEnd__(&st_pos, & pt_pos,&pt);
        }
        if (pt->num < 0)
        {
            AddEnd__(&st_neg, &pt_neg,&pt);
        }
        pt = pt->next;
    }
    pt = st;
    pt_neg = st_neg;
    pt_pos = st_pos;
    printf("list 1\n");
    while (pt !=NULL)
    {
        printf("%d ",pt->num);
        pt = pt->next;
    }
    printf("\nlist 2\n");
    while (pt_pos !=NULL)
    {
        printf("%d ",pt_pos->num);
        pt_pos = pt_pos->next;
    }
    printf("\nlist 3\n");
    while (pt_neg !=NULL)
    {
        printf("%d ",pt_neg->num);
        pt_neg = pt_neg->next;
    }
    printf("\n");
    system("pause");
    return 0;
}