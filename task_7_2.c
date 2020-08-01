#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*Утворити і вивести масив А, елементи якого описані формулою  ,  m,n=1…4, i –   номер варіанта. Скласти функцію 
користувача для пошуку даних у цьому масиві. Критерії пошуку взяти відповідно свого варіанту, якщо критерії пошуку\
не відповідають вашим даним вибрати свої значення для пошуку. Шукані дані вивести в головній функції.
Обчислити суму квадратів елементів, значення яких більші, ніж 1 та кількість таких елементів.*/
int sqrSum(int **a, int n, int m, int *counter)
{*counter = 0;
    int s = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] != 1)
            {
                (*counter)++;
                s += pow((a[i][j]),2);
            }
        }
    }
    return s;
}
int main()
{
    int **a, n = 4, m = 4;
    a = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++)
    {
        a[i] = (int *)malloc(n * sizeof(int));
    }
    srand(time(NULL));
    printf("matrix:\n");
    for (int i = 0; i < m; i++, printf("\n"))
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = rand() % 9 + 1;
            printf("%d ", a[i][j]);
        }
    }
    int sum, counter;
    sum = sqrSum(a,n,m,&counter);
    printf("\ns = %d\ncount = %d\n", sum, counter);
    system("pause");
    return 0;
}