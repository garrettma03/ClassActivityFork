#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int imageProcessing(){
    printf("doing processing for 5 seconds\n");
    sleep(5);
    return 0;
}

int main() {
    int doorOpen = 0;

    pid_t pid = fork(); // Create a new process (child)

    while(1){
        if (pid == 0) {
            //do image processing
            imageProcessing();
            break;
        } else {
            printf("parent PID %d, doing robot stuff\n", getpid());
            wait(NULL); //do child process
            printf("child dead, robot will shut down now\n");
            return 0;
        }
    }
    return 0;
}
