/* Лабораторная работа №11. Вариант 20.
 * Перевести все мерные расстояния из миль (mi) в километры (km).
 * Студент группы 08-101 А.Ядров*/
#include <stdio.h>

#define CONTINUE 2
#define IN_DIGIT 1
#define OUT 0
#define MAX_INT 2147483647

int to_km(int mi) {
    return (int) (mi * 1.609);
}

int is_digit(int c) {
    if (c >= '0' && c <= '9') {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int c, n = 0;
    int state = OUT;
    while ((c = getchar()) != EOF) {
        if (state == OUT) {
            if (is_digit(c)) {
                state = IN_DIGIT;
            } else {
                if (c != ' ' && c != '\t' && c != '\n') {
                    state = CONTINUE;
                }
            }
        }
        if (state == IN_DIGIT) {
            if (is_digit(c)) {
                if (n < MAX_INT / 10 - (c - '0')) {
                    n = n * 10 + (c - '0');
                } else {
                    state = CONTINUE;
                    printf("%d", n);
                    n = 0;
                    continue;
                }
                if (n > (int) MAX_INT / 1.609) {
                    state = CONTINUE;
                    printf("%d", n);
                    n = 0;
                    continue;
                }
            } else if (c != 'm') {
                state = CONTINUE;
                printf("%d", n);
                n = 0;
            } else {
                if ((c = getchar()) != 'i') {
                    state = CONTINUE;
                    if (c == '\n' || c == '\t' || c == ' ') {
                        state = OUT;
                        printf("%d%c ", n, 'm');
                        if (c == '\n') {
                            printf("%c", '\n');
                        }
                    } else {
                        printf("%d%c%c", n, 'm', c);
                    }
                    n = 0;
                } else {
                    c = getchar();
                    if (c == '\n' || c == ' ' || c == '\t') {
                        state = OUT;
                        printf("%dkm ", to_km(n));
                        n = 0;
                        if (c == '\n') {
                            printf("%c", '\n');
                        }
                    } else {
                        state = CONTINUE;
                        printf("%d%s%c", n, "mi", c);
                    }
                }
            }
        }
        if (state == CONTINUE) {
            if (c == '\n' || c == ' ' || c == '\t') {
                state = OUT;
                printf("%c", ' ');
                if (c == '\n') {
                    printf("%c", '\n');
                }
                continue;
            }
            printf("%c", c);
        }
    }
    return 0;
}