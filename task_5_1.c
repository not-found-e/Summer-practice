#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*5.	Дано масив цілих чисел a[i], і = 1, … , n. Використовуючи вказівники підрахувати кількість ділянок масиву, 
де елементи змінюють знак.*/
int main()
{
    int n;
    printf("Enter n :");
    scanf("%d", &n);
    printf("array a:\n");
    srand(time(NULL));
    int a[n], *p;
    p = a;
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 20 - 10;
        printf("%d ", a[i]);
    }
    int counter = 0;
    int f;
    if (*p > 0)
    {
        f = 1;
    }
    else
    {
        f = 0;
    }

    for (int i = 0; i < n; i++)
    {
        if (f == 1)
        {
            if (*p < 0)
            {
                f = 0;
                counter++;
            }
            p++;
        }
        else
        {
            if(*p>0)
            {
                f = 1;
                counter++;
            }
            p++;
        }
        
    }
    printf("\nnumber of areas = %d\n",counter );
    system("pause");
    return 0;
}