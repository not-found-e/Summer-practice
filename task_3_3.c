#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*Задано масив Х(5,5). Всi нульовi елементи головної дiагоналi замiнити сумою додатних елементiв масиву. 
Вивести вихiдну матрицю, знайдену суму та перетворений масив.*/
int main (){
    int x[5][5];
    const int n = 5; 
    int s =0;
    printf("matrix X:\n");
    srand(time(NULL));
    for (int i = 0; i < n; i++,printf("\n"))
    {
        for (int j = 0; j < n; j++)
        {
            x[i][j] = rand()%10;
            printf("%d ",x[i][j]);
            s+= x[i][j];
        }
        
    }
    printf("new matrix\n");
    for (int i = 0; i < n; i++,printf("\n"))
    {
        for (int j = 0; j < n; j++)
        {
            if((i == j) && (x[i][j] == 0)) x[i][j] = s;
            printf("%d ",x[i][j]);
        }
        
    }
    printf("sum  = %d",s);
    system("pause");
    return 0;
}