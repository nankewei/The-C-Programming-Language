#include <stdio.h>

void strcat(char *s, char *t);
int main()
{
    char A[100] = "abc";
    strcat(A, "c123def");
    printf("%s\n" ,A);
    return 0;
}
void strcat(char *s, char *t)
{
    while (*s)
        s++;
    while (*s++ = *t++)
        ;
}
