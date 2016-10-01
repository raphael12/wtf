#include <stdio.h>

int main () {
    int chr, str, word;
    str = 0;
    word = 0;
    while ((chr = getchar()) != EOF) {
        if (chr == '\n' ) {
            ++str;
        }
        if ((chr == ' ') || (chr == '\n'))
            ++word;
    }
    printf("%d\n%d\n", str, word);
    return 0;
}
