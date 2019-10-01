#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int forever=1;

void signal_handler(int signal){

    printf("Received signal: %d\n",signal);
    forever = 0;

}

int main(){
    int pid;
    signal(10, signal_handler);
    pid = fork();
    if(pid == 0){
        // soy el hijo

        printf("soy el hijo\n");
        // codigo que quiero que haga el hijo
        while(forever){

        }
        printf("saliendo del while infinito \n");

    } else{
        printf("soy el padre y mi hijo es: %d\n",pid);
        sleep(5);
        kill(pid, 10);
        // codigo del padre
        for(;;){}
    }
}