#pragma once
#include "Neuron.h"

typedef double(*fun1)(double x);

class NeuralNetwork
{

	int inputsNumber;
	int L1NeuronsNumber;
	int L2NeuronsNumber;
	int L3NeuronsNumber;
	
	Neuron *L1Neurons;
	Neuron *L2Neurons;
	Neuron *L3Neurons;


public:
	NeuralNetwork(int inputsNumber, int L1inputsNumber, int L2NeuronsNumber, int L3NeuronsNumber, fun1 activationFunction, fun1 derivative);
	~NeuralNetwork();

	double *start(double *inputs);
	void learn(double *inputs, double *outputs);
};

