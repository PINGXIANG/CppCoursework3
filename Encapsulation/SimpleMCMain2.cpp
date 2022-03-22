#include <iostream>

#include "SimpleMC.h"

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

	PayOff callPayOff(Strike, PayOff::OptionType::call);
	PayOff putPayOff(Strike, PayOff::OptionType::put);

	double resultCall = SimpleMonteCarlo2(callPayOff, Expiry, Spot, Vol, r, NumberOfPaths);
	double resultPut = SimpleMonteCarlo2(putPayOff, Expiry, Spot, Vol, r, NumberOfPaths);

	cout << "the prices are " << resultCall << " for the call and " << resultPut << " for the put\n";

	return EXIT_SUCCESS;
}
