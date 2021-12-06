#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, char* argv[]) {
	if (argc != 3) {
		printf ("You must specify file path");
		exit(1);
	}

	int fd1 = open(argv[1], O_RDONLY);
	if (fd1 == -1) {
		perror("open");
		exit(1);
	}

	int fd2 = open(argv[2], O_WRONLY | O_CREAT);
	if (fd2 == -1) {
		perror("open");
		exit(1);
	}

	int n_chars;
	char buf[4000];
	while((n_chars = read(fd1,buf,sizeof(buf)))>0) {
		if(write(fd2,buf,n_chars)!=n_chars){
		perror("write");
		exit(1);
		}
	}

	if (close(fd1) == -1) {
		perror("close");
		exit(1);
	}
	if (close(fd2) == -1) {
		perror("close");
		exit(1);
	}
								
	return 0;
}

