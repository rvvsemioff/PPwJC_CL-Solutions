#include <stdio.h>

float lumpsum(int period, int power);

int main(void){
    int period, power;
    printf("Wybierz okres:\n0 - limit 300 km\n1 - limit 500 km\n2 - limit 700 km\n");
    scanf("%d", &period);
    printf("Wybierz pojemnosc silnika:\n0 - do 900 cm3\n1 - powyzej 900 cm3\n");
    scanf("%d", &power);
    float lsum=lumpsum(period,power);
    if(lsum!=0) printf("Ryczalt stanowi %0.2f zl.", lsum);
    else printf("Nieprawidlowe dane!");
    return 0;
}

float lumpsum(int period, int power){
    switch(power){
        case 0: switch(period){
                case 0: return 156.42;
                case 1: return 260.7;
                case 2: return 364.98;
                default: return 0;
            }
        case 1: switch(period){
                case 0: return 250.74;
                case 1: return 417.9;
                case 2: return 585.06;
                default: return 0;
            }
        default: return 0;
    }
}
