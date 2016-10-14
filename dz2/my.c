#include <stdio.h>

int main () {
    int cha, str = 0, word = 0;
    while ((cha = getchar()) != EOF) {
        if (cha == '\n' ) {
            ++str;
        }
        if ((cha == ' ') || (cha == '\n'))
            ++word;
    }
    printf("%d\n%d\n", str, word);
    return 0;
}
