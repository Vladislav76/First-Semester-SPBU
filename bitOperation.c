#include <stdio.h>
int bitAnd(int x, int y) {
	return ~(~x | ~y);
}
int bitXor(int x, int y) {
	return ~(x & y) & ~(~x & ~y);	
}
int thirdBits(void) {
	int i = 73;
	i = i << 9 | 73;
	i = i << 9 | 73;
	i = i << 5 | 4;
	return i;
}
int fitsBits(int x, int n) {
	int offs = 32 + (~n + 1);
	int y = x << offs;
	y = y >> offs;
	return !(x + ~y + 1);
}
int sign(int x) {
	int lastNum = !!x;
	int res = x >> 31;
	res = res << 1 | lastNum;
	return res;
}
int getByte(int x, int n) {
	n = n << 3;
	x = (x >> n) & 255;
	return x;
}
int logicalShift(int x, int n) {
	int num = ~n + 1;
	int offset = (32 + num) & 31;
	int mask = ~0 << offset;
	mask = ~mask;
	x = x >> n;
	x = x & mask;
	return x;
}
int addOK(int x, int y) {
	int mask = ~(1 << 31);
	int x1 = (x >> 1) & mask;
	int y1 = (y >> 1) & mask; 
	int res = ((x1 + y1) >> 31) & 1;
	return !res;
}
int bang(int x) {
	int i = (x >> 31 | (~x + 1) >> 31) & 1;
	return i ^ 1;
}
int conditional(int x, int y, int z) {
	int mask = ~!!x + 1;
	return y & mask | z & ~mask;
}
int isPower2(int x) {
	int y = ~x + 1;
	return !!x & !((x >> 31) & 1) & !(x & y + y) ;
}
int main() {
	printf("%d\n", logicalShift(-2147483648, 0));
	printf("ch = %x\n", d);
	return 0;
}