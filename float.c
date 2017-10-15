#include <stdio.h>
#include <math.h>

void fn1(float, int*, int*, int*); 
void fn2(float, int*, int*, int*); 
void fn3(float, int*, int*, int*);

struct qq {
	char s[200];
	void (*fptr)(float, int*, int*, int*);
};
struct qq m[3] = {{"1", &fn1}, {"2", &fn2}, {"3", &fn3}};

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
	for (int i = 0; i < 3; i++) {
		printf("%d) %s\n", i + 1, m[i].s);
	}
}
void print_float(int sign, int mant, int exp) {
	sign = 1 + sign * (-2);
	int step = exp - 127;
	float f = 1 + (float) mant / pow(2, 23);
	float offs = 2;
	if (step < 0) {
		step = step * (-1);
		offs = 0.5;
	}
	for (int i = 0; i < step; i++) {
		f = f * offs;
	}
	printf("Result: %f\n", f);
}
int main(void) {
 	float a, b;
	int num, sign, mant, exp;
	print_methods(m);
	printf("Enter number of method (1 or 2 or 3): \n");
	scanf("%d", &num);
	printf("Enter two float-numbers:\n");
	scanf("%f%f", &a, &b);
	m[num - 1].fptr(a / b, &sign, &mant, &exp);
	print_float(sign, mant, exp);
	return 0;
}