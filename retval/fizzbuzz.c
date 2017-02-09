#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    for (int i = 1; i <= atoi(argv[argc-1]); i++)
        printf(&"%d\n\0\n"[
                printf("%s", i%3 ? "" : "fizz")
                |
                printf("%s", i%5 ? "" : "buzz")
                ], i);
    return 0;
}
