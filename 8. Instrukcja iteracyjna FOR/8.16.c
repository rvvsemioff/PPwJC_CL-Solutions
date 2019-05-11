#include <stdio.h>
#include <string.h>

void login(void);

int main(void){
    login();
    return 0;
}

void login(void){
    char password[22]="the_greatest_password", login[22], message[50];
    for(int i=0; i<5; i++){
        printf("Podaj haslo: ");
        scanf("%s", &login);
        if(strcmp(password, login)==0){
            printf("Podaj wiadomosc: ");
            scanf("%s", &message);
            for(int j=0; j<strlen(message); j++) message[j]+=19;
            printf("Wiadomosc szyfrowana:\n%s\n", message);
            for(int j=0; j<strlen(message); j++) message[j]-=19;
            printf("Wiadomosc odszyfrowana:\n%s", message);
            break;
        }
        else printf("Niepoprawne haslo.\n");
    }
}
