#include "data_input.h"
#include <limits.h>
#define COUNT 10

struct player{
    char name[15];
    char surname[25];
    long result;
};

void generate_data(struct player participants[], unsigned char count);
void print_data(struct player participants[], unsigned char count);
void write_data(struct player participants[], unsigned char count, char name[]);
void read_data(struct player participants[], unsigned char count, char name[]);
void find_the_best(struct player participants[], unsigned char count);

int main(void){
    unsigned char count=COUNT, is_data=0;
    char name[20];
    struct player *participants;
    while(1){
        participants=malloc(count*sizeof(struct player));
        if(participants!=NULL) break;
    }
    SetConsoleCP(1250);
    SetConsoleOutputCP(1250);
    printf("WprowadŸ nazwê konkurencji: ");
    scanf("%s", &name);
    while(1){
        switch(input("Wygeneruj (1), zapisz (2), odczytaj (3) dane zawodników, wyœwietl dane najlepszych zawodników (4) lub wyjdŸ (5)", 0, 6)){
        case 1:
            generate_data(participants, count);
            is_data=1;
            puts("Wygenerowano dane zawodników:\n");
            print_data(participants, count);
            break;
        case 2:
            if(is_data){
                write_data(participants, count, name);
                puts("Zapisano dane.\n");
            }
            else puts("Nie ma danych do zapisu.\n");
            break;
        case 3:
            read_data(participants, count, name);
            is_data=1;
            puts("Odczytano dane:\n");
            print_data(participants, count);
            break;
        case 4:
            if(is_data) find_the_best(participants, count);
            else puts("Nie ma danych do opracowania.\n");
            break;
        default:
            free(participants);
            return EXIT_SUCCESS;
        }
    }
}

void generate_data(struct player participants[], unsigned char count){
    srand(time(NULL));
    for(unsigned char i=0; i<count; ++i){
        generate_name(participants[i].name, 15, 0);
        generate_name(participants[i].surname, 25, 0);
        participants[i].result=(long)random(LONG_MAX);
    }
}

void print_data(struct player participants[], unsigned char count){
    for(unsigned char i=0; i<count; ++i) printf("%hhu:\tImiê - %s\n"
                                                "\tNazwisko - %s\n"
                                                "\tWynik - %ld\n\n", i+1, participants[i].name, participants[i].surname, participants[i].result);
}

void write_data(struct player participants[], unsigned char count, char name[]){
    FILE *f_p=fopen(name, "wb");
    if(f_p==NULL) exit(1);
    fwrite(participants, sizeof(struct player), count, f_p);
    if(fclose(f_p)==EOF) exit(2);
}

void read_data(struct player participants[], unsigned char count, char name[]){
    FILE *f_p=fopen(name, "rb");
    if(f_p==NULL) exit(1);
    fread(participants, sizeof(struct player), count, f_p);
    if(fclose(f_p)==EOF) exit(2);
}

void find_the_best(struct player participants[], unsigned char count){
    long best[3]={0, 0, 0};
    for(unsigned char i=0; i<count; ++i){
        if(participants[i].result>best[0]) best[0]=participants[i].result;
        else if(participants[i].result>best[1]) best[1]=participants[i].result;
        else if(participants[i].result>best[2]) best[2]=participants[i].result;
    }
    printf("Najlepsze wyniki: %ld, %ld, %ld:\n\n", best[0], best[1], best[2]);
    for(unsigned char i=0; i<3; ++i){
        for(unsigned char j=0; j<count; ++j){
            if(best[i]==participants[j].result){
                printf("%hhu:\tImiê - %s\n\tNazwisko - %s\n", i+1, participants[j].name, participants[j].surname);
                break;
            }
        }
    }
}
