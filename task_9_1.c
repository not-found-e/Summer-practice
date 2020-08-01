#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
/*Дано масив дійсних чисел a[i], і = 1, … , n. Виділіть для нього необхідний обсяг динамічної пам'яті. Створити 
динамічний масив b[j], j = 1, … , m, в який записати лише парні елементи масиву a[i], що знаходяться на непарних 
місцях. Вивільніть динамічну пам'ять.*/
bool Even(int n)
{
    
    return  n%2 == 0;
}
int main()
{
    int *a, *b, n, m;
    printf("Enter n: ");
    scanf("%d",&n);
    a = (int*)malloc(n*sizeof(int));
    srand(time(NULL));
    printf("array a:\n");
    for (int i = 0; i < n; i++)
    {
        a[i] = rand()%10;
        printf("%d ", a[i]);
    }
    int k=0;
    printf("\narray b:\n");
    for (int i = 0; i < n; i++)
    {
        if( Even(i) && Even(a[i]))
            m++;

    }
    b = (int*)malloc(m*sizeof(int));
    for (int i = 0; i < n; i++)
    {
        if( Even(i) && Even(a[i]))
            b[k++] = a[i];

    }
    for (int i = 0; i < m; i++)
    {
        printf("%d ",b[i]);
    }
    free(a);
    free(b);
    system("pause");
    return 0;
}