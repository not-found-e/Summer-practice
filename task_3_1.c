#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*В заданiй матрицi Q(4,5) знайти суму елементiв менших заданого числа D. Вивести вихiдну матрицю та обчислену суму.*/
int main (){
    int q[4][5]; 
    const col = 5 , row = 4;
    srand(time(NULL));
    int d,s =0;
    d = rand()%9+1;
    printf("d = %d\n",d);
    printf("matrix q:\n");
    
        for (int i = 0; i < row; i++,printf("\n"))
        {
            for (int j = 0; j < col; j++)
            {
                q[i][j] = rand()%10;
                if(q[i][j] < d) s+=q[i][j];
                printf("%d ",q[i][j]);
            }
            
        }
        
    printf("\nsum = %d\n",s);
    system("pause");
    return 0;
}