#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    int doorOpen = 0;

    pid_t pid = fork(); // Create a new process (child)

    while(1){
        if (pid == 0) {
            //do weather stuff
            char *args[]={"./weather",NULL};
            execvp(args[0],args);
        } else {
            printf("weather plugin installed\n");
            wait(NULL); //do child process
            printf("weather stats printed, ending process\n");
            return 0;
        }
    }
    return 0;
}
