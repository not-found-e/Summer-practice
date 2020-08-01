#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
/*5.	Відомі дані про ріст 15 юнаків класу. Впорядкувати дані за спаданням. Жодна пара учнів не має однаковий
зріст. На початку навчального року в клас з’явився новий учень (відомо, що його ріст не збігається з ростом жодного 
з учнів класу, не перевищує ріст найнижчого учня та менший росту найвищого). 
1)	Вивести прізвища всіх учнів, ріст яких менше росту новенького.
2)	Визначити прізвище учня, після якого варто записати прізвище новенького, щоб упорядкованість не порушилася.
3)	Визначити прізвище учня, ріст якого найменше відрізняється від росту новенького.
4)	Одержати новий список прізвищ учнів (з урахуванням прізвища новенького), у якому прізвища розташовані в порядку спадання росту
*/
typedef struct Tst
{
    char lname[15];
    int high;

    struct Tst *next;
} Elem;
void SwapForwList_BEG(Elem **st, Elem **bef)
{
    Elem *tmp;
    tmp = (*st)->next;
    (*st)->next = tmp->next;
    tmp->next = *st;
    *st = tmp;
    *bef = *st;
}
void SwapForwList_END(Elem **before_before_End, Elem **bef)
{
    if ((*before_before_End)->next->next == NULL)
    {
        (*before_before_End) = (*bef);
        Elem *tmp = (*before_before_End)->next;
        (*before_before_End)->next->next->next = tmp;
        (*before_before_End)->next = tmp->next;
        tmp->next = NULL;
    }
    else
    {
        Elem *tmp = (*before_before_End)->next;
        (*before_before_End)->next->next->next = tmp;
        (*before_before_End)->next = tmp->next;
        tmp->next = NULL;
    }
}
void SwapForwList_CUR(Elem **before_first_Cur, Elem **bef)
{
    (*before_first_Cur) = (*bef);
    Elem *tmp = (*before_first_Cur)->next;
    Elem *forth_ = tmp->next->next;
    (*before_first_Cur)->next->next->next = tmp;

    (*before_first_Cur)->next = tmp->next;

    tmp->next = forth_;

    // if ((forth_->next == NULL))
    //     *bef = (*before_first_Cur)->next;
}

