#include "NeuralNetwork.h"
#include <iostream>
#include <ctime>


double fRand(double fMin, double fMax)
{
	double f = (double)rand() / RAND_MAX;
	return fMin + f * (fMax - fMin);
	//return rand() % 2 + 1;
}


NeuralNetwork::NeuralNetwork(int m_inputsNumber, int m_L1inputsNumber, int m_L2NeuronsNumber, int m_L3NeuronsNumber, fun1 m_activationFunction, fun1 m_derivative):
	inputsNumber(m_inputsNumber),
	L1NeuronsNumber(m_L1inputsNumber),
	L2NeuronsNumber(m_L2NeuronsNumber),
	L3NeuronsNumber(m_L3NeuronsNumber)
{
	std::srand(time(NULL));
		L1Neurons = new Neuron[L1NeuronsNumber];
		double *wagi=NULL;
		for (int i = 0; i < L1NeuronsNumber; i++)
		{
			wagi = new double[inputsNumber];
			for (int j = 0; j < inputsNumber; j++)
			{
				wagi[j] = fRand(0, 1);

			}

			L1Neurons[i].setN(inputsNumber);
			L1Neurons[i].setFunkcjaAktywuj¹ca(m_activationFunction);
			L1Neurons[i].setPochodna(m_derivative);
			L1Neurons[i].setWagi(wagi);
		}

		L2Neurons = new Neuron[L2NeuronsNumber];
		for (int i = 0; i < L2NeuronsNumber; i++)
		{
			wagi = new double[L1NeuronsNumber];
			for (int j = 0; j < L1NeuronsNumber;j++)
			{
				wagi[j] = fRand(0, 1);

			}
			L2Neurons[i].setN(L1NeuronsNumber);
			L2Neurons[i].setFunkcjaAktywuj¹ca(m_activationFunction);
			L2Neurons[i].setPochodna(m_derivative);
			L2Neurons[i].setWagi(wagi);
		}



		L3Neurons = new Neuron[L3NeuronsNumber];

		for (int i = 0; i < L3NeuronsNumber; i++)
		{
			wagi = new double[L2NeuronsNumber];
			for (int j = 0; j < L2NeuronsNumber; j++)
			{
				wagi[j] = fRand(0, 1);

			}
			L3Neurons[i].setN(L2NeuronsNumber);
			L3Neurons[i].setFunkcjaAktywuj¹ca(m_activationFunction);
			L3Neurons[i].setPochodna(m_derivative);
			L3Neurons[i].setWagi(wagi);
		}
	

		////////////////////////////////////////////////////////////////////
		for (int i = 0; i < L1NeuronsNumber; i++)
		{
			for (int j = 0; j < L1Neurons[i].getN(); j++)
			{
				std::cout << L1Neurons[i].getWagi(j) << std::endl;
			}
		}

		for (int i = 0; i < L2NeuronsNumber; i++)
		{
			for (int j = 0; j < L2Neurons[i].getN(); j++)
			{
				std::cout << L2Neurons[i].getWagi(j) << std::endl;
			}
		}
		for (int i = 0; i < L3NeuronsNumber; i++)
		{
			for (int j = 0; j < L3Neurons[i].getN(); j++)
			{
				std::cout << L3Neurons[i].getWagi(j) << std::endl;
			}
		}
/////////////////////////////////////////////////////////////////////////////
}




NeuralNetwork::~NeuralNetwork()
{
}

double *NeuralNetwork::start(double *inputs)
{


	double *results1 = new double [L1NeuronsNumber];
	for (int i = 0; i < L1NeuronsNumber; i++)
	{
		results1[i]=L1Neurons[0].start(inputs);
	}

	double *results2 = new double[L2NeuronsNumber];
	for (int i = 0; i < L2NeuronsNumber; i++)
	{
		results2[i] = L2Neurons[i].start(results1);
	}


	double *results3 = new double[L3NeuronsNumber];
	for (int i = 0; i < L3NeuronsNumber; i++)
	{
		results3[i] = L3Neurons[i].start(results2);
	}
	
	delete results1, results2;

	return results3;
}

void NeuralNetwork::learn(double * inputs, double * outputs)
{

	double *results1 = new double[L1NeuronsNumber];
	for (int i = 0; i < L1NeuronsNumber; i++)
	{
		results1[i] = L1Neurons[i].start(inputs);
	}

	double *results2 = new double[L2NeuronsNumber];
	for (int i = 0; i < L2NeuronsNumber; i++)
	{
		results2[i] = L2Neurons[i].start(results1);
	}

	double *results = new double[L3NeuronsNumber];
	for (int i = 0; i < L3NeuronsNumber; i++)
	{
		results[i] = L3Neurons[i].start(results2);
	}



	//std::cout << "\n\n\nOutputErrors: \n";

	double *outputErrors = new double[L3NeuronsNumber];
	for (int i = 0; i < L3NeuronsNumber; i++)
	{
		outputErrors[i] = outputs[i]-results[i];
		//std::cout << outputErrors[i] << std::endl;
		//std::cout << outputs[i] << std::endl << results[i] << std::endl;
	}

	//std::cout << "\n\n\L2ERRORS: \n";
	double *L2Errors = new double[L2NeuronsNumber];
	for (int i = 0; i < L2NeuronsNumber; i++)
	{
		L2Errors[i] = 0;
		for (int j = 0; j < L3NeuronsNumber; j++)
		{
			L2Errors[i] += outputErrors[j] * L3Neurons[j].getWagi(i);
			//std::cout << L2Errors[i] << std::endl;
		}
	}

	//std::cout << "\n\n\L1ERRORS: \n";
	double *L1Errors = new double[L1NeuronsNumber];
	for (int i = 0; i < L1NeuronsNumber; i++)
	{
		L1Errors[i] = 0;
		for (int j = 0; j < L2NeuronsNumber; j++)
		{
			L1Errors[i] += L2Errors[j] * L2Neurons[j].getWagi(i);
			//std::cout << L1Errors[i] << std::endl;
			//std::cout << "errors2: " << L2Errors[j] << " wagi: " << L2Neurons[j].getWagi(i) << std::endl;
		}
	}


	double ni = 0.1;

	for (int i = 0; i < L1NeuronsNumber; i++)
	{
		for (int j = 0; j < L1Neurons[i].getN(); j++)
		{
			L1Neurons[i].setWagi(L1Neurons[i].getWagi(j) + ni*L1Errors[i] * L1Neurons[i].getPochodna()(results1[i])*inputs[j], j);
		}
	}

	for (int i = 0; i < L2NeuronsNumber; i++)
	{
		for (int j = 0; j < L2Neurons[i].getN(); j++)
		{
			L2Neurons[i].setWagi(L2Neurons[i].getWagi(j) + ni*L2Errors[i] * L2Neurons[i].getPochodna()(results2[i])*results1[j], j);
		}
	}

	for (int i = 0; i < L3NeuronsNumber; i++)
	{
		for (int j = 0; j < L3Neurons[i].getN(); j++)
		{
			L3Neurons[i].setWagi(L3Neurons[i].getWagi(j) + ni*outputErrors[i] * L3Neurons[i].getPochodna()(results[i])*results2[j], j);
		}
	}

}
