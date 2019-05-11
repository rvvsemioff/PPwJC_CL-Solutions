#include <stdio.h>
#include <stdlib.h>

enum mounth{styczen,luty,marzec,kwiecien,maj,czerwiec,lipiec,sierpien,wrzesien,pazdziernik,listopad,grudzien};

void mounth(enum mounth m);

int main(void){
    int m;
    printf("Podaj numer miesiaca: ");
    scanf("%d", &m);
    m--;
    mounth(m);
    return 0;
}

void mounth(enum mounth m){
    switch(m){
        case styczen:
        case luty:
        case marzec: printf("Miesiac nalezy do I-go kwartalu");
            break;
        case kwiecien:
        case maj:
        case czerwiec: printf("Miesiac nalezy do II-go kwartalu");
            break;
        case lipiec:
        case sierpien:
        case wrzesien: printf("Miesiac nalezy do III-go kwartalu");
            break;
        case pazdziernik:
        case listopad:
        case grudzien: printf("Miesiac nalezy do IV-go kwartalu");
            break;
        default: printf("Numer jest niepoprawny.");
            return;
    }
    switch(m){
        case luty: printf(" i zawiera 28 lub 29 dni.");
            break;
        case kwiecien:
        case czerwiec:
        case wrzesien:
        case listopad: printf(" i zawiera 30 dni.");
            break;
        case styczen:
        case marzec:
        case maj:
        case lipiec:
        case sierpien:
        case pazdziernik:
        case grudzien: printf(" i zawiera 31 dni.");
    }
}
