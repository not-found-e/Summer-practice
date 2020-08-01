#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*Вивести на екран таблицю результатів голосування, де у рядках є дані з населених пунктів, а у стовпцях - дані 
щодо конкретних кандидатів
5.	В яких населених пунктах другий і четвертий кандидати на¬брали максимальну кількість голосів?
*/
int main()
{
    int max_2 = 0, max_4 = 0, place_2, place_4;
    srand(time(NULL));
    int s1 = 0, s2 = 0, s3 = 0;

    int **p;
    p = (int *)calloc(6, sizeof(int *));
    for (int i = 0; i < 6; i++)
    {
        p[i] = (int *)calloc(5, sizeof(int));
        for (int j = 0; j < 5; j++)
            p[i][j] = rand() % 10 * i + 50;
    }
    printf("1 |2 |3 |4 |5 |<-candidates \n--+--+--+--+--+\n");
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%d|", p[i][j]);
            if (j == 1)
            {
                if (max_2 < p[i][j])
                {
                    max_2 = p[i][j];
                    place_2 = i+1;
                }
            }
            if (j == 3)
            {

                if (max_4 < p[i][j])
                {
                    max_4 = p[i][j];
                    place_4 = i+1;
                }
            }
        }
        printf("punkt%d", i + 1);
        printf("\n--+--+--+--+--+\n");
    }
    printf("\ncandidate 2 in punkt #%d, %d votes",place_2,max_2);
    printf("\ncandidate 4 in punkt #%d, %d votes\n",place_4,max_4);
    system("pause");
    return 0;
}