#include <stdio.h>
#include <string.h>
#define MAX_LEN 256
void SeekComments(FILE *f) {
	char tempArray[MAX_LEN];
	char c;
	while (!feof(f)) {
		if (fgets(tempArray, MAX_LEN, f) != NULL) {
			//printf("%s ", tempArray);
			int found = 0;
			int i = 1;
			int size = strlen(tempArray);
			while (i < size) {
				if (tempArray[i - 1] == '/' && tempArray[i] == '/') {
					found = 1;
					break;
				}
				i++;
			}
			//printf("%d ", found);
			if (found) {
				for (int j = i - 1; j < size - 1; j++) {
					printf("%c", tempArray[j]);
				}
				printf("\\n\n");
			}
		}
	}
}
int main(void) {
	FILE *fptr;
	char name[] = "input.txt";
	if ((fptr = fopen(name, "r")) != NULL) {
		SeekComments(fptr);
	}
	else {
		printf("Не удалось открыть файл!\n");
	}
	fclose(fptr);
	return 0;
}