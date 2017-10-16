#include "Neuron.h"
#include <cstdlib>
#include <iostream>


Neuron::Neuron()
{
	wagi = NULL;
}

Neuron::Neuron(int m_n):
	n(m_n)
{
	wagi = new double[n];
	for (int i = 0; i < n; i++)
	{
		wagi[i] = 0.5;
	}
}

Neuron::Neuron(int m_n, double *m_wagi):
	n(m_n), 
	wagi(m_wagi)
{}

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

void Neuron::setPochodna(fun1 m_pochodna)
{
	pochodna = m_pochodna;
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
	double a = sumowanie(m_inputs);
	return funkcjaAktywuj¹ca(a);
	
}

double Neuron::sumowanie(double *m_input)
{

	double suma=0;
	for (int i = 0; i < n; i++)
	{
		suma += wagi[i] * m_input[i];
	}

	return suma;
}



Neuron::~Neuron()
{
	delete wagi;
}
