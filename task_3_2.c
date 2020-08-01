#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*Задано матрицю В(4,4). Сформувати одновимірний масив з мiнiмальних елементiв стовпчикiв. У цьому масиві обчислити 
суму та кiлькiсть додатних елементiв. Вивести вихiдну матрицю і сформований масив, суму та кiлькiсть додатних 
елементiв.*/
int main (){
    int b[4][4];
    const int n = 4;
    int a[4],min;
    srand(time(NULL));
    printf("matrix b:\n");
    for (int i = 0; i < n; i++,printf("\n"))
    {
        for (int j = 0; j < n; j++)
        {
            b[i][j] = rand()%20-10;
            printf("%d ",b[i][j]);
        }
        
    }int k=0;
    for (int j = 0; j < n; j++)
    {
        min = b[0][j];
        for (int i = 0; i < n; i++)
        {
            if(b[i][j] < min) min = b[i][j];
        }
        a[k++] = min;
    }
    printf("array A:\n");
    int s=0,positive_counter = 0;
    for (int i = 0; i < n; i++)
    {
        s+=a[i];
        if(a[i]>0) positive_counter++;
        printf("%d ",a[i]);
    }
    printf("\nsum  = %d ", s);
    printf("\npos(a)  = %d ", positive_counter);
    system("pause");
    return 0;
}