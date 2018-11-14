#include "std_lib_facilities.h"
int main()
{
  int a=7,b=1;
/*The '^' is the operator for the xor operation which will make an and comparison on digits of 'a' and 'b' numbers (a=0111(2), b=0001(2); a^b --> 0 1 1 1 (2))
																																				  & & & &
																																				  0 0 0 1 (2)
																																				  v v v v
																																				  0 0 0 1 (2) = 1
*/
  a=a^b;
  b=a^b;
  a=a^b;

  cout << "a: " << a << ", b: " << b; 
}
