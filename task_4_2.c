#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*5.	Дано дійсну матрицю А розмірності nxm. Заповнити її випадковими цілими числами з відрізка [-10; 10].  
Знайти середнє арифметичне максимального та мінімального елементів матриці.*/
int main (){
    const int n = 3, m = 4;
    int a[n][m];
    printf("matrix:\n");
    srand(time(NULL));
    for (int i = 0; i < n; i++,printf("\n"))
    {
        for (int j = 0; j < m; j++)
        {
            a[i][j] = rand()%20-10;
            printf("%d ", a[i][j]);
        }
        
    }
    int min, max;
    min = a[0][0];
    max = a[0][0];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(min>a[i][j]) min = a[i][j];
            if(max<a[i][j]) max = a[i][j];
        }
        
    }
    float avg;
    avg =(float)(min+max)/2;
    printf("min = %d, max = %d\n", min,max);
    printf("avg = %.2f\n", avg);
    system("pause");
    return 0;
}