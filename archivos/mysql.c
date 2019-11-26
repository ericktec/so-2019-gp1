#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

typedef struct s{
    char firstName[20];
    char lastName[20];
    int studentId;
    char semester;
}Student;


int writeStudent(int argc, char **argv){
    char *fileName=argv[1];
    int fd2 = open(fileName,O_WRONLY|O_CREAT,0666);
    for(int i=0;i<10;i++){
        Student mystudent;
        mystudent.studentId=(i+1)*10;
        mystudent.semester=(i+1);
        sprintf(mystudent.firstName, "juanito_%d",i);
        sprintf(mystudent.lastName, "perez_%d",i);
        write(fd2, &mystudent, sizeof(mystudent));
    }
    close(fd2);
    return 0;
}


int readStudent(int argc, char **argv){
    char *fileName=argv[1];
    int fd2 = open(fileName,O_RDONLY);
    Student mystudent;
    while(read(fd2,&mystudent,sizeof(mystudent))){
        printf("%s %s :%d: %d \n", mystudent.firstName,mystudent.lastName,mystudent.studentId,mystudent.semester);
    }
    close(fd2);
    return 0;
}

int main(int argc, char **argv){
    char *fileName=argv[1];
    char*lastName=argv[2];
    char * newLastName=argv[3];
    int fd2 = open(fileName,O_RDONLY);
    int recordPos=-1;
    int i=-1;
    Student mystudent;
    while(read(fd2,&mystudent,sizeof(mystudent))){
        i++;
        if(!strcmp(mystudent.lastName,lastName)){
            recordPos=i;
            break;
        }
    }
    close(fd2);
    if(recordPos!=-1){
        printf("El record existe en la posicion %d\n",recordPos);
        char lastNameBuf[sizeof(mystudent.lastName)];
        strncpy(lastNameBuf, newLastName, sizeof(mystudent.lastName));
        fd2 = open(fileName,O_WRONLY);
        lseek(fd2, recordPos*sizeof(mystudent)+sizeof(mystudent.firstName), SEEK_SET);
        write(fd2, lastNameBuf, sizeof(mystudent.lastName));
        close(fd2);
    }else{
        printf("El record no existe\n");
    }
    return 0;
}

