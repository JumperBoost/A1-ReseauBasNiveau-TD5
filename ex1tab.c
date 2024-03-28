#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char **argv) {
    int i, j, s, tabpid[3];
    printf("[avant fork] PID: %d\n", getpid());
    for(j = 0; j < 3; j++) {
        tabpid[j] = fork();
        if (tabpid[j] != 0 ) {
            printf("PID: %d, retour fork: %d \n",getpid(),tabpid[j]);
            for(int k = 0; k < 3; k++)
                printf("parent-tabpid[%i]: %i\n", k, tabpid[k]);
        } else {
            printf("PID: %d \n",getpid());
            for(int k = 0; k < 3; k++)
                printf("fils-tabpid[%i]: %i\n", k, tabpid[k]);
            exit(j);
        }
    }
    for(j = 0; j < 3; j++) {
        i= waitpid(tabpid[j], &s, 0);
        if (i > 0) {
            printf("terminé PID: %d, Code: %d\n", i, WEXITSTATUS(s));
        }
        sleep(1);
    }
}