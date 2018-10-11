//INDEV!

#include "std_lib_facilities.h"

class length
{

	private:

		double leng;
		string unit;

	public:

		bool operator < (const length& str) const
    	{
        	return (leng < str.leng);
   	 	}

		length(double lg, string un)
		{
			leng=lg;
			unit=un;
		}

		static length unitChangeToM(length lg)
		{
			if(lg.unit=="cm")
			{
				lg.leng/=100;
				lg.unit="m";
			}
			else if(lg.unit=="in")
			{
				lg.leng/=2.54;
				lg.leng/=100;
				lg.unit="m";
			}
			else if(lg.unit=="ft")
			{
				lg.leng*=12;
				lg.leng*=2.54;
				lg.leng/=100;
				lg.unit="m";
			}
			return lg;
		}

		static void printLg(length lg)
		{
			cout <<lg.leng<<lg.unit<<", ";

		}

		static double getLength(length lg)
		{
			return lg.leng;
		}
			
};

int main()
{	
	vector<length>lengths;
	double sum;
	int counter=0;
	double tempLeng;
	string tempUnit;

	cout <<"Write a length with these units: 'cm', 'm', 'in', 'ft'!\n"
		 <<"The accepted formats: \"#.#@@\" and \"#.# @@\", where # is digit with decimal point,\n"
		 <<"and @@ means the length unit. To break the cycle, write '|'!";

	while(1)
	{
		cout <<"\n> ";
		cin>>tempLeng>>tempUnit;

		if(cin.fail())
		{
			cout<<"\n>>ERROR: Wrong format, (Not valid unit or negative length)\n";
			cout<<">>SYS.ERROR: Data income channel crashed..\n";
			break;
		}
			
		if(tempUnit=="cm"||tempUnit=="m"||tempUnit=="in"||tempUnit=="ft"&&tempLeng>=0)
		{
			if(tempUnit!="m")
			{
				lengths.push_back(length(tempLeng,tempUnit));
				lengths[counter]=length::unitChangeToM(lengths[counter]);
				counter++;
			}
			else
			{
				lengths.push_back(length(tempLeng,tempUnit));
				counter++;
			}
		}
		else
		{
			cout<<">>ERROR: Wrong format, (Not valid unit or negative length)\n";
		}
	}

	sort(lengths.begin(),lengths.end());

	cout <<"########################################"
		 <<"\n\n>>>LENGTHS:\n";

	for(int i=0;i<lengths.size();i++)
	{
		length::printLg(lengths[i]);
		sum+=length::getLength(lengths[i]);
	}

	cout <<"\n########################################"
		 <<"\n\n>>>STATS:\n"
		 <<"The smallest length: "<<length::getLength(lengths[0])<<"\n"
		 <<"The biggest length: "<<length::getLength(lengths[lengths.size()-1])<<"\n"
		 <<"The sum of all lengths: "<<sum<<"m\n"
		 <<"########################################\n";

	return 0;
}
