#include <iostream>
#include "Neuron.h"
#include "NeuralNetwork.h"
#include <fstream>
//#include <string>



double function1(double x);
double function2(double x);
double *csvReader(std::string file);

void funk()
{
	int a = 0;
}

int main()
{
	

	//NeuralNetwork *n1 = new NeuralNetwork(64, 16, 16, 2, function1, function2);
	//
	//double outputs[2] = { 0,1 };
	//double *d;
	//
	//d = n1->start(csvReader("../a1.csv"));
	//std::cout << d[0] << " " << d[1];
	//
	//n1->learn(csvReader("../a1.csv"), outputs);
	//n1->learn(csvReader("../a1.csv"), outputs);
	//n1->learn(csvReader("../a1.csv"), outputs);

	//d=n1->start(csvReader("../a1.csv"));
	//std::cout << d[0] << " " << d[1];
	//
	//n1->learn(csvReader("../a1.csv"), outputs);
	//n1->learn(csvReader("../a1.csv"), outputs);
	//n1->learn(csvReader("../a1.csv"), outputs);

	//d = n1->start(csvReader("../a1.csv"));
	//std::cout << d[0] << " " << d[1];


	NeuralNetwork *n = new NeuralNetwork(2, 1, 2, 1, function1, function2);

	double input[2] = { 1,0 };
	double output[1] = { 1 };

	double input2[2] = { 0,1 };
	double output2[1] = { 0 };

	double *a = n->start(input);
	std::cout<< std::endl << "WYNIK: " << a[0] << " " << std::endl;
	n->learn(input, output);
	a = n->start(input);
	std::cout << std::endl << "WYNIK: " << a[0] << " " << std::endl;
	n->learn(input, output);
	a = n->start(input);
	std::cout << std::endl << "WYNIK: " << a[0] << " " << std::endl;
	n->learn(input, output);
	a = n->start(input);
	std::cout << std::endl << "WYNIK: " << a[0] << " " << std::endl;
	n->learn(input, output);
	a = n->start(input);
	std::cout << std::endl << "WYNIK: " << a[0] << " " << std::endl;
	n->learn(input, output);
	a = n->start(input);
	std::cout << std::endl << "WYNIK: " << a[0] << " " << std::endl;


	a = n->start(input2);
	std::cout << std::endl << "WYNIK: " << a[0] << " " << std::endl;

	n->learn(input2, output2);
	a = n->start(input2);
	std::cout << std::endl << "WYNIK: " << a[0] << " " << std::endl;

	system("pause");
	return 0;
}


double function1(double x)
{
	return 2*x;
}

double function2(double x)
{
	return 2;
}


double* csvReader(std::string file)
{


	std::ifstream is(file);     // open file
	double *input=new double[64];
	char  c;
	int i = 0;
	while (is.get(c))          // loop getting single characters
	{
		if (c != ',' && c != '\n')
		{
				input[i] = c-48;
				i++;
		}
	}
	is.close();                // close file

	return input;
}
