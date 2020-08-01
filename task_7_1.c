#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*. Утворити і вивести масив y з елементами yk=fi+1(k), де k=1,12, і- номер варіанта. Для розрахунку yk створити 
функцію користувача  Скласти ще одну функцію користувача для пошуку даних у цьому масиві. Критерії пошуку взяти 
відповідно свого варіанту. Шукані дані вивести в головній функції.
5.	Скільки було від’ємних значень? Визначити мінімальне значення.*/
void Fill_Array(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = rand()%20-10;
    }
    
}
int Neg_In_Arr(int *a, int n)
{int negative_counter = 0;
    for (int  i = 0; i < n; i++)
    {
        if(a[i]<0) negative_counter++;
    }
    return negative_counter;
}
int MIN(int *a, int n)
{int min = a[0];
    for (int  i = 0; i < n; i++)
    {
        if(min > a[i]) min = a[i];
    }
    return min;
}
int main (){
    int n;
    printf("Enter n ");
    scanf("%d", &n);
    int a[n];
    printf("array\n" );
    Fill_Array(a,n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
        
    }
    int min, negative_counter;
    negative_counter = Neg_In_Arr(a,n);
    min = MIN(a,n);
    printf("\nnegative = %d\nmin = %d\n",negative_counter,min);
    system("pause");
    return 0;
}