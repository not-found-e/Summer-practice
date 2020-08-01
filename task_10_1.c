#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
/*У шкільній адміністрації є така інформація про кожного випускника 11 класів:
– прізвище, ім'я, по батькові;
– дата народження (рік, місяць, число);
– домашня адреса (вулиця, будинок, квартира);
– оцінки атестата про середню освіту.
Визначити: а) чи є в цьому списку випускник із вказаним прізвищем та ім’ям; б) кількість випускників, які старші на 
даний момент за 18 років.
*/
typedef struct
{
    char name[15], lname[15], father[15];
} PIB;
typedef struct
{
    int day, month, year,age;
} date;
typedef struct
{
    char street[15], house[15];
    int flat;
} adress;
typedef struct
{
    PIB p;
    date d;
    adress a;
    int notes[3];
} student;
int AgeCalcul(int dd, int mm, int yy)
{   time_t t = time(NULL);
    struct tm *T = localtime(&t);
    if ((T->tm_mon+1) > mm)
        return (T->tm_year+1900) - yy;
    else
    {
        if (mm == (T->tm_mon+1))
            if (T->tm_mday >= dd)
                return (T->tm_year+1900) - yy;
            else
                return (T->tm_year+1900) - yy - 1;
        else
            return (T->tm_year+1900) - yy - 1;
    }
}
int main()
{
    student a[100];
    int n,counter = 0;
    printf("Enter num of students ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        system("cls");
        printf("student #%d", i + 1);
        printf("\nName            >");
        fflush(stdin);
        gets(a[i].p.name);
        printf("\nLname           >");
        fflush(stdin);
        gets(a[i].p.lname);
        printf("\nday of birth    >");
        scanf("%d", &a[i].d.day);
        printf("\nmonth of birth  >");
        scanf("%d", &a[i].d.month);
        printf("\nyear of birth   >");
        scanf("%d", &a[i].d.year);
        printf("\nstreet          >");
        fflush(stdin);
        gets(a[i].a.street);
        printf("\nhouse           >");
        fflush(stdin);
        gets(a[i].a.house);
        printf("\nflat            >");
        scanf("%d", &a[i].a.flat);
        for (int j = 0; j < 3; j++)
        {
            printf("\n\tnote          >");
            scanf("%d", &a[i].notes[j]);
        }
        a[i].d.age = AgeCalcul(a[i].d.day,a[i].d.month,a[i].d.year);
    }
    char NAME[15],LNAME[15];
    printf("Enter Name  :");
    scanf("%s",&NAME);
    printf("Enter Lname :");
    scanf("%s",&LNAME);
    int  f = 0;
    for (int i = 0; i < n; i++)
    {
        if((strcmp(NAME,a[i].p.name)==0) && (strcmp(LNAME,a[i].p.lname)==0))
        {
            printf("\nYES\n");
            f = 1;
        }
        if(a[i].d.age > 18) counter++;
    }
    if(f == 0) { printf("No student %s %s ", NAME,LNAME);}
    printf("\nnum of students older than 18 y.o = %d\n",counter);
    system("pause");
    return 0;
}