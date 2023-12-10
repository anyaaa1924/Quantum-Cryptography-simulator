#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b;
    char userChoice;
    printf("Content-type: text/html\n\n");
    printf("<html><head><title>Quantum Cryptography Game</title></head><body>\n");

    char *userChoice = getenv("QUERY_STRING");

    if (userChoice == NULL)
    {
        printf("<p>No data submitted.</p>\n");
    }
    else if (userChoice == a)
    {
        printf("<p>You chose: a %s</p>\n", userChoice);
    }
    else
    {
        printf("<p>You chose: b %s</p>\n", userChoice);
    }

    printf("</body></html>\n");

    return 0;
}
