#include "Neuron.h"
#include <cstdlib>
#include <iostream>
#include <ctime>




double fRand(double fMin, double fMax)
{
	double f = (double)rand() / RAND_MAX;
	return fMin + f * (fMax - fMin);
}

Neuron::Neuron()
{
	wagi = NULL;
	funkcjaAktywuj¹ca = NULL;
	srand(time(NULL));
	threshold = 0;
	b = 0;
}

Neuron::Neuron(int m_n) :
	n(m_n)
{
	funkcjaAktywuj¹ca = NULL;
	srand(time(NULL));
	threshold = 0;
	b = 0;
	wagi = new double[n];
	for (int i = 0; i < n; i++)
	{
		wagi[i] = fRand(-0.5, 0.5);
	}
}

Neuron::Neuron(int m_n, double *m_wagi) :
	n(m_n),
	wagi(m_wagi)
{
	threshold = 0;
	funkcjaAktywuj¹ca = NULL;
	srand(time(NULL));
	b = 0;
}

void Neuron::setWagi(double *m_wagi)
{
	wagi = m_wagi;
}

void Neuron::setWagi(double x, int i)
{
	if (wagi != NULL && i < n)
	{
		wagi[i] = x;
	}
	else
	{
		throw "error-setWagi";
	}
}

void Neuron::setN(int m_n)
{
	n = m_n;
	
}

void Neuron::setFunkcjaAktywuj¹ca(fun1 m_funkcjaAktywuj¹ca)
{
	funkcjaAktywuj¹ca = m_funkcjaAktywuj¹ca;
}

double Neuron::getWagi(int i)
{
	if (wagi != NULL && i < n)
	{
		return wagi[i];
	}
	else
	{
		throw "error-getWagi";
	}
}

double Neuron::start(double *m_inputs)
{
	if (funkcjaAktywuj¹ca == NULL)
		throw "ustaw funkcje aktywujaca!";
	double a = sumowanie(m_inputs);
	return funkcjaAktywuj¹ca(a, threshold);

}

double Neuron::learn(double * input, double output, double ni)
{


	double result = this->start(input);
	double error = output - result;
	if (result != output)
	{
		for (int i = 0; i < n; i++)
		{
			wagi[i] += ni*error*input[i];
		}
		b += ni*error;

	}

	return error;
}

double Neuron::sumowanie(double *m_input)
{

	double suma = 0;
	for (int i = 0; i < n; i++)
	{
		suma += wagi[i] * m_input[i];
	}

	return suma+b;
}

Neuron::~Neuron()
{
	delete wagi;
}
