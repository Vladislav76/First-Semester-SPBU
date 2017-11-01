#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 256
#define MAX_SIZE 500
void InputStr(FILE *f, char **m, int *n) {
	int i = 0;
	while (!feof(f)) {
		m[i] = (char*) calloc(MAX_LEN, sizeof(char));
		if (fgets(m[i], MAX_LEN, f) != NULL) {
		}
		i++;
	}
	*n = i;
}
void SeekStr(char **m, int n) {
	for (int i = 0; i < n; i++) {
		int found = 0;
		for (int j = 0; j < n; j++) {
			if (i != j && !strcmp(m[i], m[j])) {
				found = 1;
				break;
			}
		}
		if (!found) {
			printf("%s", m[i]);
			break;
		}
	}
}
int main(void) {
	FILE *fptr;
	char name[] = "input.txt";
	if ((fptr = fopen(name, "r")) != NULL) {
		int n = 0;
		char** m = calloc(MAX_SIZE, sizeof(char**));
		InputStr(fptr, m, &n);
		SeekStr(m, n);
	}
	else {
		printf("Не удалось открыть файл!\n");
	}
	fclose(fptr);
	return 0;
}