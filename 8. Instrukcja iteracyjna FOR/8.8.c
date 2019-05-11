#include <stdio.h>
#include <inttypes.h>
#include <math.h>

void numbers(void);

int main(void){
    numbers();
    return 0;
}

void numbers(void){
    for(int16_t i=100; i<1000; i++){
        if(i==pow(i/100, 3)+pow((i/10)%10, 3)+pow(i%10, 3)){
            printf("%"PRId16" = %"PRId16"^3 + %"PRId16"^3 + %"PRId16"^3\n", i, i/100, (i/10)%10, i%10);
        }
    }
}
