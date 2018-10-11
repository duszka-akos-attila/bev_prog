#include "std_lib_facilities.h"

int main()
{
  string firstName, friendName;
  char friendSex;
  int friendAge=0;

  cout << "Please enter your first name: ";
  cin >> firstName;
  cout << "Please enter your friend's name: ";
  cin >> friendName;

  cout << "Please enter your friend's age: ";
  cin >> friendAge;
  if(friendAge<=0 || friendAge>=110)
  {
  	simple_error("You're kidding! It's not a real age. Please write real age (1-109)!");
  }

  cout << "And now please enter your friend's sex! If male write 'm',otherwise 'f' : ";
  cin >> friendSex;

  system("clear");

  cout << "Dear " << firstName << ","<< "\n"<<"How are you? I am fine. I miss you. \n";
  cout << "Have you seen " << friendName << " lately? ";

  if(friendSex=='m')
  {
  	cout << "If you see " << friendName << " please ask him to call me.";
  }
  else if(friendSex=='f')
  {
  	cout << "If you see " << friendName << " please ask her to call me.";
  }

  cout << "\n";
  cout << "I hear you just had a birthday and you are " << friendAge << " years old. ";

  if(friendAge<=12)
  {
  	cout << "Next year you will be " << friendAge+1 <<".";
  }
  else if(friendAge==17)
  {
  	cout << "Next year you will be able to vote.";
  }
  else if(friendAge==70)
  {
  	cout << "I hope you are enjoying retirement.";
  }

  cout << "\nYours sincerely, \n \n" << firstName <<"\n";
  return 0;
}
