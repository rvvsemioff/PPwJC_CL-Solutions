#include <stdio.h>

void service(void);

int main(void){
    service();
    return 0;
}

void service(void){
    int n;
    printf("Witamy w pomocy serwisowej firmy X.\nWyberz tonowo usluge:\n1. zakup towaru\n2. zwrot towaru\n3. serwis techniczny zakupionego urzadzenia\n4. zgloszenie operatora\n");
    scanf("%d",&n);
    switch(n){
        case 1: printf("1. problemy z dostawa\n2. problemy niezgodnosci z zamowieniem\n");
            scanf("%d",&n);
            switch(n){
                case 1: printf("porada 1");
                    return;
                case 2: printf("porada 2");
                    return;
                default: printf("niewlasciwy wybor!");
                    return;
            }
        case 2: printf("porada 3");
            return;
        case 3: printf("1. urzadzanie nie dziala\n2. urzadzenie dzila wadliwie\n");
            scanf("%d",&n);
            switch(n){
                case 1: printf("1. sprawdz czy wlaczone\n2. sprawdz bezpiecznik\n");
                    scanf("%d",&n);
                    switch(n){
                        case 1: printf("wlancz");
                            return;
                        case 2: printf("wymien bezpiecznik na nowy");
                            return;
                        default: printf("niewlasciwy wybor!");
                            return;
                    }
                case 2: printf("1. usterka A\n2. usterka B\n3. usterka C\n");
                    scanf("%d",&n);
                    switch(n){
                        case 1: printf("porada A");
                            return;
                        case 2: printf("porada B");
                            return;
                        case 3: printf("porada C");
                            return;
                        default: printf("niewlasciwy wybor!");
                            return;
                    }
                default: printf("niewlasciwy wybor!");
                    return;
            }
        case 4: printf("odpowiedz operatora");
            return;
        default: printf("niewlasciwy wybor!");
    }
}
