#include "data_input.h"

void generate_data(float **measurement, unsigned char count);
void print_data(float *measurement, unsigned char count);
void write_data(float *measurement, unsigned char count);
void append_data(float *measurement, unsigned char count);
unsigned char read_data(float **measurement);
float count_mean(float *measurement, unsigned char count);

int main(void){
    unsigned char user_count, count, is_data=0;
    float *measurement;
    SetConsoleCP(1250);
    SetConsoleOutputCP(1250);
    user_count=input("WprowadŸ liczbê pomiarów", 0, 255);
    while(1){
        switch(input("Wygeneruj (1), zapisz (2), dopisz (3), odczytaj (4) dane, oblicz œredni¹ arytmetyczn¹ (5) lub wyjdŸ (6)", 0, 7)){
        case 1:
            count=user_count;
            if(is_data) free(measurement);
            generate_data(&measurement, count);
            is_data=1;
            puts("Wygenerowano dane:\n");
            print_data(measurement, count);
            break;
        case 2:
            if(is_data){
                write_data(measurement, count);
                puts("Zapisano dane\n");
            }
            else puts("Nie ma danych!\n");
            break;
        case 3:
            if(is_data){
                append_data(measurement, count);
                puts("Dopisano dane\n");
            }
            else puts("Nie ma danych!\n");
            break;
        case 4:
            if(is_data) free(measurement);
            count=read_data(&measurement);
            is_data=1;
            puts("Odczytano dane:\n");
            print_data(measurement, count);
            break;
        case 5:
            if(is_data) printf("Œrednia arytmetyczna z pomiarów: %0.2f\n\n", count_mean(measurement, count));
            else puts("Nie ma danych!\n");
            break;
        default:
            if(is_data) free(measurement);
            return EXIT_SUCCESS;
        }
    }
}

void generate_data(float **measurement, unsigned char count){
    float *try_p;
    while(1){
        try_p=malloc(count*sizeof(float));
        if(try_p!=NULL) break;
    }
    *measurement=try_p;
    srand(time(NULL));
    for(unsigned char i=0; i<count; ++i) (*measurement)[i]=random(600)*0.01f+34.0f;
}

void print_data(float *measurement, unsigned char count){
    for(unsigned char i=0; i<count; ++i) printf("%0.2f\n", measurement[i]);
    puts("");
}

void write_data(float *measurement, unsigned char count){
    FILE *f_p=fopen("data.ini", "w");
    if(f_p==NULL) exit(2);
    for(unsigned char i=0; i<count; ++i) fprintf(f_p, "%f\t", measurement[i]);
    if(fclose(f_p)==EOF) exit(3);
}

void append_data(float *measurement, unsigned char count){
    FILE *f_p=fopen("data.ini", "a");
    if(f_p==NULL) exit(2);
    for(unsigned char i=0; i<count; ++i) fprintf(f_p, "%f\t", measurement[i]);
    if(fclose(f_p)==EOF) exit(3);
}

unsigned char read_data(float **measurement){
    unsigned char i;
    float *try_p, buffer[255];
    FILE *f_p=fopen("data.ini", "r");
    if(f_p==NULL) exit(2);
    for(i=0; ; ++i){
        if(feof(f_p)) break;
        fscanf(f_p, "%f\t", &buffer[i]);
    }
    if(fclose(f_p)==EOF) exit(3);
    while(1){
        try_p=malloc(i*sizeof(float));
        if(try_p!=NULL) break;
    }
    *measurement=try_p;
    for(unsigned char j=0; j<=i; ++j) (*measurement)[j]=buffer[j];
    return i;
}

float count_mean(float *measurement, unsigned char count){
    double mean=0.0;
    for(unsigned char i=0; i<count; ++i) mean+=measurement[i];
    return mean/count;
}
