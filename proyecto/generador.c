#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <math.h>

int main(int argc,char** argv){


    int i;
    char num[3];
    for(i=2;i<101;i++){
        sprintf(num, "%d", i);
        // Write numbers
        write(1, num, sizeof(num));
    }
    sprintf(num, "%d", -1);
    write(1, num, sizeof(num));



    return 0;
}