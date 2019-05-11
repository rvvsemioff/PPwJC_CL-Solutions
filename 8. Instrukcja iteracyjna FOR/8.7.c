#include <stdio.h>
#include <inttypes.h>

int32_t factorial(uint8_t n);

int main(void){
    uint8_t n;
    printf("Podaj liczbe od 0 do 12: ");
    scanf("%"SCNu8, &n);
    if(n>12){
        printf("Niewlasciwe dane!");
        return 0;
    }
    printf("n! = %"PRId32".", factorial(n));
    return 0;
}

int32_t factorial(uint8_t n){
    int32_t result=1;
    if(n==0) return 1;
    for(; n; n--){
        result*=n;
    }
    return result;
}
