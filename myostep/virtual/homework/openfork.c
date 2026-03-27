#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
int main(int argc,char *argv[]){
    int fd = open("test.txt", O_RDONLY);
    if(fd < 0) {
        fprintf(stderr,"open failed\n");
        exit(1);
    }
    printf("opened fd = %d\n", fd);
    int rc = fork();
    if(rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if(rc == 0) {
        printf("child process: file = %d\n", fd);
    }
    else {
        printf("parent process: file = %d\n", fd);
    }
    if (close(fd) == -1) {
        perror("close failed");
        return 1;
    }
    return 0;
}