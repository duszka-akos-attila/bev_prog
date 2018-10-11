#include "std_lib_facilities.h"
int main()
{
  int a=7,b=1;

  a=a+b;
  b=a-b;
  a=a-b;

  cout << "a: " << a << ", b: " << b; 
}
