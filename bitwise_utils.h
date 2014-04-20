#ifndef __bitwise_utils__
#define __bitwise_utils__

#include <iostream>

template<class T>
inline int numbits(T num)
{
  return sizeof(num)*8;
}

template<class T>
inline void printBits(T num) {
  int nbits = numbits(num);
  unsigned long long mask = 1;
  mask = mask << (nbits-1);
  for(int i=0;i<nbits;++i) {
    if(i%4==0)
      std::cout << " ";
    std::cout << (num & mask ? 1 : 0);
    mask = mask >> 1;
  }
  std::cout << std::endl;
}

#endif