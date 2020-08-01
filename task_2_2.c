#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* 5.	Використовуючи задані масиви Т(6) та Н(6), створити масив Р(6), елементи якого обчислюються за формулою 
Р(і)=Т(і)-Н(і), де і=1,2,…6.
Відсортувати елементи масиву Р за зростанням. Вивести на екран всі масиви.
*/
void  ArrayP_create(int *t,int *h,int *p)
{
    for (int i = 0; i < 6; i++)
    {
        p[i]=t[i]-h[i];
    }
    
}
void SortArr(int *p)
{ int *head;
head = p;
   for (int i = 6; i > 0 ; i--)
   { p = head;
       for (int j = 0; j < i; j++)
       {
           if(*p>*(p+1))
           {
               int tmp;
               tmp = *p;
               *p = *(p+1);
               *(p+1) = tmp;
           }
           p++;
       }
       
   }
   
    
}
int main (){
    const n = 6;
    int t[n], h[n],p[n];
    srand(time(NULL));
    printf("array T:\n");
    for (int i = 0; i < n; i++)
    {
        t[i]=rand()%10;
        h[i]=rand()%10;
        printf("%d ", t[i]);
    }
    printf("\narray H:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", h[i]);
    }
    printf("\narray P:\n");
    ArrayP_create(t,h,&p);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", p[i]);
        
    }
    printf("\nSorted array P:\n");
    SortArr(&p);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", p[i]);
        
    }
    
    system("pause");
    return 0;
}