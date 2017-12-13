#include <stdio.h>
int CountingDifference(int n) {
	int res = 0;
	int sum = (1 + n) * n / 2;
	for(int i = 1; i <= n; i++) {
		res += i * (sum - i);
	}
	return res;
}
int main(void) {
	int n = 100;
	printf("%d\n", CountingDifference(n));
	return 0;
}