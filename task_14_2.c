#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*5)	друге найменше за довжиною слово в порядку розташування, якщо їх декілька;*/
int min_2Length(char *s)
{
    int counter = 0, min = strlen(s), min_2 = strlen(s);
    for (int i = 0; i < strlen(s); i++)
    {
        if (((s[i] >= 'A') && (s[i] <= 'Z')) || ((s[i] >= 'a') && (s[i] <= 'z')))
        {
            counter++;
        }
        else if(counter!=0)
        {
            if (counter < min)
            {
                min_2 = min;
                min = counter;
            }
            if (counter < min_2 && counter > min)
                min_2 = counter;
            counter = 0;
        }
    }
    if(counter!=0)
        {
            if (counter < min)
            {
                min_2 = min;
                min = counter;
            }
            if (counter < min_2 && counter > min)
                min_2 = counter;
            counter = 0;
        }
    return min_2;
}
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
    FILE *in_file, *out_file;
    char  s[100];
    in_file = fopen("in.txt", "r");
    out_file = fopen("out.txt", "w");
    if (in_file == NULL)
        exit(1);
    else
    {
        if (out_file == NULL)
        {
            exit(1);
        }
        else
        {
            while (!feof(in_file))
            {
                int min_2_len = 0, k = 0;
                fgets(s, 100, in_file);
                min_2_len = min_2Length(s);
                char word[min_2_len];
                for (int i = 0; i < strlen(s); i++)
                {
                    if (IS_Letter(s[i]) == 0)
                    {
                        word[k++] = s[i];
                    }
                    else if (k == min_2_len)
                    {
                        for (int j = 0; j < min_2_len; j++)
                        {
                            fprintf(out_file,"%c",word[j]);
                        }
                        fprintf(out_file," ");
                        k = 0;
                    }
                    else
                    {
                        k = 0;
                    }
                }
                fprintf(out_file,"\n");
            }
        }
    }
    fclose(in_file);
    fclose(out_file);
    system("pause");
    return 0;
}