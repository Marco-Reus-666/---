#include "support.h"

using namespace std;

void update(double dt)
{
	warming += dt;
	cout << "Updating global warming to " << warming << " degrees." << endl;
}

void local(void)
{
	double warming = 0.8;

	cout << "Local warming = " << warming << " degrees" << endl;
	cout << "But global wamring = " << ::warming << " degrees" << endl;
}
