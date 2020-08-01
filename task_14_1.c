#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
// #include <time.h>
/*5.	Дано рядок S. Перевірити баланс дужок в ньому. Вивести повідомлення про виконання.
Вхідні дані: S ="2*X1+(3*X2/(X2+3*X1)/(X2+25*X".
Вихідні дані: "В даному рядку більше символів "(" на 2 одиниці
*/
int main()
{
    char s[100];

    printf("Text:\n");
    gets(s);
    int counter_open = 0, counter_cl = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == ')' ||
            s[i] == '}' ||
            s[i] == ']')
            counter_cl++;

        if (s[i] == '(' ||
            s[i] == '{' ||
            s[i] == '[')
            counter_open++;
    }
    int f = 0;
    if (counter_open != counter_cl)
        f = 1;
    int l1 = 0, l2 = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == ')' ||
            s[i] == '}' ||
            s[i] == ']')
            l1++;
        if (l1 > l2)
        {
            printf("-_- NO \")\" > na %d", counter_cl - counter_open);
            f = 0;
            break;
        }
        else if (l2 == l1 && i == strlen(s) - 1)
            printf("Balanced");
        if (s[i] == '(' ||
            s[i] == '{' ||
            s[i] == '[')
            l2++;
    }
    if (f == 1)
        printf("-_- NO \"(\" > na %d",  counter_open - counter_cl );
    getch();
    return 0;
}