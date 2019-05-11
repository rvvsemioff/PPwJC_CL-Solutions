#include <stdio.h>
#include <string.h>

void triple_tree(int a, int b, int c, int n, char *triples);

int main(void){
    int n, l, str=0, end;
    for(; ; ){
        printf("Podaj ilosc trojek pitagorejskich i gorna granice liczb (jedna liczba): ");
        scanf("%d", &n);
        if(n<10 || n>200) printf("Niewlasciwy wybor!\n");
        else break;
    }
    char triples[309];
    strcpy(triples, "\n3 4 5\n");
    triple_tree(3, 4, 5, n, triples);
    printf("%s\nKolejnosc odwrotna:\n\n", triples);
    l=strlen(triples);
    end=l-1;
    for(int i=l-2; i>=0; i--){
        if(triples[i]=='\n' || triples[i]=='\0'){
            str=i+1;
            for(int j=str; j<end; j++){
                printf("%c", triples[j]);
            }
            printf("\n");
            end=i;
        }
    }
}

void triple_tree(int a, int b, int c, int n, char *triples){
    int d, e, f;
    char buf[13];
    d=a-2*b+2*c;
    e=2*a-b+2*c;
    f=2*a-2*b+3*c;
    if(d<n && e<n && f<n){
        sprintf(buf, "%d %d %d\n", d, e, f);
        strcat(triples, buf);
        triple_tree(d, e, f, n, triples);
    }
    d=a+2*b+2*c;
    e=2*a+b+2*c;
    f=2*a+2*b+3*c;
    if(d<n && e<n && f<n){
        sprintf(buf, "%d %d %d\n", d, e, f);
        strcat(triples, buf);
        triple_tree(d, e, f, n, triples);
    }
    d=-a+2*b+2*c;
    e=-2*a+b+2*c;
    f=-2*a+2*b+3*c;
    if(d<n && e<n && f<n){
        sprintf(buf, "%d %d %d\n", d, e, f);
        strcat(triples, buf);
        triple_tree(d, e, f, n, triples);
    }
}
