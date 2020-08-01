#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*5. Створіть файл дійсних чисел. Підрахуйте кількість елементів файлу, більших за n
(кількість елементів файлу, n та самі елементи вводяться з клавіатури).*/
int main (){
    float *a;
    FILE *file;
    int n,d;
    printf("Enter n & d\n");
    scanf("%d%d",&n,&d);
    file = fopen("D:\\work\\Progrr\\LP\\task_13\\data.txt","w");
    if(file == NULL) exit(1);
    else
    {
    a = (float *)malloc(n*sizeof(float));
    for (int i = 0; i < n; i++)
    {
        printf("%d   > ", i+1);
        scanf("%f",&a[i]);
    }
        // fwrite(&a,sizeof(float), n,file);
        for (int i = 0; i < n; i++)
        {
            fprintf(file,"%.2f ", a[i]);
        }
        
    fclose(file);
    int counter=0;
    file = fopen("D:\\work\\Progrr\\LP\\task_13\\data.txt","r");
    for (int i = 0; i < n; i++)
    {
        fscanf(file,"%f",&a[i]);
        if(a[i]<d) counter++;
        // printf("%f ", a[i]);
    }
    fclose(file);
    printf("\nin file num < %d = %d\n", d, counter);
    }
    system("pause");
    return 0;
}