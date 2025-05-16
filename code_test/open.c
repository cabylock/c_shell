#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
char buffer[1024];
int fd;
fd = open("abc.txt",O_RDONLY);
ssize_t bytes;
    while ((bytes = read(fd, buffer, sizeof(buffer))) > 0) {
        write(1, buffer, bytes);  // 1 là stdout
    }



}

