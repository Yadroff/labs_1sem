/* Лабораторная работа №9. Вариант 29.
 * Студент группы 08-101 А.Ядров*/

#include <stdio.h>
#include <stdlib.h>
#define i0 -7
#define j0 3
#define l0 9

int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int sign(int a) {
    if (a < 0) {
        return -1;
    }
    if (a == 0) {
        return 0;
    } else {
        return 1;
    }
}

int min(int a, int b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

int main() {
    int i = i0, j = j0, l = l0, ilast = i, jlast = j, llast = l;
    for (int k = 0; k < 50; k++) {
        ilast = i;
        jlast = j;
        llast = l;
        i = (30 + max(max(ilast * jlast, ilast * llast), jlast * llast) % 30) % 30 + k;
        j = abs(jlast - llast) * sign(ilast) - abs(ilast - llast) * sign(jlast);
        l = min(ilast, max(jlast, min(llast, max(ilast, jlast))));
        if ((i-20) * (i-20) + 4 * j * j <= 100) {
            printf("Попал на шаге %d i=%d, j=%d, l=%d\n", k, i, j,l);
            return 0;
        }
    }

    printf("Не попал, i=%d, j=%d, l=%d",i,j,l);
    return 0;
}
