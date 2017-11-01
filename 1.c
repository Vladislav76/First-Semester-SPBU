#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 256
void InputString (char m[]) {
    int i = 0;
    char c = getchar();
    while (c != '\0' && c != '\n') {
        m[i] = c;
        i++;
        c = getchar();
    }
    m[i] = '\0';
}
void ChangeString(char *m, char key) {
    int i = 0;
    int j = 0;
    int k = 0;
    while (m[i] != '\0') {
        if (m[i] != key) {
            m[j] = m[i];
            j++;
        }
        i++;
    }
    m[j] = '\0';
}
void PrintResult(char *m) {
    int i = 0;
    while (m[i] != '\0') {
        putchar(m[i]);
        i++;
    }
    printf("\n");
}
int main(void) {
    char m[MAX_LEN];
    char key;
    InputString(m);
    scanf("%c", &key);
    ChangeString(m, key);
    PrintResult(m);
    return 0;
}