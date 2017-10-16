#pragma once
typedef double(*fun1)(double x);

class Neuron
{
public:
	Neuron();
	Neuron(int n);
	Neuron(int n, double *wagi);
	~Neuron();

	void setWagi(double *m_wagi);
	void setWagi(double x, int i);
	void setN(int m_n);
	void setFunkcjaAktywuj¹ca(fun1 funkcjaAktywuj¹ca);
	void setPochodna(fun1 m_pochodna);
	double getWagi(int i);
	int getN() { return n; }
	double start(double *m_input);
	fun1 getPochodna() { return pochodna; };

private:
	double *wagi;
	int n;
	fun1 funkcjaAktywuj¹ca;
	fun1 pochodna;
	
	double sumowanie(double *m_input);
};

