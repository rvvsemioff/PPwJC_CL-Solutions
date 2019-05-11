#include <stdio.h>

long long twomax(long long *smax);

int main(void){
    long long smax;
    printf("Pierwsza najwieksza liczba - %lld.\n", twomax(&smax));
    printf("Druga najwieksza liczba - %lld.", smax);
    return 0;
}

long long twomax(long long *smax){
    int N;
    long long max, tr;
    while(1){
        printf("Podaj ilosc roznych liczb (conajmniej dwie): ");
        scanf("%d", &N);
        if(N>1) break;
        printf("Niewlasciwy wybor!\n");
    }
    printf("Podaj liczbe: ");
    scanf("%lld", &max);
    while(1){
        printf("Podaj liczbe: ");
        scanf("%lld", &tr);
        if(tr>max){
            *smax=max;
            max=tr;
            break;
        }
        else if(tr!=max){
            *smax=tr;
            break;
        }
        else printf("Niewlasciwy wybor!\n");
    }
    for(; N-2; N--){
        printf("Podaj liczbe: ");
        scanf("%lld", &tr);
        if(tr==max || tr==*smax){
            N++;
            printf("Niewlasciwy wybor!\n");
            continue;
        }
        if(tr>max){
            *smax=max;
            max=tr;
            continue;
        }
        if(tr>*smax) *smax=tr;
    }
    return max;
}
