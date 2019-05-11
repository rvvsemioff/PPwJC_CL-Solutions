#include <stdio.h>

int price(int hotel, int room, int gastronomy, int days);

int main(void){
    int hotel, room, gastronomy, days;
    printf("Wybierz hotel:\n0 - Richmond Hotel\n1 - Alara Grand Hotel\n2 - Seaworld Hotels & Aquapark\n");
    scanf("%d", &hotel);
    printf("Wybierz typ pokoju:\n0 - jednoosobowy\n1 - dwuosobowy\n2 - rodziny\n");
    scanf("%d", &room);
    printf("Wybierz rodzaj wyzywienia:\n0 - podstawowy\n1 - podstawowy+\n");
    scanf("%d", &gastronomy);
    printf("Podaj liczbe dni: ");
    scanf("%d", &days);
    int pr=price(hotel, room, gastronomy, days);
    if(pr!=0) printf("Cena wybranego wyjazdu stanowi %d zl.", pr);
    else printf("Nieprawidlowe dane!");
    return 0;
}

int price(int hotel, int room, int gastronomy, int days){
    int pr;
    switch(hotel){
        case 0: switch(room){
                case 0: pr=300;
                    break;
                case 1: pr=500;
                    break;
                case 2: pr=700;
                    break;
                default: return 0;
            }
            switch(gastronomy){
                case 0: pr+=200;
                    break;
                case 1: pr+=300;
                    break;
                default: return 0;
            }
            break;
        case 1: switch(room){
                case 0: pr=600;
                    break;
                case 1: pr=800;
                    break;
                case 2: pr=1000;
                    break;
                default: return 0;
            }
            switch(gastronomy){
                case 0: pr+=400;
                    break;
                case 1: pr+=725;
                    break;
                default: return 0;
            }
            break;
        case 2: switch(room){
                case 0: pr=750;
                    break;
                case 1: pr=800;
                    break;
                case 2: pr=915;
                    break;
                default: return 0;
            }
            switch(gastronomy){
                case 0: pr+=100;
                    break;
                case 1: pr+=150;
                    break;
                default: return 0;
            }
            break;
        default: return 0;
    }
    return pr*days;
}
