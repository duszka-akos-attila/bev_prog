#include "std_lib_facilities.h"
int main()
{
  int a =1;
  int counter=0;
  cout <<"a: ";
  cin >> a;
  while(a !=0)
  {
    a<<=1;
    counter++;
  }
  cout<<counter;
}
