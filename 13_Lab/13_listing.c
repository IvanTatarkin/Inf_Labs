#include <stdio.h>
#include <stddef.h>
#include <wctype.h>

int separator(char s) {
    char *m = " \t,\n";
    for (int i = 0; i < 4; i++) {
        if (s == m[i]) return 1;
    }
    return 0;
}

int main(void) {
    const unsigned int lu = 1;
    char *s = "aeiouy";
    unsigned int vowels = 0;

    for (int i = 0; i < 6; i++) {
        vowels = vowels | lu << (s[i] - 'a');
    }
    unsigned int word = 0;
 
    char chr;

    while ((chr = getchar()) != EOF) {
        if (separator(chr) && word) {
            vowels = vowels & word;
            word = 0;
        } else {
            word = word | (lu << (towlower(chr) - 'a'));
            int k = (towlower(chr) - 'a');
        }
    }
    if (word != 0){
        vowels = vowels & word;
    }
    if (vowels) {
        for (char i = 'a'; i <= 'z'; i++){
            if ((vowels & (lu << (towlower(i) - 'a'))) != 0){
                printf("%c\n", i);
            }
        }
    }                                                   
    else {
        printf("\nthere are no vowels included in all words");
    }

    return 0;
}
