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
    int offset = (32 + num);
    int mask = ~0 << (offset + (~1 + 1));
    mask = mask << 1;
    mask = ~mask;
    x = x >> n;
    x = x & mask;
    return x;
}
int addOK(int x, int y) {
    int sign = ((x | y) >> 31) & 1;
    int mask = ~(255 << 24);
    int s = ((x & mask) + (y & mask)) >> 24;
    int x1 = (x >> 24) & 255;
    int y1 = (y >> 24) & 255;
    s = (s + x1 + y1);
    int sign2 = s & 128;
    s = s >> 8;
    return !(s || (sign2 ^ sign));
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
   
    return 0;
}