#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*5. Обчислити та вивести середн∙ арифметичне елементiв розмiщених на непарних
мiсцях в масивi R(9).                                
*/
int main (){
    int r[9];
    const n = 9;
    int s =0;
    double sz;
    printf("array:\n");
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        r[i] = rand()%10;
        s+=r[i];
        printf("%d ", r[i]);
    }
    sz=(double)s/9;
    printf("\nsz= %.2lf\n",sz);
    system("pause");
    return 0;
}