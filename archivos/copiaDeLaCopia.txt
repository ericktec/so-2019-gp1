#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char **argv){
    char *file1=argv[1];
    char *file2=argv[2];
    char *pwd = getcwd(NULL,0);
    char path1[strlen(file1)+strlen(pwd)+2];
    char path2[strlen(file2)+strlen(pwd)+2];
    sprintf(path1,"%s/%s",pwd,file1);
    sprintf(path2,"%s/%s",pwd,file2);
    printf("%s/%s\n",pwd,file1);
    printf("%s/%s\n",pwd,file2);
    int fd1=open(path1,O_RDONLY);
    int fd2=open(path2,O_WRONLY|O_CREAT,0666);
    char buffer[100];
    int n;
    while((n = read(fd1, buffer,100)) !=0 ){
        write(fd2, buffer, n);
    }
    close(fd1);
    close(fd2);

}