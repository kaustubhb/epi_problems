#include <iostream>
#include "bitwise_utils.h"
using namespace std;

template<class T>
T bitswap(T num, int i, int j)
{
  if(((num >> i)&1) != ((num >> j)&1)) {    // swap only if bits are not same
    num = num ^ (1 << i | 1 << j);   // exoring with 1 toggles the bit
  }
  return num;
}

int main()
{
  unsigned short n;
  int i,j;
  cin >> n >> i >> j;
  cout << "Before swap:\t";
  printBits(n);
  cout << endl;

  n = bitswap(n, i, j);
  cout << "After swap:\t";
  printBits(n);
  cout << endl;
}