#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
Задано символьні рядки. Рядок, який складається із декількох послідовностей символів (наборів символів), які 
розділяються не менше ніж одним символом пробілу (' ').  Для кожного рядка знайти послідовності символів у яких є
5)	ідентифікатори;
*/
int IS_Letter(char s)
{
    if (((s >= 'A') && (s <= 'Z')) || ((s >= 'a') && (s <= 'z')))
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
int main()
{
    FILE *in_file = fopen("task_14_3in.txt", "r");
    if (in_file == NULL)
        exit(1);
    else
    {
        char ident[100];
        printf("Enter ident\n");
        fflush(stdin);
        gets(ident);
        char s[100];
        int k = 0;
        int j, g = 0, f = 0, p = 0;
        while (!feof(in_file))
        {
            fgets(s, 100, in_file);
            k =0;
            for (int i = 0; i < strlen(s); i++)
            { 
                if (IS_Letter(s[i]) == 1)
                {
                    k = i + 1;
                }
                else
                {
                    if (s[i] == ident[0])
                    {
                        p = 0;
                        j = i;
                        while (g < strlen(ident))
                        {
                            if (s[j] == ident[g])
                                p = 1;
                            else
                            {
                                p = 0;
                                break;
                            }
                            j++;
                            g++;
                        }
                        g = 0;
                        if (p == 1)
                        {

                            while (IS_Letter(s[k]) == 0)
                            {
                                printf("%c", s[k]);
                                k++;
                            }
                            i = k - 1;

                            printf(" ");
                        }
                    }
                }
            }
            printf("\n");
        }
    }
    system("pause");
    return 0;
}