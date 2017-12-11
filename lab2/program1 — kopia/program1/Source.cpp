#include "Neuron.h"
#include <iostream>
#include <ctime>
#include <fstream>
#include <map>
#include <cmath>

using namespace std;

double ucz(Neuron *neuron, double** inputs, double **outputs, int n, double ni);
void csvReader(std::string file, double*T, int index);




double funkcjaAktywuj¹ca(double x, double threshold)
{
	if (x >= threshold)
	return 1;
	else
 return -1;
	//return 0.5*x;
}


int main()
{
	

	srand(time(NULL));
	double **output=new double*[20];
	for (int i = 0; i < 20; i++)
		output[i] = new double[2];

	for (int i = 0; i < 20; i++)
	{
		if (i < 10)
		{
			output[i][0] = 1;
			output[i][1] = -1;
		}
		else
		{
			output[i][1] = 1;
			output[i][0] = -1;
		}
	}

	double inputs[20 * 56];
	double **_inputs=new double*[20];
	for (int i = 0; i < 20; i++)
	{
		_inputs[i] = new double[56];
	}




	for (int i = 'A'; i <= 'J'; i++)
	{

		string file = "../../Litery/";
		file += char(i);
		file += "1.csv";
		csvReader(file, _inputs[i-'A'], 0);
	}


	for (int i = 'a'; i <= 'j'; i++)
	{
		string file = "../../Litery/";
		file += char(i);
		file += "m1.csv";
		csvReader(file, _inputs[i - 'a'+10], 0);
	}



	Neuron neurons[2];
	double ni = 0.07;


	ofstream wyniki("wyniki.txt");

	double iteracje = 0;

	for (int l = 0; l < 500; l++)
	{
		ni += 0.002;
		iteracje = 0;
		for (int k = 0; k < 10; k++)
		{
			for (int i = 0; i < 2; i++)
			{
				neurons[i].setActivatingFunction(funkcjaAktywuj¹ca);
				neurons[i].setN(56);
			}

			//cout << "Uczenie: " << endl;
			double error = 1;
			int i = 0;
			while (error > 0.0001 && error >-1)
			{
				error = ucz(neurons, _inputs, output, 2, ni);
				cout << "numer iteracji: " << i << "   blad sredniokwadratowy: " << error << endl;
				i++;
			}

			//cout << "liczba iteracji: " << i << endl;
			iteracje += i;

			
			for (int i = 'A'; i <= 'J'; i++)
			{
				cout << (char)i << ": " << neurons[0].start(_inputs[i - 'A']) << " " << neurons[1].start(_inputs[i - 'A']) << endl;
			}
			for (int i = 'a'; i <= 'j'; i++)
			{
				cout << (char)i << ": " << neurons[0].start(_inputs[i - 'a' + 10]) << " "<< neurons[1].start(_inputs[i - 'a' + 10]) << endl;
			}
			
			system("pause");
		}

		cout << endl << "wsp. uczenia: " << ni << "		œrednia liczba iteracji: " << iteracje / 10;
		wyniki << ni << "," << iteracje / 5 << endl;
	}

	system("pause");
	return 0;
}


double ucz(Neuron *neuron, double** inputs, double **outputs, int n, double ni)
{
	double error1=0, error=0;


	int j;
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			
			error1 = neuron[j].learn(inputs[i], outputs[i][j], ni);

			error += error1*error1;
		}

	}

	return error/2;
}

void csvReader(std::string file, double*T, int index)
{
	std::ifstream is(file);
	char  c;
	while (is.get(c))
	{
		if (c != ',' && c != '\n')
		{
			if (c == 48)
				T[index] = -1;
			else
				T[index] = 1;

			index++;
		}
	}
	is.close();
}