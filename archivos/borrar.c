#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char **argv){
    char *file1=argv[1];
    char *pwd = getcwd(NULL,0);
    char path1[strlen(file1)+strlen(pwd)+2];
    sprintf(path1,"%s/%s",pwd,file1);
    printf("%s/%s\n",pwd,file1);
    unlink(path1);
    return 0;
}