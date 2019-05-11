#include <stdio.h>

void scholarship(float m1, float m2, float m3);

int main(void)
{
    float m1,m2,m3;
    printf("Podaj trzy oceny: ");
    scanf("%f%f%f",&m1,&m2,&m3);
    scholarship(m1,m2,m3);
    return 0;
}

void scholarship(float m1, float m2, float m3){
    if(m1>=3&&m2>=3&&m3>=3){
        float mid=(m1+m2+m3)/3;
        if(mid>4) printf("Stypendia wynosi 500 zl.");
        else if(mid>3) printf("Stypendia wynosi 300 zl.");
        else printf("Stypendia nie moze byc przyznana.");
    }
    else printf("Stypendia nie moze byc przyznana.");
}
