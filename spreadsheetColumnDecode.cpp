#include <iostream>
#include <exception>
#include <string>

using namespace std;

int ssDecodeColID(string colstr)
{
  int result = 0;
  for(size_t i=0; i<colstr.size(); ++i)
  {
    if(colstr[i] >= 'A' && colstr[i] <= 'Z')
      result = result*26 + colstr[i] - 'A' + 1;
    else
      throw exception();
  }
  return result;
}

string add1(string input)
{
  int ord = input.size()-1;
  while(1)
  {
    if(ord == -1)
    {
      input = "A" + input;
      break;
    }

    if(input[ord] != 'Z')
    {
      input[ord] += 1;
      break;
    }
    else
    {
      input[ord] = 'A';
      --ord;
    }
  }
  return input;
}   

void testDecoder()
{
  string col = "A";
  cout << "A:\t" << 1 << endl;
  for(int i=2;i<1000;++i)
  {
    col = add1(col);
    cout << col << ":\t" << i << endl;
    if(ssDecodeColID(col) != i)
    {
      cout << "Wrong output: " << col << endl;
      throw exception(); 
    }
  }
}

int main()
{
  testDecoder();
}