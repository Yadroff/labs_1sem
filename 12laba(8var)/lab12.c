/* Лабораторная работа №12. Вариант 8
 * Перенести первый блок нулей из младших разрядов в середину десятичной записи числа
 * Студент группы 08-101 А.Ядров*/

#include <stdio.h>
#include <math.h>

int lenght(int a){
    int len = 0;
    while (a > 0){
        a /= 10;
        len ++;
    }
    return len;
}
int main() {
    int a;
    while (scanf("%d", &a) != EOF) {
        int c = 0, d = 0, b, cnt = 0, otr = 0;
        if (a < 0) {
            otr = 1;
            a *= -1;
        }
        b = a;
        int len = lenght(a);
        int mid = len / 2 + len % 2; //определение середины
        for (int i = 0; i < mid; i++) { //определение первого блока 0
            if (c) {
                if (b % 10 == 0) {
                    cnt++;
                } else {
                    break;
                }
            } else {
                if (b % 10 == 0) {
                    cnt++;
                    c = i; //индекс начало блока нулей
                }
            }
            b /= 10;
        }
        c += cnt - 1;
        for (int i = 0; i < mid; i++) { //удаление первого блока нулей
            if (a % 10 == 0 && i < c) { //пропуск первого блока нулей
                a /= 10;
                continue;
            }
            if (i < c) {
                d += (int) pow(10, i / 1.0) * (a % 10); //добавление цифры в число (если стоит до блока)
            } else {
                d += (int) pow(10, (i - cnt) / 1.0) * (a % 10); //добавление цифры в число (если стоит после блока)
            }
            a /= 10;
        }
        a *= (int) pow(10, lenght(d) / 1.0); //в a лежит левая половина числа, в d - правая часть без блока нулей
        mid = lenght(a)/2+lenght(a)%2;
        for (int i = 0; i < mid - 1; i++){
            d += (int) pow(10, i / 1.0) * (a%10);
            a /= 10;
        }
        a *= (int) pow(10, (double) lenght(d) + cnt);
        a += d;
        if (otr) {
            a *= -1;
        }
        printf("Результат: %d\n", a);
    }
    return 0;
}