#include <stdio.h>
#include <math.h>
#include <float.h>
#define N_METHODS 3
#define MAX_LEN 256
void fn1(float, int*, int*, int*); 
void fn2(float, int*, int*, int*); 
void fn3(float, int*, int*, int*);
struct qq {
	char s[MAX_LEN];
	void (*fptr)(float, int*, int*, int*);
};
struct qq m[N_METHODS] = {{"Union с int и битовые операции", &fn1}, 
	{"Union со структурой с bit fields", &fn2}, 
	{"Взятие адреса и разыменование указателя, приведенного к другому типу и битовые операции", &fn3}};
void fn1(float a,  int* sign, int* mant, int* exp) {
	union {
		float x;
		int i;
	} un;
	un.x = a;
	*sign = (un.i >> 31) & 1;
	*exp = (un.i >> 23) & 255;
	*mant = un.i & ~(511 << 23);
}
void fn2(float a, int* sign, int* mant, int* exp) {
	union {
		float x;
		int ch;
		struct {
			unsigned int mant :23;
			unsigned int exp :8;
			unsigned int sign :1;
		} i;
	} un;
	un.x = a;
	*sign = un.i.sign;
	*exp = un.i.exp;
	*mant = un.i.mant;
}
void fn3(float a, int* sign, int* mant, int* exp) {
	float *flptr = &a;
	int *inptr = (int *) flptr;
	*sign = (*inptr >> 31) & 1;
	*exp = (*inptr >> 23) & 255;
	*mant = *inptr & ~(511 << 23);
}
void print_methods(struct qq m[]) {
	for (int i = 0; i < N_METHODS; i++) {
		printf("%d) %s\n", i + 1, m[i].s);
	}
}
void print_float(int sign, int mant, int exp) {
	if (sign == 1) {
		printf("(-1) * ");
	}
	printf("1.%d * ", mant);
	printf("2^(%d)\n", exp - 127);
}
int main(void) {
 	float a, b;
	int num = 0, sign, mant, exp;
	float maxFloat = 3.4E+38;
	float minFloat = 3.4E-38;
	print_methods(m);
	while (num < 1 || num > N_METHODS) {
		printf("Enter number of method (1 or 2 or 3): \n");
		scanf("%d", &num);
	};
	printf("Enter two float-numbers:\n");
	scanf("%f%f", &a, &b);
	m[num - 1].fptr(a / b, &sign, &mant, &exp);
	if (b == 0) {
		if (a > 0) {
			printf("+Inf\n");
		} 
		else if (a < 0) {
			printf("-Inf\n");
		}
		else {
			printf("Nan\n");
		}
	}
	else {
		print_float(sign, mant, exp);
	}
	return 0;
}
