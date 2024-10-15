#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork(); // Create a child process

    if (pid < 0) {
        // Fork failed
        perror("Fork failed");
        return 1;
    } else if (pid == 0) {
        // This is the child process
        printf("In child process\n");
        execlp("/bin/echo", "echo", "Hello, World!", NULL); // Replace child process with "echo" command
        // If exec fails, print error
        perror("exec failed");
    } else {
        // This is the parent process
        wait(NULL); // Wait for the child process to finish
        printf("Child process finished\n");
    }

    return 0;
}

