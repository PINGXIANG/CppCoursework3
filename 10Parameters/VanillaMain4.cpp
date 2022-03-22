#include <iostream>
#include <memory>

#include "SimpleMC6.h"
#include "DoubleDigital2.h"

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

	double result = SimpleMonteCarlo5(theOption, Spot, VolParam, rParam, NumberOfPaths);

	cout << "the call price is " << result << "\n";

	VanillaOption secondOption(theOption);

	result = SimpleMonteCarlo5(secondOption, Spot, VolParam, rParam, NumberOfPaths);

	cout << "the call price is " << result << "\n";

	PayOffPut otherPayOff(Strike);
	VanillaOption thirdOption(otherPayOff, Expiry);
	theOption = thirdOption;

	result = SimpleMonteCarlo5(thirdOption, Spot, VolParam, rParam, NumberOfPaths);

	cout << "the put price is " << result << "\n";

	return EXIT_SUCCESS;
}
