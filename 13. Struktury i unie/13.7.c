#include <windows.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct PozycjaPlanu{
    unsigned char day;
    unsigned char s_hour;
    unsigned char e_hour;
    char classes[50];
    char teacher[25];
    unsigned char room;
};

void show_by_day(struct PozycjaPlanu schedule[], unsigned char count);
void show_by_class(struct PozycjaPlanu schedule[], unsigned char count);
unsigned char count_8_am(struct PozycjaPlanu schedule[], unsigned char count);

int main(void){
    struct PozycjaPlanu *schedule, *buf;
    unsigned char count=0;
    while(1){
        schedule=malloc(30*sizeof(struct PozycjaPlanu));
        if(schedule!=NULL) break;
    }
    SetConsoleCP(1250);
    SetConsoleOutputCP(1250);
    srand(time(NULL));
    for(unsigned char i=1; i<6; ++i){
        for(unsigned char j=0; j<6; ++j){
            if(round(((double)rand()/RAND_MAX)*3)==2){
                unsigned char l_c=0;
                schedule[count].day=i;
                schedule[count].s_hour=(2*j)+8;
                schedule[count].e_hour=schedule[count].s_hour+2;
                schedule[count].classes[0]=(char)round(((double)rand()/RAND_MAX)*25)+'A';
                for(unsigned char k=1; k<=(unsigned char)round(((double)rand()/RAND_MAX)*48); ++k){
                    if((unsigned char)round(((double)rand()/RAND_MAX)*5)==5 && schedule[count].classes[k-1]!=' ') schedule[count].classes[k]=' ';
                    else schedule[count].classes[k]=(char)round(((double)rand()/RAND_MAX)*25)+'a';
                    l_c=k;
                }
                schedule[count].classes[l_c+1]='\0';
                l_c=0;
                schedule[count].teacher[0]=(char)round(((double)rand()/RAND_MAX)*25)+'A';
                schedule[count].teacher[1]='.';
                schedule[count].teacher[2]=' ';
                schedule[count].teacher[3]=(char)round(((double)rand()/RAND_MAX)*25)+'A';
                for(unsigned char k=4; k<=(unsigned char)round(((double)rand()/RAND_MAX)*20); ++k){
                    schedule[count].teacher[k]=(char)round(((double)rand()/RAND_MAX)*25)+'a';
                    l_c=k;
                }
                schedule[count].teacher[l_c+1]='\0';
                schedule[count].room=(unsigned char)(((double)rand()/RAND_MAX)*250)+1;
                ++count;
            }
        }
    }
    while(1){
        buf=realloc(schedule, count*sizeof(struct PozycjaPlanu));
        if(buf!=NULL){
            schedule=buf;
            break;
        }
    }
    show_by_day(schedule, count);
    show_by_class(schedule, count);
    printf("\n%hhu razy w tygodniu rozpoczynasz zajêcia o 8 rano.\n", count_8_am(schedule, count));
    free(schedule);
    return 0;
}

void show_by_day(struct PozycjaPlanu schedule[], unsigned char count){
    unsigned char input, is_hollow=0;
    puts("Wybierz dzieñ tygodnia:");
    puts("1 - Poniedzia³ek");
    puts("2 - Wtorek");
    puts("3 - Œroda");
    puts("4 - Czwartek");
    puts("5 - Pi¹tek");
    while(1){
        printf(":");
        scanf("%hhu", &input);
        if(input>0 && input<6) break;
        puts("Niew³aœciwa wartoœæ!");
    }
    for(unsigned char i=0; i<count; ++i){
        if(schedule[i].day==input){
            switch(schedule[i].day){
            case 1:
                printf("\nPoniedzia³ek");
                break;
            case 2:
                printf("\nWtorek");
                break;
            case 3:
                printf("\nŒroda");
                break;
            case 4:
                printf("\nCzwartek");
                break;
            case 5:
                printf("\nPi¹tek");
            }
            printf(" - od %hhu do %hhu:\n", schedule[i].s_hour, schedule[i].e_hour);
            printf("%s - %s - sala numer %hhu\n", schedule[i].classes, schedule[i].teacher, schedule[i].room);
            is_hollow=1;
        }
        else if(is_hollow) break;
    }
    if(!is_hollow) puts("Na podany dzieñ nie zapisano ¿adnych zajêæ.");
    fflush(stdin);
}

void show_by_class(struct PozycjaPlanu schedule[], unsigned char count){
    unsigned char is_hollow=0;
    char sel_classes[50], buf[50];
    printf("\nWybierz zajêcie:\n");
    for(unsigned char i=0; i<count; ++i){
        printf("\"%s\"", schedule[i].classes);
        if(i!=count-1) printf(", ");
        else puts(".");
    }
    printf("\nWprowad¿ nazwê zajêcia: ");
    fgets(sel_classes, 50, stdin);
    for(unsigned char i=0; i<count; ++i){
        strcpy(buf, schedule[i].classes);
        strcat(buf, "\n");
        if(strcmp(sel_classes, buf)==0){
            switch(schedule[i].day){
            case 1:
                printf("\nPoniedzia³ek");
                break;
            case 2:
                printf("\nWtorek");
                break;
            case 3:
                printf("\nŒroda");
                break;
            case 4:
                printf("\nCzwartek");
                break;
            case 5:
                printf("\nPi¹tek");
            }
            printf(" - od %hhu do %hhu:\n", schedule[i].s_hour, schedule[i].e_hour);
            printf("%s - %s - sala numer %hhu\n", schedule[i].classes, schedule[i].teacher, schedule[i].room);
            is_hollow=1;
        }
        else if(is_hollow) break;
    }
    if(!is_hollow) puts("Nie zapisano ¿adnych zajêæ z podanego przedmiotu.");
    fflush(stdin);
}

unsigned char count_8_am(struct PozycjaPlanu schedule[], unsigned char count){
    unsigned char c=0;
    for(unsigned char i=0; i<count; ++i){
        if(schedule[i].s_hour==8) ++c;
    }
    return c;
}
