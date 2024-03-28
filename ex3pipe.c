#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main (int argc, char const **argv) {
    pid_t pid;
    int fd[2], nbread;
    char buffer[4096];
    char *args[4096];

    if(argc < 4) {
        write(2, "Vous n'avez pas assez de paramètre pour exécuter le programme.\n", 65);
        return 1;
    }

    int not_pipe_param = 0;
    for(int i = 1; i < argc; i++) {
        if(strcmp(argv[i], "--pipe") == 0)
            not_pipe_param = i - 1;
        args[i-1] = argv[i];
    }
    if(not_pipe_param == 0) {
        write(2, "Vous n'avez pas préciser de pipe en paramètre pour exécuter le programme.\n", 77);
        return 1;
    }

    pipe(fd);   // création du tube
    pid = fork();
    if (pid) {
        // Execution du processus parent
        wait(NULL);
        close(fd[1]);
        dup2(fd[0], 0);
        args[argc] = NULL;
        execvp(args[not_pipe_param+1], args+not_pipe_param+1);
        close(fd[0]);
    } else {
        // Exécution du processus fils
        close(fd[0]);
        dup2(fd[1], 1);
        close(fd[1]);
        args[not_pipe_param] = NULL;
        execvp(args[0], args);
    }
}
