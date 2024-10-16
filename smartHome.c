#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    int doorOpen = 0;

    pid_t pid = fork(); // Create a new process (child)

    if (pid == 0) {
        if (doorOpen == 1) {
            printf("child PID %d, DOOR OPEN\n", getpid());
            printf("closing door\n");
            doorOpen = 0; //close door
        } else {
            printf("child PID %d, door is already closed\n", getpid());
        }
    } else {
        printf("parent PID %d, opening door\n", getpid());
        doorOpen = 1; //open the door
        wait(NULL); //do child process
        printf("child dead, door is now closed\n");
    }
    return 0;
}
