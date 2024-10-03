#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

//implementation of vfork() system call
//create child process using parent block (child and parent run in same memory)
//but fork() system call 
//The child process and the parent process run in separate memory




int main() {
    int fd = open("add.c", O_RDONLY); // Open terminal device as stdin
    if (fd < 0) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    printf("Parent: stdin fd = %d\n", fd);

    pid_t pid = vfork();  // Create child process using vfork
    if (pid < 0) {
        perror("vfork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) { // Child process
          printf("Child Process created using vfork() System Call \n");
	  printf("Child: closing stdin (fd 0)\n");
          close(0); // Close file descriptor 0 (stdin)

          printf("Child: stdin is closed\n");
          _exit(0); // Exit child process to avoid affecting parent
    } else {
        // Parent process continues here after child exits
        printf("Parent: stdin fd after vfork = %d\n", fd);

        // Check if stdin (fd 0) is still open
        char buffer[10];
        int result = read(0, buffer, sizeof(buffer)); // Reading from stdin
        if (result < 0) {
            perror("Parent: read from stdin");
        } else {
            printf("Parent: stdin is still open\n");
        }

        close(fd); // Close the file descriptor
    }

    return 0;
}

