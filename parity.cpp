#include <iostream>
#include <map>
#include <vector>
#include "bitwise_utils.h"
using namespace std;

template<class T>
int checkParity(T num) {
  int nbits = numbits(num);

  int parity = 0;
  T mask = 1;
  for(int i=0;i<nbits;++i) {
    if(mask & num)
      parity += 1;
    mask = mask << 1;
  }
  return parity%2;
}

template<class T>
int checkParity2(T num) {
  int parity = 0;
  while(num) {
    parity = parity ^ (num & 1);
    num = num >> 1;
  }
  return parity;
}

template<class T>
int checkParity3(T num) {
  int parity = 0;
  while(num) {
    parity ^= 1;
    num = num & (num-1);
  }
  return parity;
}

void makeParityTable(map<uint16_t,uint8_t> &table)
{
  for(int i=0;i<65536;++i) { // 65536 == 2^16
    table[(uint16_t)i] = (uint8_t)checkParity3(i);
  }
  
  // for(auto i=table.begin(); i != table.end(); ++i )
  //   cout << i->first << " " << ((int)i->second) << endl;
}

void checkBulkParity(vector<unsigned long long> &nums)
{
  map<uint16_t,uint8_t> table;
  makeParityTable(table);
  for(auto it = nums.begin(); it!=nums.end(); ++it) {
    const uint8_t *shortInts = reinterpret_cast<const uint8_t*>(&(*it));
    int parity = 0;
    for(int i=0;i<4;++i) {
      parity += table[shortInts[i]];
    }
    cout << *it << " " << parity << endl;
  }
}

int main()
{
  std::vector<unsigned long long> v;
  v.push_back(10);
  v.push_back(-1);
  v.push_back(-2);
  v.push_back(-3);
  v.push_back(-4);
  checkBulkParity(v);
  return 0;
}