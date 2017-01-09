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

int getint(int *pn) {
    int c, sign;

    while (isspace(c = getch()));
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getch();
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}

int main() {
    int n, array[SIZE], i;
    memset(array, 0, sizeof(array));
    memset(buf, 0, sizeof(buf));
    for (n = 0; n < SIZE && (i = getint(&array[n])) != EOF; n++){
        if (isspace(i))
            printf("getint %d\n", array[n]);
        else
            break;
    }
}