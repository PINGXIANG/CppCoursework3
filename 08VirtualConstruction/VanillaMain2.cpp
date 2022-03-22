#include <iostream>
#include <memory>

#include "SimpleMC4.h"
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

	PayOffCall thePayOff(Strike);
	VanillaOption theOption(thePayOff, Expiry);

	double result = SimpleMonteCarlo3(theOption, Spot, Vol, r, NumberOfPaths);

	cout << "the call price is " << result << "\n";

	VanillaOption secondOption(theOption);

	result = SimpleMonteCarlo3(secondOption, Spot, Vol, r, NumberOfPaths);

	cout << "the call price is " << result << "\n";

	PayOffPut otherPayOff(Strike);
	VanillaOption thirdOption(otherPayOff, Expiry);
	theOption = thirdOption;

	result = SimpleMonteCarlo3(thirdOption, Spot, Vol, r, NumberOfPaths);

	cout << "the put price is " << result << "\n";

	return EXIT_SUCCESS;
}
