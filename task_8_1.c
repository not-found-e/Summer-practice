#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
/*5.	Написати функцію Even логічного типу, що повертає True, якщо цілий параметр k є парним, і False в 
протилежному випадку. За її допомогою знайти кількість парних чисел серед послідовності з 10 цілих чисел*/
bool Even(int n)
{
    
    return n!=0 && n%2 == 0;
}
int main (){
    int a[10];
    srand(time(NULL));
    int counter = 0;
    for (int i = 0; i < 10; i++)
    {
        a[i] = rand()%10;
        printf("%d ", a[i]);
            if(Even(a[i])) counter++;
    }
    printf("\n%d\n ", counter);
    system("pause");
    return 0;
}