#include <stdio.h>
#include <math.h>

short line(int x, int y, float *r);

int main(void){
    short type;
    int x, y;
    float r;
    printf("Podaj wspolrzedne x oraz y punktu: ");
    scanf("%d%d", &x, &y);
    type=line(x, y, &r);
    switch(type){
        case 0:
            printf("Punkt sie znajduje na osi wspolrzednych\n");
            break;
        case 1:
        case 2:
        case 3:
        case 4:
            printf("Punkt sie znajduje w %hd cwiarce.\n", type);
    }
    printf("Odleglosc punktu od poczatku ukladu wspolrzednych: %f", r);
    return 0;
}

short line(int x, int y, float *r){
    *r=sqrtf(powf(x, 2)+powf(y, 2));
    if(x==0 || y==0) return 0;
    if(x>0){
        if(y>0) return 1;
        return 4;
    }
    if(y>0) return 2;
    return 3;
}
