#include "data_input.h"
#include <limits.h>

void generate_data(int **numbers, unsigned char count);
void print_data(int numbers[], unsigned char count);
void write_data(int numbers[], unsigned char count);
void append_data(int numbers[], unsigned char count);
unsigned char read_data(int **numbers);
void seek_data(int numbers[], unsigned char count);

int main(void){
    unsigned char  count, user_count, is_data=0;
    int *numbers;
    SetConsoleCP(1250);
    SetConsoleOutputCP(1250);
    user_count=input("WprowadŸ iloœæ liczb ca³kowitych", 0, UCHAR_MAX);
    while(1){
        switch(input("Wygeneruj (1), zapisz (2), dopisz (3), odczytaj (4) dane, wyœwietl element pliku na podanej pozycji (5) lub wyjdŸ (6)", 0, 7)){
        case 1:
            if(is_data) free(numbers);
            count=user_count;
            generate_data(&numbers, count);
            is_data=1;
            puts("Wygenerowano dane:\n");
            print_data(numbers, count);
            break;
        case 2:
            if(is_data){
                write_data(numbers, count);
                puts("Zapisano dane.\n");
            }
            else puts("Nie ma danych do zapisu.\n");
            break;
        case 3:
            if(is_data){
                append_data(numbers, count);
                puts("Dopisano dane.\n");
            }
            else puts("Nie ma danych do dopisywania.\n");
            break;
        case 4:
            if(is_data) free(numbers);
            count=read_data(&numbers);
            is_data=1;
            puts("Odczytano dane:\n");
            print_data(numbers, count);
            break;
        case 5:
            seek_data(numbers, count);
            break;
        default:
            if(is_data) free(numbers);
            return EXIT_SUCCESS;
        }
    }
}

void generate_data(int **numbers, unsigned char count){
    int *try_p;
    while(1){
        try_p=malloc(count*sizeof(int));
        if(try_p!=NULL) break;
    }
    *numbers=try_p;
    srand(time(NULL));
    for(unsigned char i=0; i<count; ++i) (*numbers)[i]=(int)random(INT_MAX);
}

void print_data(int numbers[], unsigned char count){
    for(unsigned char i=0; i<count; ++i) printf("%d\n", numbers[i]);
    puts("");
}

void write_data(int numbers[], unsigned char count){
    FILE *f_p=fopen("data.qt", "wb");
    if(f_p==NULL) exit(1);
    for(unsigned char i=0; i<count; ++i) fprintf(f_p, "%d\t", numbers[i]);
    if(fclose(f_p)==EOF) exit(2);
}

void append_data(int numbers[], unsigned char count){
    FILE *f_p=fopen("data.qt", "ab");
    if(f_p==NULL) exit(1);
    for(unsigned char i=0; i<count; ++i) fprintf(f_p, "%d\t", numbers[i]);
    if(fclose(f_p)==EOF) exit(2);
}

unsigned char read_data(int **numbers){
    unsigned char i;
    int *try_p, buffer[UCHAR_MAX];
    FILE *f_p=fopen("data.qt", "rb");
    if(f_p==NULL) exit(1);
    for(i=0; ; ++i){
        if(feof(f_p)) break;
        fscanf(f_p, "%d\t", &buffer[i]);
    }
    if(fclose(f_p)==EOF) exit(2);
    while(1){
        try_p=malloc(i*sizeof(int));
        if(try_p!=NULL) break;
    }
    *numbers=try_p;
    for(unsigned char j=0; j<=i; ++j) (*numbers)[j]=buffer[j];
    return i;
}

void seek_data(int numbers[], unsigned char count){
    char c_read;
    int read, position=input("WprowadŸ ¿¹dan¹ pozycjê", -1, INT_MAX);
    FILE *f_p=fopen("data.qt", "rb");
    if(f_p==NULL) exit(1);
    fseek(f_p, position, SEEK_SET);
    fscanf(f_p, "%c", &c_read);
    while(1){
        if(position==0||c_read=='\t') break;
        --position;
        fseek(f_p, -1, SEEK_CUR);
        fscanf(f_p, "%c", &c_read);
        fseek(f_p, -1, SEEK_CUR);
    }
    fscanf(f_p, "%d", &read);
    printf("Na danej pozycji odczytano wartoœæ %d.\n\n", read);
    if(fclose(f_p)==EOF) exit(2);
}
