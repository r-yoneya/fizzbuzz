#include <stdio.h>
#include <stdlib.h>

void fz(int n) { printf("fizz\n"); }
void bz(int n) { printf("buzz\n"); }
void fb(int n) { printf("fizzbuzz\n"); }
void _n(int n) { printf("%d\n", n); }

void (*funcs[3][5])(int n) = {
  { fb, fz, fz, fz, fz },
  { bz, _n, _n, _n, _n },
  { bz, _n, _n, _n, _n },
};

const int c = (sizeof funcs[0]) / (sizeof funcs[0][0]);
const int r = (sizeof funcs) / (sizeof funcs[0]);

void fizzbuzz(int n);

void nop(int n) {}
void (*prev[])(int) = { nop, fizzbuzz };

void fizzbuzz(int n) {
  prev[(n > 1) & 1](n - 1);
  funcs[n%r][n%c](n);
}

int main(int argc, char* argv[]) {
    fizzbuzz(atoi(argv[1]));
    return 0;
}
