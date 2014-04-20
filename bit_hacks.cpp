#include <iostream>
#include "bitwise_utils.h"
using namespace std;

// checks if 2 ints have opposite sign
// Sign is determined by MSB. If MSB is same, bits are exor-ed and 0 is set at MSB, which is negative number.
bool isOppositeSign(int x, int y) {
  return (x ^ y) < 0;
}

int abs(int x) {
  int mask = x >> (numbits(x)-1);   // mask is 0 if positive number, -1 otherwise
  return (x ^ mask) - mask;   // if mask is -1, this is equivalent to 2's complement
}

// Here, we are using y ^ x ^ y => x
// This will work only if false is 0 and true is 1
int max(int x, int y) {
  return y ^ ((x ^ y) & -(x > y));
}

int min(int x, int y) {
  return y ^ ((x ^ y) & -(x < y));
}

// check if number is a power of 2
// x & (x - 1) sets only the last set bit to 0.
bool checkPowerof2(int x) {
  return x && ((x & (x-1)) == 0);
}

int main()
{
  cout << isOppositeSign(10,-10) << endl;

}
