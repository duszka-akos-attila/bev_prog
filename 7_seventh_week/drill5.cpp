#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int main(void)
{
	try
	{
		/*1.*/cout<<"1. Success!\n"; //Cout -> cout
		/*2.*/cout<<"2. Success!\n"; //Missing closing pair of ' " '
		/*3.*/cout<<"3. Success"<<"!\n"; //Missing starting pair of ' " '
		/*4.*/cout<<"4. Success!"<<'\n'; //Missing String delimiters
		/*5.*/int res=7; vector<int> v(10); v[5] = res; cout << "5. Success!\n"; //Wrong variable declaration string -> int
		/*6.*/vector<int> v2(10); v2[5] = 7; if (v2[5]!=7){} cout << "6. Success!\n"; //Wrong way to referring an element of the vector, and cout can not be in the scope of the if, because the condition is false
		/*7.*/if (true) cout << "7. Success!\n"; else cout << "Fail!\n"; //"cond" is not a condition
		/*8.*/bool c = true; if (c) cout << "8. Success!\n"; else cout << "Fail!\n"; //The boolean was initialized in the opposite way
		/*9.*/string s = "ape"; string c1 = "fool"; if (true) cout << "9. Success!\n"; //Wrong variable declaration and wrong way to compare strings and string does not have bool value
		/*10.*/string s1 = "ape"; if (s1!="fool") cout << "10. Success!\n"; //The original condition was false
		/*11.*/string s2 = "ape"; if (s2=="fool"){} cout << "11. Success!\n"; //The condition is false and missing stream flow operator pair ' < '
		/*12.*/string s3 = "ape"; if (s3!="fool") cout << "12. Success!\n"; //Wrong operator in if and missing stream flow operator pair ' < '
		/*13.*/vector<char> v3(5); for (int i=0; i<v3.size(); ++i){}  cout << "13. Success!\n";//In the 2. field of the for cycle the statement led to infinite cycle and cycles are not commands, so we don't need to close with ' ; ', and to avoid multiple cout can't be in cycle
		/*14.*/vector<char> v4(5); for (int i=0; i<=v.size(); ++i){} cout << "14. Success!\n"; //Cycles are not commands, so we don't need to close with ' ; ', and to avoid multiple cout can't be in cycle
		/*15.*/string s4 = "15. Success!\n"; for (int i=0; i<6; ++i){} cout << s4; //S is not a list, so we can't refer to the elements of it, and to avoid multiple cout can't be in cycle
		/*16.*/if (true) cout << "16. Success!\n"; else cout << "Fail!\n"; //If the condition in the if() is true the first command or every command in the first block under it will be executed
		/*17.*/int x = 2000; int c2 = x; if (c2==2000) cout << "17. Success!\n"; //Char can't get integer value
		/*18.*/string s5 = "18. Success!\n"; for (int i=0; i<10; ++i){} cout << s5; //The initialisation was string but the refer was string list, and to avoid multiple cout can't be in cycle
		/*19.*/vector<int> v5(5); for (int i=0; i<=v.size(); ++i){} cout << "19. Success!\n"; //We always have to give the type of the list elements, and cycles not commands, so ' ; ' can't be at the end, and to avoid multiple cout can't be in cycle
		/*20.*/int i=0; int j = 9; while (i<10) ++i; if (j<=i) cout << "20. Success!\n"; //The original code would be an infinite cycle and would never write out the Success!
		/*21.*/int x1 = 2; double d = 5/(x1-1); if (d==2*x1+1) cout << "21. Success!\n"; //This code has mathemaitcal errors like division by zero
		/*22.*/string s6 = "22. Success!\n"; for (int i=0; i<=14; ++i) cout << s6[i]; //We can't define what is building up a string
		/*23.*/int i1=2; int j1=0; while (j1<10){ ++j1; if (j1<i1) cout << "23. Success!\n";} //We have to declare at least the j variable and also have to refine the cycle and the variable values to make this work
		/*24.*/int x2 = 4; double d1 = 5/(x2-2); if (d1=2*x2-0.5) cout << "24. Success!\n"; //It does not have mistake if we want to check that the opreration executed successfully
		/*25.*/cout << "25. Success!\n"; //Because we want to write to the consonle we use cout not cin


	}
	catch (exception& e)
	{
		cerr << "error: " << e.what() << '\n';
		return 1;
	}
	catch (...)
	{
		cerr << "Oops: unknown exception!\n";
		return 2;
	}
}