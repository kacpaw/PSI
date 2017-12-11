#include <iostream>
#include <fstream>
#include <string>

using namespace std;


void csvReader(std::string file, double *T, int index);
void csvWritter(string file, double *T, int n);
 
int main()
{

	int nLitery = 20;
	double T[20 * 56];


	for (int i = 'A'; i <= 'T'; i++)
	{

		string file = "../../Litery/";
		file += char(i);
		file += "1.csv";
		csvReader(file, T, (i - 'A') * 56);
	}
	

	for (int i = 'A'; i <= 'T'; i++)
	{

		string file = "../../Litery/";
		file += char(i);
		file += "m1.csv";
		csvReader(file, T, (i - 'A') * 56);
	}
		csvWritter("input2.csv", T, 56 * 56);

	system("pause");
	return 0;
}

void csvReader(std::string file, double*T, int index)
{
	std::ifstream is(file);     // open file
	char  c;
	while (is.get(c))          // loop getting single characters
	{
		if (c != ',' && c != '\n')
		{
			T[index] = c - 48;
			index++;
		}
	}
	is.close();                // close file
}

void csvWritter(string file, double*T, int n)
{
	ofstream os(file);
	for (int j = 0; j < n; )
	{
		os << T[j];
		j++;
		for (int i = 1; i < 56; i++, j++)
		{
			os << "," << T[j];
		}
		os << endl;
	}
}

