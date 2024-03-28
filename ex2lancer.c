#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char **argv) {
    if(argc > 1) {
        printf("Hello\n");
        if (fork()) {
            wait(NULL);
            printf("World!\n");
        } else {
            char **args;
            for(int i = 0; i < argc-1; i++)
                args[i] = argv[i+1];
            args[argc] = NULL;
            execvp(argv[1], args);
        }
    } else {
        printf("Veuillez indiquer la commande à exécuter.\n");
    }
}