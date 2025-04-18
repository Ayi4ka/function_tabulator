#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <string.h>

int main() {
    float* x;
    float* p;
    float* a;
    float* b;
    float* c;
    float x1, xn, Hx, p1, pn, Hp, max;
    int n, m,o1, o2; // n - кол-во строк m - кол-во столбцов 
    float pi = 3.14159265358979323846;

    printf("Hi! This program helps you do some counting \n please write the first value x"); //Ввод значений 
    scanf("%f", &x1);
    printf("Ok, now please write the last value x \n");
    scanf("%f", &xn);
    printf("Ok, now please write change step for x \n");
    scanf("%f", &Hx);
    printf("Ok, now please write the first value p \n");
    scanf("%f", &p1);
    printf("Ok, now please write the last value p \n");
    scanf("%f", &pn);
    printf("Excellent, now please write change step for p \n");
    scanf("%f", &Hp);
    printf("You are cool guy. Thanks! \n");
    if ((Hx == 0) && (Hp == 0)) {
        printf("You have mistake in step!");
        return 0;
    }
    n = ((xn-x1)/Hx)+1;
    m = ((pn-p1)/Hp)+1;

    printf("%i %i\n", n, m);
    a = (float*)malloc(n * m * sizeof(float*)); 
    b = (float*)malloc(n * m * sizeof(float*));
    c = (float*)malloc(n * m * sizeof(float*));
    x = (float*)malloc(n * sizeof(float*));
    p = (float*)malloc(m * sizeof(float*));

    for (int i = 0; i < n; i++) {
        x[i] = x1;
        x1 = x1+ Hx;
    }
    for (int j = 0; j < m; j++) {
        
        p[j] = p1;
        p1 = p1 + Hp;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            //Проверка соблюдений условий 
            if ((x[i]) == 0) {
                *(c + i * m + j) = 0.0001;
            }
            else
                if ((x[i] + 3) < 0) {
                    *(c + i * m + j) = 0.0002;
                }
                else
                    if ((x[i] + pi) <= 0) {
                        *(c + i * m + j) = 0.0003;
                    }
                    else
                        if ((fabsf(log(x[i] + pi) + p[j]) - (sqrt(x[i] + 3))) == 0) {
                            *(c + i * m + j) = 0.0004;
                        }
                        else
                            if (((fabsf(log(x[i] + pi) + p[j]) - (sqrt(x[i] + 3))) != 0) && ((x[i] + 3) >= 0) && ((x[i] + pi) > 0)) {
                                *(a + i * m + j) = fabsf(sin((p[j] / 2) - x[i] + 3)) + 2 * p[j] * pow(x[i], -2);
                                *(b + i * m + j) = fabsf(log(x[i] + pi) + p[j]) - (sqrt(x[i] + 3));
                                *(c + i * m + j) = *(a + i * m + j) / *(b + i * m + j);
                            }
        }
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        if (i == 0) {
            printf("  x p   | % 8.3f", p[i]);
        }
        else {
            printf(" | % 4.3f", p[i]);
        }

    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%8.3f|", x[j]);
            for (int a = 0; a < m; a++)
            {
                if (*(c + j * m + a) == (float)0.0001) {
                    printf("    a    ");
                }
                else if (*(c + j * m + a) == (float)0.0002) {
                    printf("    b    ");
                }
                else if (*(c + j * m + a) == (float)0.0003) {
                    printf("    c    ");
                }
                else if (*(c + j * m + a) == (float)0.0004) {
                    printf("    d    ");
                }
                else printf("% 9.3f", *(c + j * m + a));
            }
            printf("\n");
        }
        break;
    }
    printf("\n");
    printf("  ERROR LIST:\n a - sub-power value 0\n b - value under root 0\n c - wrong value under log\n d - the denomination is 0\n");
    printf(" 3 - digit precision \n");
    max = 0;
    o1 = 0;
    o2 = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ((max) > (*(c + i * m + j))) {
                max = *(c + i * m + j);
                o1 = i;
                o2 = j;
            }
           
        }
    }
    if (max == 0) {
        printf(" There is no largest negative element in absolute module");
    } else 
        printf(" Largest negative element in absolute module is %.3f\n Row and column numbers: %i %i\n", max, o1, o2);
    free(a);
    free(b);
    free(c);
    free(p);
    free(x);
}
