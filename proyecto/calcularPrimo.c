#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

//pipe
/*
./generador |./calcularPrimo|./calcularPrimo |./calcularPrimo|./calcularPrimo|./calcularPrimo|./calcularPrimo|./calcularPrimo|./calcularPrimo|./calcularPrimo|./calcularPrimo|./calcularPrimo|./calcularPrimo|./calcularPrimo|./calcularPrimo|./calcularPrimo|./calcularPrimo|./calcularPrimo|./calcularPrimo|./calcularPrimo|./calcularPrimo|./calcularPrimo|./calcularPrimo|./calcularPrimo|./calcularPrimo
*/
int main(int argc,char** argv){
    char num[3];
    char valorMax[3];

    read(0, num, sizeof(num));
    int nPrimo = atoi(num);
    fprintf(stderr, "%d ",nPrimo);
    read(0, num, sizeof(num));
    int n = atoi(num);

    while (n!=-1) {
        if( n%nPrimo  != 0){

            sprintf(num, "%d", n);
            write(1, num, sizeof(num));
        }
        read(0,num,sizeof(num));
        n=atoi(num);
    }
    int temp = -1;
    sprintf(valorMax,"%d" , temp);
    write(1,valorMax,sizeof(valorMax));

    return 0;
}