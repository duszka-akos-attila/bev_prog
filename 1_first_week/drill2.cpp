//Calling the std_lib_facilities header which is contains hundreds of lines that are making our learning easier
#include "std_lib_facilities.h"
//Declare and initialise main function, which is the core of all programs
int main()
{
//Writing out Hello World! to standard output(to terminal)
  cout << "Hello World!\n";
//In Windows this function prevent command prompt to exit after it has been successfully terminated
  keep_window_open();
//Most of the functions has a return value, which is also stop the main function
  return 0;
}
