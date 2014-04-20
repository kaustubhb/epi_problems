#include <iostream>
#include <vector>
using namespace std;

void printPowerSet(vector<int> &setOrig, size_t i, vector<int> toPrint) {
  if(i == setOrig.size()) {
    cout << "{ ";
    for(auto it=toPrint.begin(); it!=toPrint.end(); ++it) {
      cout << *it << " ";
    }
    cout << '}' << endl;
    return;
  }
  printPowerSet(setOrig, i+1, toPrint);
  toPrint.push_back(setOrig[i]);
  printPowerSet(setOrig, i+1, toPrint);
} 

int main() {
  vector<int> v = {1,2,3};
  vector<int> toPrint;
  printPowerSet(v, 0, toPrint);
}