#include <stdio.h>

int check(float x,float y);

int main(void)
{
    float x,y;
    printf("Podaj wspolrzedne x, y punktu: ");
    scanf("%f%f", &x, &y);
    if(check(x,y)) printf("Punkt o wspolrzednych %0.3f, %0.3f nalezy do obszaru",x,y);
    else printf("Punkt o wspolrzednych %0.3f, %0.3f nie nalezy do obszaru",x,y);
    return 0;
}

int check(float x,float y){
    return (x>-1&&x<1&&y>-1&&y<1)?1:0;
}
