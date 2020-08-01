#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*Задано текст, слова в якому розділені пробілами і розділовими знаками. Розробити програму, яка вилучає в кожному 
слові цього тексту всі наступні входження першої літери. */
char Letter_def(char s)
{
    if ((s < 'A') || ((s > 'Z') && (s < 'a')) || (s > 'z'))
        return 1;
    else if (s >= 'A' && s <= 'Z')
        return s + 32;
    else
        return s;
}
int main()
{
    char s[100];
    printf("Text :\n");
    fflush(stdin);
    gets(s);
    char buf = 1, buf_capital = 1; int i = 0;
    while (buf == 1)
    {
       buf =Letter_def(s[i]);
       i++;
    } 
    char *b;
    b = (char*)malloc(strlen(s)*sizeof(char));
    int k =0;
    buf_capital = buf - 32;
    int counter = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        if((s[i] == buf) || (s[i] == buf_capital)) 
        {
            counter++;
        }
        else
        {
            b[k++] = s[i];
            
        }
    }
    b = (char*)realloc(b,(k+1)*sizeof(char));
    b[k+1] = '\0';
    strcpy(s,b);
    s[k] = '\0';
    printf("\n");
    puts(s);
    system("pause");
    return 0;
}