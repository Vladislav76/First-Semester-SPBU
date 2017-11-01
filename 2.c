#include <stdio.h>
#define MAX_SIZE 1000
void Input(int *m1, int *m2, int *n, int *m) {
	int i = 0;
	int c;
	while ((c = getchar()) != '\n') {
		m1[i] = c - '0';
		i++;
	}
	*n = i;
	i = 0;
	while ((c = getchar()) != '\n') {
		m2[i] = c - '0';
		i++;
	}
	*m = i;
}
int Compare(int *m1, int *m2, int n, int m) {
	if (n > m) {
		return 1;
	}
	else if (m > n) {
		return 2;
	}
	else {
		int i = 0;
		while (m1[i] == m2[i] && i < n) {
			i++;
		}
		if (i == n) {
			return 0;
		} 
		else if (m1[i] > m2[i]) {
			return 1;
		}
		else {
			return 2;
		}
	}
}
void PrintResult(int *m1, int *m2, int n, int m, int Res) {
	/*for (int i = 0; i < n; i++) {
		printf("%d", m1[i]);
	}
	printf("\n");
	for (int i = 0; i < m; i++) {
		printf("%d", m2[i]);
	}*/
	switch (Res) {
		case 0:
			printf("Числа равны\n");
			break;
		case 1:
			printf("Первое число больше второго\n");
			break;
		case 2:
			printf("Второе число больше первого\n");
			break;
	}
}
int main(void) {
	int m1[MAX_SIZE];
	int m2[MAX_SIZE];
	int size1 = 0, size2 = 0;
	Input(m1, m2, &size1, &size2);
	int Res = Compare(m1, m2, size1, size2);
	PrintResult(m1, m2, size1, size2, Res);
	return 0;
}