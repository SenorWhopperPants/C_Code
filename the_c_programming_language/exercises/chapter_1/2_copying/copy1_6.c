#include <stdio.h>

/* copy input to output */
int main()
{
    int c;
    int check;

    while (check = ((c = getchar()) != EOF)) {
        putchar(c);
        printf("%d\n", check);
    }
}
