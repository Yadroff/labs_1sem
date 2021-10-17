#include <string.h>    // Lab 13
#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>

#define VOWELS (1u << ('a'- 'a') | 1u << ('e' - 'a') | 1u << ('i' - 'a') | 1u << ('o' - 'a') | 1u << ('u' - 'a'))
#define OUT 0
#define IN_WORD 1

unsigned int char_to_set(char c) {
    c = tolower(c);
    if (c < 'a' || c > 'z') {
        return 0;
    }
    return 1u << (c - 'a');
}

unsigned int negation(unsigned int set) {
    return ~set;
}

unsigned int difference(unsigned int set1, unsigned int set2) {
    return set1 & negation(set2);
}

unsigned int subset(unsigned int set1, unsigned int set2) {
    return ~difference(set1, set2);
}

int main() {
    bool c1 = true, c2 = false;
    int c, state = OUT;
    unsigned int set = 0;
    while ((c = getchar()) != EOF) {
        switch (state) {
            case OUT: {
                if (c == '\n' || c == '\t' || c == ' ') {
                    continue;
                }
                state = IN_WORD;
            }
            case IN_WORD: {
                if (c == '\n' || c == '\t' || c == ' ') {
                    if (c1 && subset(set, VOWELS)) {
                        c2 = true;
                    }
                    c1 = true;
                    set = 0;
                }
                if (char_to_set(c) == 0) {
                    c1 = false;
                } else if (c1){
                    set = set | char_to_set(c);
                }
            }
        }
    }
    if (c2){
        printf("В тексте есть слово, состоящее из гласных латинских букв\n");
    }
    else{
        printf("В тексте нет слов, состоящих из гласных латинских букв\n");
    }
}