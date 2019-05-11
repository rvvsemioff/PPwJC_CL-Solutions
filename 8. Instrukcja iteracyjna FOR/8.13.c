#include <stdio.h>
#include <string.h>
#include <math.h>

void automorphic(void);
void prime(void);
void pythagorean(long long a, long long b, long long c, long long m, long long n);

int main(void){
    int c;
    long long m, n;
    for(; ; ){
        printf("Wybierz wyznaczanie liczb:\n1: automorficznych\n2: pierwszych\n3: pitagorejskich\n");
        scanf("%d", &c);
        switch(c){
            case 1:
                automorphic();
                return 0;
            case 2:
                prime();
                return 0;
            case 3:
                for(; ; ){
                    printf("Podaj przedzial <m, n>: ");
                    scanf("%lld %lld", &m, &n);
                    if(n>m){
                        pythagorean(3, 4, 5, m, n);
                        return 0;
                    }
                    else printf("Niewlasciwy przedzial!\n");
                }
            default:
                printf("Niewlasciwy wybor!\n");
        }
    }
    return 0;
}

void automorphic(void){
    long long i, i_s, j, t;
    printf("Liczby automorficzne:\n");
    for (i=0; ; i++){
        i_s=powf(i, 2);
        for(t=10; i_s/t>=10; t*=10);
        for(j=i_s; i<=j; j%=t){
            if(i==j){
                printf("%lld\n", i);
                break;
            }
            if(j<10) break;
            if(j!=i_s) t/=10;
        }
    }
}

void prime(void){
    int div;
    long long i, j;
    printf("Liczby pierwsze:\n");
    for(i=2; ; i++){
        div=0;
        for(j=2; j<i; j++) if(i%j==0) div=1;
        if(div==0) printf("%lld\n", i);
    }
}

void pythagorean(long long a, long long b, long long c, long long m, long long n){
    if(a>=m && a<=n && b>=m && b<=n && c>=m && c<=n){
        printf("%lld %lld %lld\n", a, b, c);
        long long d, e, f;
        d=a-2*b+2*c;
        e=2*a-b+2*c;
        f=2*a-2*b+3*c;
        pythagorean(d, e, f, m, n);
        d=a+2*b+2*c;
        e=2*a+b+2*c;
        f=2*a+2*b+3*c;
        pythagorean(d, e, f, m, n);
        d=-a+2*b+2*c;
        e=-2*a+b+2*c;
        f=-2*a+2*b+3*c;
        pythagorean(d, e, f, m, n);
    }
}
