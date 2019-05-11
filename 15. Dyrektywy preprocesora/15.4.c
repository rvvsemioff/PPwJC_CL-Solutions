#include <stdio.h>
#include <stdlib.h>

#define begin {
#define then
#define end }
#define write(x) printf("%s", (x))
#define writeln(x) printf("%d\n", (x))
#define readln(x) scanf("%d", &x)
#define sqr(x) x*x

int main(int argc, char *argv[])
begin
    int a, b;
    write("Podaj a ");
    readln(a);
    write("Podaj b ");
    readln(b);
    write("Podales: ");
    writeln(a);
    writeln(b);
    if(a>b) then begin
        write("a wieksze od b ");
        write("--> Kwadrat a= ");
        writeln(sqr(a));
    end;
    if(a<b) then write("b wieksze od a");
    if(a==b) then write(" a i b takie same");
    return 0;
end
