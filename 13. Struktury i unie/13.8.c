#include <windows.h>
#include <math.h>
#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUMBER 250

struct survey{
    char name[15];
    char surname[25];
    unsigned char street;
    unsigned char house;
    unsigned char flat;
    unsigned char sex;
    unsigned char age;
};

void generate_data(struct survey people[], unsigned char N);
void generate_name(char name[], unsigned char N);
double random(unsigned char mult);
void print(char streets[][25], struct survey people[], unsigned char N);
void write_streets(char streets[][25]);
unsigned char input(char str[], unsigned char bottom, unsigned char top);
unsigned char count_by_house(unsigned char *men, struct survey people[], unsigned char N, unsigned char street, unsigned char house);
unsigned char count_by_street(struct survey people[], unsigned char N, unsigned char street);

int main(void){
    struct survey people[NUMBER];
    char streets[5][25];
    SetConsoleCP(1250);
    SetConsoleOutputCP(1250);
    srand(time(NULL));
    generate_data(people, NUMBER);
    for(unsigned char i=0; i<5; ++i) generate_name(streets[i], 25);
    print(streets, people, NUMBER);
    return 0;
}

void generate_data(struct survey people[], unsigned char N){
    for(unsigned char i=0; i<N; ++i){
        generate_name(people[i].name, 15);
        generate_name(people[i].surname, 25);
        people[i].street=(unsigned char)random(4)+1;
        people[i].house=(unsigned char)random(3)+1;
        people[i].flat=(unsigned char)random(51)+1;
        people[i].sex=(unsigned char)random(1);
        people[i].age=(unsigned char)random(120);
    }
};

void generate_name(char name[], unsigned char N){
    unsigned char l_c=1;
    name[0]=(char)random(25)+'A';
    for(unsigned char i=1; i<(unsigned char)random(N-2); ++i){
        name[i]=(char)random(25)+'a';
        ++l_c;
    }
    name[l_c]='\0';
}

double random(unsigned char mult){
    return round(((double)rand()/RAND_MAX)*mult);
}

void print(char streets[][25], struct survey people[], unsigned char N){
    unsigned char s_input, h_input, women, men=0;
    write_streets(streets);
    s_input=input("Wybierz ulicê za numerem", 0, 6);
    h_input=input("Wybierz dom za numerem (od 1 do 4)", 0, 5);
    women=count_by_house(&men, people, N, s_input, h_input);
    printf("W danym budynku na danej ulice mieszka %hhu kobiet(y) i %hhu mê¿czyzn.\n", women, men);
    write_streets(streets);
    s_input=input("Wybierz ulicê za numerem: ", 0, 6);
    printf("Na danej ulice mieszka %hhu mê¿czyzn w wieku <18 - 60>.\n", count_by_street(people, N, s_input));
}

void write_streets(char streets[][25]){
    for(unsigned char i=0; i<5; ++i){
        printf("%hhu: \"%s\"", i+1, streets[i]);
        if(i!=4) printf(", ");
        else puts(".");
    }
}

unsigned char input(char str[], unsigned char bottom, unsigned char top){
    unsigned char input_val;
    while(1){
        printf("%s: ", str);
        scanf("%hhu", &input_val);
        if(input_val>bottom && input_val<top) return input_val;
        puts("Niew³aœciwa wartoœæ!");
    }
}

unsigned char count_by_house(unsigned char *men, struct survey people[], unsigned char N, unsigned char street, unsigned char house){
    unsigned char women=0;
    for(unsigned char i=0; i<N; ++i){
        if(people[i].street==street && people[i].house==house){
            switch(people[i].sex){
                case 0:
                    ++women;
                    break;
                case 1:
                    ++*men;
            }
        }
    }
    return women;
}

unsigned char count_by_street(struct survey people[], unsigned char N, unsigned char street){
    unsigned char men=0;
    for(unsigned char i=0; i<N; ++i) if(people[i].street==street && people[i].age>17 && people[i].age<61) ++men;
    return men;
}
