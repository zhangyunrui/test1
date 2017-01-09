#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define BUFSIZE 100
#define SIZE 100
char buf[BUFSIZE];
int bufp = 0;


int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

int getfloat(float *pn) {
    int c, sign;
    float power;

    while (isspace(c = getch()));
    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getch();
    for (*pn = 0.0; isdigit(c); c = getch())
        *pn = 10.0 * *pn + (c - '0');
    if (c == '.')
        c = getch();
    for (power = 1.0; isdigit(c); c = getch()) {
        *pn = 10.0 * *pn + (c - '0');
        power *= 10.0;
    }
    *pn *= sign / power;
    if (c != EOF)
        ungetch(c);
    return c;
}

int main() {
    int n, i;
    float array[SIZE];
    memset(array, 0, sizeof(array));
    memset(buf, 0, sizeof(buf));
    for (n = 0; n < SIZE && (i = getfloat(&array[n])) != EOF; n++) {
        if (isspace(i))
            printf("getint %.3f\n", array[n]);
        else if (i == '+' || i == '-')
            printf("getint %d\n", 0);
        else
            break;
    }
}