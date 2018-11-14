#include "std_lib_facilities.h"
int main()
{
  int a =1;
  int counter=0;
  cout <<"a: ";
  cin >> a;
  //Making a cycle that goes until the a is not 0
  while(a !=0)
  {
    //The bitshift operator shifts the digits of 'a' once to the left and the last digit will change to 0. The first digit will disappear, so once you use this, you will never be able to recover the original value. (11101 --> 11010)
    a<<=1;
    //Counter counts how many times will the cycle runs, by every time when a cycle run it will increase it's size by one. (counter++ == counter+=1 && counter +=1 == counter= counter+1)
    counter++;
  }
  cout<<counter;
}
