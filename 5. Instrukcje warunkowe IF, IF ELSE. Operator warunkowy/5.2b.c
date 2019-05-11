#include <stdio.h>
#include <math.h>

int check(float r, float x, float y);

int main(void)
{
    float r,x,y;
    printf("Podaj radius kola: ");
    scanf("%f", &r);
    printf("Podaj wspolrzedne x, y punktu: ");
    scanf("%f%f", &x, &y);
    if(check(r,x,y)) printf("Punkt o wspolrzednych %f, %f nalezy do obszaru",x,y);
    else printf("Punkt o wspolrzednych %f, %f nie nalezy do obszaru",x,y);
    return 0;
}

int check(float r, float x, float y){
    return (sqrtf(powf(x,2)+powf(y,2))<r)?1:0;
}
