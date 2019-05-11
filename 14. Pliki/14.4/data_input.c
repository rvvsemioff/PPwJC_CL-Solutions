#include "data_input.h"

unsigned char check_posix(void){
    time_t today=86400;
    if(strcmp(asctime(gmtime(&today)), "Fri Jan 02 00:00:00 1970\n")!=0) return 1;
    return 0;
}

unsigned char input(char str[], unsigned char bottom, unsigned char top){
    unsigned char input_val;
    while(1){
        printf("%s: ", str);
        fflush(stdin);
        scanf("%hhu", &input_val);
        if(input_val>bottom && input_val<top) return input_val;
        puts("Niew³aœciwa wartoœæ!");
    }
}

short define_year(time_t time){
    struct tm *tm_today;
    tm_today=gmtime(&time);
    return (short)(*tm_today).tm_year+1900;
}

void generate_name(char name[], unsigned char N, unsigned char space){
    unsigned char l_c=1;
    name[0]=(char)random(25)+'A';
    for(unsigned char i=1; i<(unsigned char)random(N-2); ++i){
        if(space && name[i-1]!=' ' && (unsigned char)random(5)==4) name[i]=' ';
        else name[i]=(char)random(25)+'a';
        ++l_c;
    }
    name[l_c]='\0';
}

double random(long mult){
    return round(((double)rand()/RAND_MAX)*mult);
}
