#include <iostream>
#include <exception>
#include <algorithm>
using namespace std;

int charToInt(char c)
{
  if(c >= '0' && c <= '9')
    return c - '0';
  if(c >= 'a' && c <= 'f')
    return c - 'a';
  if(c >= 'A' && c <= 'F')
    return c - 'A';
  throw exception();
}

char intToChar(int i)
{
  if(i >= 0 && i <= 9)
    return (char)(i + '0');
  if(i >= 10 && i <= 15)
    return (char)(i - 10 + 'a');
  throw exception();
}

int toBase10(string numstr, int inbase)
{
  int result = 0;
  for(size_t i=0;i<numstr.size();++i)
  {
    result = result*inbase + charToInt(numstr[i]);
  }
  cout << result << endl;
  return result;
}

string convertToBase(int innum, int tobase)
{
  string result = "";
  while(innum > 0)
  {
    result = result + intToChar(innum%tobase);
    innum = innum/tobase;
  }
  std::reverse(result.begin(), result.end());
  return result;
}

string convertBases(int inbase, string inNum, int outbase)
{
  return convertToBase(toBase10(inNum, inbase), outbase);
}

int main()
{
  string inNum;
  int inbase, outbase;
  cin >> inbase >> inNum >> outbase;
  cout << convertBases(inbase, inNum, outbase) << endl;

}