#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv) {
    printf("Hello\n");
    execlp("ps", "ps", "-l", NULL);
    printf("World!\n");
}