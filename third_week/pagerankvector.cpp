#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

void printOut(vector<double> data)
{
	for (int i=0; i<4; i++)
	{
		cout<<"The rank of the "<<i+1<<". link: "<<data[i]<<"\n";
	}
}

double distance(vector<double> pagerank, vector<double> pagerank_temp)
{
	double dist = 0.0;

	for(int i=0;i<4;i++)
	{
		dist +=abs(pagerank[i] - pagerank_temp[i]);
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
	vector<double> prT = {1.0/4.0, 1.0/4.0 ,1.0/4.0 ,1.0/4.0};

	int i;

	while(1)
	{
		for(i=0;i<4;i++)
		{
			pr[i] = prT[i];
		}

		for (i=0;i<4;i++)
		{
			double temp=0;

			for (int j=0;j<4;j++)
			{
				temp+=links[i][j]*pr[j];
			}

			prT[i]=temp;
		}

		if ( distance(pr,prT) < 0.00001)
		{
			break;
		}
	}

	printOut (pr);
	return 0;
} 
