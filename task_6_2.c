#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*Ввести прізвище, ім’я та по батькові як одне дане типу рядок. Визначити довжину рядка і кількість букв «а» у
 ньому. Виконати додатково завдання свого варіанта двома способами:  а) розглядаючи рядок як масив символів; */
int main()
{
    char s[100];
    printf("text:\n");
    gets(s);
    int a_counter = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        if ((s[i] == 'a') || (s[i] == 'A'))
        {
            a_counter++;
        }
    }
    int NAME_position;
    printf("length = %d, num of a = %d\n", strlen(s), a_counter);
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == 32)
        {
            NAME_position = i + 1;
            i++;
            while (s[i] != 32)
            {
                printf("%c", s[i]);
                i++;
            }
            break;
        }
    }
    printf("\nLname length = %d\n",NAME_position-1);
    printf("\n2 case\n");
    {
        char *p=strtok(s," ");
        int i = 0;
        while (p!=NULL)
        {
            if(i == 1) 
                printf("\n%s", p);
            p = strtok (NULL, " ");
            i++;
        }
    }
    char lname[30];
    strcpy(lname,s-(strlen(s)-NAME_position+1));
    printf("\nLname length = %d\n",strlen(lname));
    system("pause");
    return 0;
}