#include "data_input.h"
#include <limits.h>
#define COUNT 100

struct merch{
    char name[30];
    char country[30];
    short size;
};

void generate_data(struct merch exports[], unsigned char count);
void print_data(struct merch exports[], unsigned char count);
void write_data(struct merch exports[], unsigned char count);
void read_data(struct merch exports[], unsigned char count);
void examine_data(struct merch exports[], unsigned char count);

int main(void){
    unsigned char count=COUNT, is_data=0;
    struct merch *exports;
    while(1){
        exports=malloc(count*sizeof(struct merch));
        if(exports!=NULL) break;
    }
    SetConsoleCP(1250);
    SetConsoleOutputCP(1250);
    while(1){
        switch(input("Wygeneruj (1), zapisz (2), odczytaj (3) dane eksportowanych towarów, wyœwietl wielkoœæ i podzia³ eksportu (4) lub wyjdŸ (5)", 0, 6)){
        case 1:
            generate_data(exports, count);
            is_data=1;
            puts("Wygenerowano dane eksportu:\n");
            print_data(exports, count);
            break;
        case 2:
            if(is_data){
                write_data(exports, count);
                puts("Zapisano dane.\n");
            }
            else puts("Nie ma danych do zapisu.\n");
            break;
        case 3:
            read_data(exports, count);
            is_data=1;
            puts("Odczytano dane:\n");
            print_data(exports, count);
            break;
        case 4:
            if(is_data) examine_data(exports, count);
            else puts("Nie ma danych do opracowania.\n");
            break;
        default:
            free(exports);
            return EXIT_SUCCESS;
        }
    }
}

void generate_data(struct merch exports[], unsigned char count){
    char countries[10][30]={"Dania", "Czechy", "Chiny", "Francja", "Izrael", "Japonia", "Niemcy", "Nowa Zelandia", "Norwegia", "Rosja"};
    srand(time(NULL));
    for(unsigned char i=0; i<count; ++i){
        generate_name(exports[i].name, 30, 1);
        strcpy(exports[i].country, countries[(short)random(10)]);
        exports[i].size=(short)random(SHRT_MAX);
    }
}

void print_data(struct merch exports[], unsigned char count){
    for(unsigned char i=0; i<count; ++i) printf("%hhu:\tNazwa - %s\n"
                                                "\tKraj - %s\n"
                                                "\tWielkoœæ - %hd\n\n", i+1, exports[i].name, exports[i].country, exports[i].size);
}

void write_data(struct merch exports[], unsigned char count){
    FILE *f_p=fopen("export.d", "wb");
    if(f_p==NULL) exit(1);
    fwrite(exports, sizeof(struct merch), count, f_p);
    if(fclose(f_p)==EOF) exit(2);
}

void read_data(struct merch exports[], unsigned char count){
    FILE *f_p=fopen("export.d", "rb");
    if(f_p==NULL) exit(1);
    fread(exports, sizeof(struct merch), count, f_p);
    if(fclose(f_p)==EOF) exit(2);
}

void examine_data(struct merch exports[], unsigned char count){
    char countries[10][30]={"Dania", "Czechy", "Chiny", "Francja", "Izrael", "Japonia", "Niemcy", "Nowa Zelandia", "Norwegia", "Rosja"};
    unsigned char c_count[10]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    long all_size=0;
    for(unsigned char i=0; i<count; ++i){
        all_size+=exports[i].size;
        for(unsigned char j=0; j<10; ++j){
            if(strcmp(countries[j], exports[i].country)==0){
                ++c_count[j];
                break;
            }
        }
    }
    printf("Ogólna wielkoœæ eksportu/importu: %ld\n", all_size);
    puts("Eksport w poszczególnych krajach:\n");
    for(unsigned char i=0; i<10; ++i) printf("%s - %hhu\n", countries[i], c_count[i]);
    puts("");
}
