#include <stdio.h>


void swap(int *pa, int *pb) {
    int temp;

    temp = *pa;
    *pa = *pb;
    *pb = temp;
}

int main() {
    int a, b;
    a = 1;
    b = 2;
    swap(&a, &b);
    printf("%d %d\n", a, b);
    return 0;
}