#include <stdio.h>
#include <limits.h>

int main() {
    printf("Size of Char %d\n", CHAR_BIT);
    printf("Size of Char Min %d\n", CHAR_MIN);
    printf("Size of Char Max %d\n", CHAR_MAX);
    printf("Size of int Min %d\n", INT_MIN);
    printf("Size of int Max %d\n", INT_MAX);
    printf("Size of long Min %ld\n", LONG_MIN);
    printf("Size of long Max %ld\n", LONG_MAX);
    printf("Size of short Min %d\n", SHRT_MIN);
    printf("Size of short Max %d\n", SHRT_MAX);
    printf("Size of unsignd char %u\n", UCHAR_MAX);
    printf("Size of unsignd long %lu\n", ULONG_MAX);
    printf("Size of unsignd int %u\n", UINT_MAX);
    printf("Size of unsignd short %u \n", USHRT_MAX);

    char i;

    for (i = 0; i > i++;);
    printf("Size of int Min %d\n", i);
    for (i = 0; i < i--;);
    printf("Size of int Max %d\n", i);
    return 0;
}