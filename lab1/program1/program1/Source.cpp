#include <iostream>
#include "Neuron.h"
#include <ctime>


void testuj(Neuron *neuron, double **inputs );
double ucz(Neuron *neuron, double** inputs, double *outputs, int n, double ni);


double funkcjaAktywuj¹ca(double x, double threshold)
{
	if (x >= threshold)
		return 1;
	else
		return 0;
}

int main()
{
	double **inputs = new double*[4];
	for (int i = 0; i < 4; i++)
		inputs[i] = new double[2];
	
	inputs[0][0] = 0; 	inputs[0][1] = 0;
	inputs[1][0] = 0; 	inputs[1][1] = 1;
	inputs[2][0] = 1; 	inputs[2][1] = 0;
	inputs[3][0] = 1; 	inputs[3][1] = 1;
	double outputs[4] = { 0,1,1,1 };


	Neuron *neuron1=new Neuron(2);
	Neuron *neuron2 = new Neuron(2);
	Neuron *neuron3 = new Neuron(2);
	Neuron *neuron4 = new Neuron(2);
	Neuron *neuron5 = new Neuron(2);
	Neuron *neuron6 = new Neuron(2);

	neuron1->setFunkcjaAktywuj¹ca(funkcjaAktywuj¹ca);
	neuron2->setFunkcjaAktywuj¹ca(funkcjaAktywuj¹ca);
	neuron3->setFunkcjaAktywuj¹ca(funkcjaAktywuj¹ca);
	neuron4->setFunkcjaAktywuj¹ca(funkcjaAktywuj¹ca);
	neuron5->setFunkcjaAktywuj¹ca(funkcjaAktywuj¹ca);
	neuron6->setFunkcjaAktywuj¹ca(funkcjaAktywuj¹ca);


	double e=1;
	int i;
	for (i = 0; e>0; i++)
	{
		(e = ucz(neuron1, inputs, outputs, 4, 0.001));
	}
	std::cout << i << " cykli uczenia\n";

	system("pause");
	return 0;
}





void testuj(Neuron *neuron, double **inputs)
{
	std::cout << "0: " << neuron->start(inputs[0]) << std::endl;
	std::cout << "1: " << neuron->start(inputs[1]) << std::endl;
	std::cout << "1: " << neuron->start(inputs[2]) << std::endl;
	std::cout << "1: " << neuron->start(inputs[3]) << std::endl;

}

double ucz(Neuron *neuron, double** inputs, double *outputs, int n, double ni)
{
	double error1=0, error=0;
	bool *T = new bool[n];
	for (int i = 0; i < n; i++)
	{
		T[i] = false;
	}
	int j;
	for (int i = 0; i < n; i++)
	{

		j = rand()%n;
		while (T[j] == true)
		{
			j = rand() % n;
		}
		T[j] = true;
		error1 = 0;
		error1+=neuron->learn(inputs[j], outputs[j], ni);
		error += error1*error1;
	}

	return error/2;
}