#include <stdio.h>
void endian() {
    union {
        int i;
        char c[sizeof(int)];
    } un;
    un.i = 1;
    if (un.c[0] != 0)
        printf("little-endian\n");
    else printf("big-endian\n");
}
int main() {
    endian();
    return 0;
}