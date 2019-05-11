#include <stdio.h>

void means(void);
void thebiggest(void);
void geoprogression(void);
void check(void);

int main(void){
    int in;
    do{
        printf("1. means()\n2. thebiggest()\n3. geoprogression()\n4. check()\n5. KONIEC\n: ");
        scanf("%d", &in);
        switch(in){
            case 1:
                means();
                break;
            case 2:
                thebiggest();
                break;
            case 3:
                geoprogression();
                break;
            case 4:
                check();
        }
        printf("\n");
    }while(in!=5);
    return 0;
}

void means(void){
    int i, e=0, o=0, even_mean=0, odd_mean=0;
    do{
        printf("Podaj liczbe: ");
        scanf("%d", &i);
        if(i==0) continue;
        if(i%2==0){
            even_mean+=i;
            e++;
        }
        else{
            odd_mean+=i;
            o++;
        }
    } while(i!=0);
    printf("Srednia liczb parzystych: %d.\nSrednia liczb nieparzystych: %d.", (e==0)?0:even_mean/e, (o==0)?0:odd_mean/o);
}

void thebiggest(void){
    double i, b=-1;
    printf("Podaj -1 dla zakonczenia dzilania.\n");
    do{
        printf("Podaj liczbe: ");
        scanf("%lf", &i);
        if(i>b) b=i;
    } while(i!=-1);
    printf("Najwieksza liczba: %lf.", b);
}

void geoprogression(void){
    double b1, b2, q;
    int c=1;
    printf("Podaj b1: ");
    scanf("%lf", &b1);
    printf("Podaj b2: ");
    scanf("%lf", &b2);
    q=b2/b1;
    printf("Podaj zero dla wyjscia.\n");
    do{
        c++;
        b1=b2;
        printf("Podaj nastepna liczba: ");
        scanf("%lf", &b2);
    } while(b2/b1==q&&b2!=0);
    printf("Ilosc liczb tworzacych ciag geometryczny: %d.", c);
}

void check(void){
    int MAX, i=1, sum=0;
    printf("Podaj wartosc MAX: ");
    scanf("%d", &MAX);
    while(sum<=MAX) sum+=i++;
    printf("Nalezy dodac do siebie %d kolejnych liczb calkowitych.", i-2);
}
