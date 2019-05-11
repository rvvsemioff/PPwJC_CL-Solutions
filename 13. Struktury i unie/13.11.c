#include <windows.h>
#include <math.h>
#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct point{
    int X;
    int Y;
    int Z;
};

unsigned char input(void);
void generate_data(struct point p[], unsigned char N);
double random(int mult);
void calculate_data(struct point p[], unsigned char N);
void print_data(struct point p[], unsigned char N);

int main(void){
    unsigned char N;
    SetConsoleCP(1250);
    SetConsoleOutputCP(1250);
    N=input();
    struct point p[N];
    generate_data(p, N);
    calculate_data(p, N);
    print_data(p, N);
    return 0;
}

unsigned char input(void){
    unsigned char input_val;
    while(1){
        printf("WprowadŸ iloœæ punktów: ");
        scanf("%hhu", &input_val);
        if(input_val>2 && input_val<12) return input_val;
        puts("Niew³aœciwa wartoœæ!");
    }
}

void generate_data(struct point p[], unsigned char N){
    srand(time(NULL));
    for(unsigned char i=0; i<N; ++i) p[i].X=(int)random(10);
}

double random(int mult){
    return round(((double)rand()/RAND_MAX)*mult);
}

void calculate_data(struct point p[], unsigned char N){
    p[0].Y=0;
    p[0].Z=0;
    for(unsigned char i=1; i<N; ++i){
        p[i].Y=p[i].X+2*p[i-1].X;
        p[i].Z=2*(p[i].X+p[i].Y*p[i].Y);
    }
}

void print_data(struct point p[], unsigned char N){
    printf("X(0)=%d i X(-1)=%d: Y[0]=%d;Z[0]=%d\n", p[0].X, 0, p[0].Y, p[0].Z);
    for(unsigned char i=1; i<N; ++i) printf("X(%hhu)=%d i X(%hhu)=%d: Y[%hhu]=%d;Z[%hhu]=%d\n", i, p[i].X, i-1, p[i-1].X, i, p[i].Y, i, p[i].Z);
}
