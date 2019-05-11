#include <stdio.h>
#include <stdlib.h>
#include <string.h>

short cramer(int a1, int a2, int b1, int b2, int c1, int c2, float *x, float *y);

int main(void){
    int a1, a2, b1, b2, c1, c2, str, sigh, step;
    float x, y;
    char num[9]="pierwsze", eq[24], buf1[6], buf2[2];
    for(int i=0; i<2; i++){
        printf("Podaj %s rownanie liniowe:\n", num);
        scanf("%s", &eq);
        str=0;
        sigh=1;
        step=1;
        for(int i=0; i<=strlen(eq); i++){
            switch(step){
                case 1:
                    if(eq[i]=='-'){
                        sigh=-1;
                        str=i+1;
                    }
                    else if(eq[i]=='x'){
                        if(i==str){
                            a1=sigh;
                            step=2;
                        }
                        else{
                            strcpy(buf1, "");
                            for(int j=str; j<i; j++){
                                sprintf(buf2, "%c", eq[j]);
                                strcat(buf1, buf2);
                            }
                            a1=strtol(buf1, NULL, 10)*sigh;
                            step=2;
                        }
                    }
                    break;
                case 2:
                    if(eq[i]=='+'){
                        sigh=1;
                        step=3;
                    }
                    else if(eq[i]=='-'){
                        sigh=-1;
                        step=3;
                    }
                case 3:
                    if(eq[i]=='0' || eq[i]=='1' || eq[i]=='2' || eq[i]=='3' || eq[i]=='4' || eq[i]=='5' || eq[i]=='6' || eq[i]=='7' || eq[i]=='8' || eq[i]=='9'){
                        str=i;
                        step=4;
                    }
                    else if(eq[i]=='y'){
                        b1=sigh;
                        step=5;
                    }
                    break;
                case 4:
                    if(eq[i]=='y'){
                        strcpy(buf1, "");
                        for(int j=str; j<i; j++){
                            sprintf(buf2, "%c", eq[j]);
                            strcat(buf1, buf2);
                        }
                        b1=strtol(buf1, NULL, 10)*sigh;
                        step=5;
                    }
                    break;
                case 5:
                    if(eq[i]=='-'){
                        sigh=-1;
                        str=i;
                    }
                    else if(eq[i]=='0' || eq[i]=='1' || eq[i]=='2' || eq[i]=='3' || eq[i]=='4' || eq[i]=='5' || eq[i]=='6' || eq[i]=='7' || eq[i]=='8' || eq[i]=='9'){
                        str=i;
                        sigh=1;
                        step=6;
                    }
                    break;
                case 6:
                    if(eq[i]=='\0'){
                        strcpy(buf1, "");
                        for(int j=str; j<i; j++){
                            sprintf(buf2, "%c", eq[j]);
                            strcat(buf1, buf2);
                        }
                        c1=strtol(buf1, NULL, 10)*sigh;
                        step=0;
                    }
            }
        }
        if(step==0){
            if(i==0){
                strcpy(num, "drugie");
                a2=a1;
                b2=b1;
                c2=c1;
            }
            continue;
        }
        printf("Niewlasciwe rownanie!\n");
        i--;
    }
    switch(cramer(a1, a2, b1, b2, c1, c2, &x, &y)){
        case -1:
            printf("Uklad jest sprzeczny.");
            break;
        case 0:
            printf("Uklad jest nieoznaczony.");
            break;
        case 1:
            printf("x = %f\ny = %f", x, y);
    }
    return 0;
}

short cramer(int a1, int a2, int b1, int b2, int c1, int c2, float *x, float *y){
    int w, wx, wy;
    w=a1*b2-a2*b1;
    wx=c1*b2-c2*b1;
    wy=a1*c2-a2*c1;
    if(w==0 && wx==0 && wy==0) return 0;
    if(w==0) return -1;
    *x=wx/w;
    *y=wy/w;
    return 1;
}
