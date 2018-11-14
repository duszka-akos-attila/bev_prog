#include <iostream>
#include <math.h>
#include <vector>
#include <iterator>
using namespace std;


void printOut(vector<double> data)
{
	vector<double>::iterator it;
	int j=1;
	for (it=data.begin(); it!=data.end(); it++)
	{
		cout<<"The rank of the "<<j<<". link: "<<*it<<"\n";
		j++;
	}
}

double distance(vector<double> pagerank, vector<double> pagerank_temp)
{
	vector<double>::iterator itPr=pagerank.begin();
	vector<double>::iterator itPrT=pagerank_temp.begin();
	double dist = 0.0;

	for(itPr=pagerank.begin(); itPr!=pagerank.end();itPr++)
	{
		dist +=abs(*itPr - *itPrT);
		itPrT++;
	}

	return dist;
}

int main(void)
{
	vector<vector<double>> links =
	{
		{0.0, 0.0, 1.0 / 3.0, 0.0},
		{1.0, 1.0 / 2.0, 1.0 / 3.0, 1.0},
		{0.0, 1.0 / 2.0, 0.0, 0.0},
		{0.0, 0.0, 1.0 / 3.0, 0.0}
	};

	vector<double> pr = {0.0, 0.0, 0.0, 0.0};
	vector<double> prT = {1.0/4.0 ,1.0/4.0 ,1.0/4.0 ,1.0/4.0};
	vector<vector<double>>::iterator row;
	vector<double>::iterator col;

	while(1)
	{
		int i = 0;
		int j =0;
		pr=prT;

		for (row = links.begin(); row != links.end(); row++)
		{
			double temp=0;

			for (col = row->begin(); col != row->end(); col++)
			{
				temp+=*col * pr[j];
				prT[i]=temp;
				j++;
			}

			if(j%3)
			{
				j=0;
			}

			i++;
			
		}

		if ( distance(pr,prT) < 0.00001)
		{
			break;
		}
	}

	printOut (pr);
	return 0;
} 
