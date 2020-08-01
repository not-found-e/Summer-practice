#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main (){
    float x,y;
    printf("Enter :\n");
    printf("x : ");
    scanf("%f",&x);
    printf("\ny : ");
    scanf("%f",&y);
    if( (y>0) && (x<0)) 
        printf("NO\n");
    else 
        if((pow(x,2)+pow(y,2)<=4) && (pow(x,2)+pow(y,2)>=1)) 
            printf("YES\n");
        else 
            printf("NO\n");
    system("pause");
    return 0;
}