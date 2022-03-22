#include <iostream>
#include <memory>

#include "AntiThetic.h"
#include "SimpleMC8.h"
#include "ParkMiller.h"
#include "ConvergenceTable.h"
#include "DoubleDigital2.h"
#include "StatisticsMC.h"
#include "Vanilla3.h"

using namespace std;

int main() {
	double Expiry;
	double Strike;
	double Spot;
	double Vol;
	double r;
	unsigned long NumberOfPaths;

	cout << "\nEnter expiry\n";
	cin >> Expiry;
	cout << "\nEnter strike\n";
	cin >> Strike;
	cout << "\nEnter spot\n";
	cin >> Spot;
	cout << "\nEnter vol\n";
	cin >> Vol;
	cout << "\nEnter r\n";
	cin >> r;
	cout << "\nNumber of paths\n";
	cin >> NumberOfPaths;

	ParametersConstant VolParam(Vol);
	ParametersConstant rParam(r);

	PayOffCall thePayOff(Strike);
	VanillaOption theOption(thePayOff, Expiry);

	StatisticsMean gatherer;
	ConvergenceTable gathererTwo(gatherer);

	RandomParkMiller generator(1);
	AntiThetic GenTwo(generator);

	SimpleMonteCarlo6(theOption, Spot, VolParam, rParam, NumberOfPaths, gathererTwo, GenTwo);

	vector<vector<double> > results = gathererTwo.GetResultsSoFar();

	cout << "\nFor the call price the results are\n";
	for (unsigned long i = 0; i < results.size(); ++i) {
		for (unsigned long j = 0; j < results[i].size(); ++j)
			cout << results[i][j] << " ";
		cout << "\n";
	}

	return EXIT_SUCCESS;
}
