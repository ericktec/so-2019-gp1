#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

void comparar(char* word, char*sustituir, char*newWord,int fd2){
    if(!strcmp(word,sustituir)){
                write(fd2,newWord,strlen(newWord));
                write(fd2," ",1);
                printf("la palabra nueva es %s \n", newWord);
            }else{
                write(fd2,word,strlen(word));
                write(fd2," ",1);
                printf("la palabra es %s \n", word);
            }
}

int main(int argc, char **argv){
    char *file1=argv[1];
    char *sustituir=argv[2];
    char *newWord=argv[3];
    char *file2="temporal.txt";
    char *pwd = getcwd(NULL,0);
    char path1[strlen(file1)+strlen(pwd)+2];
    char path2[strlen(file2)+strlen(pwd)+2];
    sprintf(path1,"%s/%s",pwd,file1);
    sprintf(path2,"%s/%s",pwd,file2);
    printf("%s/%s\n",pwd,file1);
    printf("%s/%s\n",pwd,file2);
    int fd1=open(path1,O_RDONLY);
    int fd2=open(path2,O_WRONLY|O_CREAT,0666);
    char word[100];
    char c;
    printf("Esto es sustituir %s por %s \n",sustituir, newWord);
    int index=0;
    while((read(fd1, &c,1)) ){
        if(c!=' '){
            word[index++]=c;
        }else{
            word[index]='\0';
            index=0;
            comparar(word, sustituir, newWord,fd2);
            
            
            
        }
        
    }
    word[index]='\0';
    comparar(word, sustituir, newWord,fd2);
    close(fd1);
    close(fd2);
    unlink(path1);
    link(path2,path1);
    unlink(path2);
}