#include <iostream>
#include <string>
#include <exception>
#include <cmath>
using namespace std;

// handle decimal, octal and hexadecimal positive and negative strings
int stringToInt(string str) {
  int result = 0;
  int sign = 1;
  size_t i = 0;     // for looping through the string
  int base = 10;

  if(str[i] == '-') { // check for sign
    sign = -1;
    ++i;
  }

  if(str.substr(i).size() >= 2 && str[i] == '0' && 
          (str[i+1] == 'x' || str[i+1] == 'X')) 
  {
    cout << str.substr(i) <<endl;
    base = 16;
    i += 2;
  }

  else if(str.substr(i).size() >= 1 && str[i] == '0') { // check for octal
    base = 8;
    ++i;
  }

  for(;i<str.length();++i) {
    char c = str[i];
    if((base == 8 && c >= '0' && c <= '7') ||
        (base == 10 && c >= '0' && c <= '9') ||
        (base == 16 && (c >= '0' && c <= '9')))
    {
      result = result * base + c - '0';
    }
    else if(base == 16)
    {
      if(c >= 'a' && c <= 'f')
        result = result*base + 10 + c-'a';
      else if (c >= 'A' && c <= 'F')
        result = result*base + 10 + c-'A';
    }
    else {
      throw exception();
    }
  }
  return result*sign;;
}

template<class T>
void swap(T *a, T *b) {
  T temp = *a;
  *a = *b;
  *b = temp; 
}

string intToString(int num) {
  string result = "";
  bool negative = num < 0;
  num = abs(num);
  while(num > 0) {
    result += (char)(num%10 + '0');
    num = num/10;
  }

  for(size_t i=0;i<result.length()/2;++i) {
    swap(&result[i], &result[result.length()-1-i]);
  }

  return negative ? ("-" + result) : result;
}

void testStringToInt() {
  string str;
  cin >> str;
  try {
    cout << stringToInt(str) << endl;
  }
  catch(exception &ex) {
    cout << "Exception occurred: " << ex.what() << endl;
  }
}

void testIntToString() {
  int num;
  cin >> num;
  try {
    cout << intToString(num) << endl;
  }
  catch(exception &ex) {
    cout << "Exception occurred: " << ex.what() << endl;
  }

}

int main() {
  //testStringToInt();
  testIntToString();
}