void push_menu(char s[])
{
    char s1[] = "add student";
    char s2[] = "sort";
    char s3[] = "LN before new st";
    char s5[] = "LN list < new_high";
    char s4[] = "push to file";
    char stop[] = "clear and exit";
    printf("\n+--+------------------+");
    printf("\n|%-2d|%-18s|", 1, s);
    printf("\n+--+------------------+");
    printf("\n|%-2d|%-18s|", 2, s1);
    printf("\n+--+------------------+");
    printf("\n|%-2d|%-18s|", 3, s2);
    printf("\n+--+------------------+");
    printf("\n|%-2d|%-18s|", 4, s3);
    printf("\n+--+------------------+");
    printf("\n|%-2d|%-18s|", 5, s4);
    printf("\n+--+------------------+");
    printf("\n|%-2d|%-18s|", 6, s5);
    printf("\n+--+------------------+");
    printf("\n|%-2d|%-18s|", 0, stop);
    printf("\n+--+------------------+\n"); //23
}
void push_table(char s1[], char s2[], Elem **st, Elem **pt)
{
    if (*pt == *st)
    {
        printf("\n\t+----+-----------------------------+"); //36
        printf("\n\t|%-4s|%-29s|", s1, s2);
        printf("\n\t+----+-----------------------------+");
    }
    printf("\n\t|%-4d|%-29s|", (*pt)->high, (*pt)->lname);
    if ((*pt)->next == NULL)
        printf("\n\t+----+-----------------------------+");
}
void AddEnd(Elem **st, Elem **pt)
{

    Elem *dd = (Elem *)malloc(sizeof(Elem));
    printf("\n\tLname           > ");
    fflush(stdin);
    gets(dd->lname);
    printf("\n\tHigh(cm)        > ");
    scanf("%d", &dd->high);
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
int main()
{
    int f = 0, new_high;
    FILE *file = fopen("11_1out.txt", "w");
    int n = 5;
    Elem *st, *pt;
    st = NULL;
    pt = NULL;
    for (int i = 0; i < n; i++)
    {
        printf("#%d", i + 1);
        AddEnd(&st, &pt);
    }
    int k = 0, p = 0;
    pt = st;
    for (;;)
    {
    m1:

        if (p == 1)
            break;
        system("cls");
        push_menu("show table");
        scanf("%d", &k);
        switch (k)
        {
        case 1:
        {
            pt = st;
            while (pt != NULL)
            {
                push_table("high", "          Last name          ", &st, &pt);
                pt = pt->next;
            }
            getch();
            break;
        }
        case 2:
        {
            if (f == 0)
            {
                printf("not sorted! Please sort first");
                getch();
                break;
            }
            pt = st;
            while (pt != NULL)
            {
                if (pt->next == NULL)
                {
                    AddEnd(&st, &pt);
                    new_high = pt->high;
                }
                pt = pt->next;
            }
            f = 0;
            n++;
            break;
        }
        case 3:
        {
            f = 1;
            pt = st;
            Elem *bef = NULL;
            for (int p = 0; p < 12; p++)
            {

                for (int i = n - 1; i > 0; i--)
                {
                    pt = st;
                    for (int j = 0; j < i; j++)
                    {
                        if (pt->high < pt->next->high)
                        {
                            if (pt == st)
                                SwapForwList_BEG(&st, &bef);
                            else if (pt->next->next == NULL)
                                SwapForwList_END(&pt, &bef);
                            else
                                SwapForwList_CUR(&pt, &bef);
                        }
                        else
                        {

                            bef = pt;
                            pt = pt->next;
                        }
                    }
                }
            }
            printf("sorted");
            getch();
            break;
        }
        case 4:
        {
            if (f == 0)
            {
                printf("not sorted! Please sort first");
                getch();
                break;
            }
            pt = st;
            while (pt != NULL)
            {
                if (pt->next->high == new_high)
                {
                    if (abs(pt->high - new_high) < abs(pt->next->next->high - new_high))
                    {
                        printf("\n3) %s , %d", pt->lname, pt->high);
                        fprintf(file, "\n3) %s, %d", pt->lname, pt->high);
                    }
                    else
                    {
                        printf("\n3) %s, %d", pt->next->next->lname, pt->next->next->high);
                        fprintf(file, "\n3) %s, %d", pt->next->next->lname, pt->next->next->high);
                    }

                    printf("\n2) %s", pt->lname);
                    fprintf(file, "\n2) %s", pt->lname);
                    getch();
                    break;
                }
                pt = pt->next;
            }

            break;
        }
        case 5:
        {
            pt = st;
            while (pt != NULL)
            {

                if (pt == st)
                {
                    fprintf(file, "\n\t+--------+-----------------------------------+"); //44
                    fprintf(file, "\n\t| number |               type                |"); //44
                    fprintf(file, "\n\t+--------+-----------------------------------+"); //44
                }
                fprintf(file, "\n\t|%-8d|%-35s|", pt->high, pt->lname); //44
                if (pt->next == NULL)
                    fprintf(file, "\n\t+--------+-----------------------------------+"); //44
                pt = pt->next;
            }
            printf("Loaded\n");
            fclose(file);
            getch();
            break;
        }
        case 6:
        {
            pt = st;
            while (pt != NULL)
            {

                if (pt->high < new_high)
                {
                    printf("\n1)\n");
                    printf("%s, %d",pt->lname, pt->high );
                    fprintf(file,"\n1)\n");
                    fprintf(file,"%s, %d",pt->lname, pt->high );
                }
                    pt = pt->next;
            }
            getch();
            break;
        }
        case 0:
        {
            p = 1;
            system("pause");
            break;
        }
        default:
            printf("\nError");
            goto m1;
            break;
        }
    }
    return 0;
}