#include <stdio.h>
int CountingDifference(int n) {
	int Res = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j) {
				Res += i * j;
			}
		}
	}
	return Res;
}
int main(void) {
	int n = 100;
	printf("%d\n", CountingDifference(n));
	return 0;
}