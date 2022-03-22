#include <iostream>
#include <memory>

#include "SimpleMC7.h"
#include "DoubleDigital2.h"
#include "VarianceByWelford.h"
#include "SimpleVariance.h"

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

	StatisticsWelfordSampleVariance gatherer1;
	StatisticsSimpleSampleVariance gatherer2;

	SimpleMonteCarlo5(theOption, Spot, VolParam, rParam, NumberOfPaths, gatherer1);

	vector<vector<double> > results1 = gatherer1.GetResultsSoFar();

	cout << "\nFor variance the call price the results are\n";
	for (unsigned long i = 0; i < results1.size(); ++i) {
		for (unsigned long j = 0; j < results1[i].size(); ++j)
			cout << results1[i][j] << " ";
		cout << "\n";
	}

	SimpleMonteCarlo5(theOption, Spot, VolParam, rParam, NumberOfPaths, gatherer2);

	vector<vector<double> > results2 = gatherer2.GetResultsSoFar();

	cout << "\nFor variance the call price the results are\n";
	for (unsigned long i = 0; i < results2.size(); ++i) {
		for (unsigned long j = 0; j < results2[i].size(); ++j)
			cout << results2[i][j] << " ";
		cout << "\n";
	}

	return EXIT_SUCCESS;
}
