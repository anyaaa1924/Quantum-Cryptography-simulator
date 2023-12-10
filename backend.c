#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Content-type: text/html\n\n");
    printf("<html><head><title>Quantum Cryptography Game</title></head><body>\n");

    char *userChoice = getenv("QUERY_STRING");

    if (userChoice == NULL) {
        printf("<p>No data submitted.</p>\n");
    } else {
        printf("<p>You chose: %s</p>\n", userChoice);
    }

    printf("</body></html>\n");

    return 0;
}
