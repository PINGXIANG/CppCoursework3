#include <iostream>
#include <memory>

#include "SimpleMC2.h"

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

	unsigned long optionType;

	cout << "\nEnter 0 for call, otherwise put ";
	cin >> optionType;

	std::unique_ptr<PayOff> thePayOffPtr;
	if (optionType == 0)
		thePayOffPtr = make_unique<PayOffCall>(Strike);
	else
		thePayOffPtr = make_unique<PayOffPut>(Strike);

	double result = SimpleMonteCarlo2(*thePayOffPtr, Expiry, Spot, Vol, r, NumberOfPaths);

	cout << "the price is " << result << "\n";

	return EXIT_SUCCESS;
}
