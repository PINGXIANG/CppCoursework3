#include <iostream>
#include <valarray>

#include "AntiThetic.h"
#include "ConvergenceTable.h"
#include "ExoticBSEngine.h"
#include "StatisticsMC.h"
#include "ParkMiller.h"
#include "PathDependentAsian.h"

using namespace std;

int main()
{
    double Expiry;
    double Strike;
    double Spot;
    double Vol;
    double r;
    double d;
    unsigned long NumberOfPaths;
    unsigned NumberOfDates;

    cout << "\nEnter expiry\n";
    cin >> Expiry;

    cout << "\nStrike\n";
    cin >> Strike;

    cout << "\nEnter spot\n";
    cin >> Spot;

    cout << "\nEnter vol\n";
    cin >> Vol;

    cout << "\nr\n";
    cin >> r;

    cout << "\nd (divident rate)\n";
    cin >> d;

    cout << "\nNumber of dates\n";
    cin >> NumberOfDates;

    cout << "\nNumber of paths\n";
    cin >> NumberOfPaths;

    PayOffCall thePayOff(Strike);


    std::valarray<double> times(NumberOfDates);

    for (unsigned long i = 0; i < NumberOfDates; i++)
        times[i] = (i + 1.0) * Expiry / NumberOfDates;

    ParametersConstant VolParam(Vol);
    ParametersConstant rParam(r);
    ParametersConstant dParam(d);

    PathDependentGeometricAsian theOption(times, Expiry, thePayOff);

    StatisticsMean gatherer;
    ConvergenceTable gathererTwo(gatherer);

    RandomParkMiller generator(NumberOfDates);

    AntiThetic GenTwo(generator);

    ExoticBSEngine theEngine(theOption, rParam, dParam, VolParam, GenTwo, Spot);

    theEngine.DoSimulation(gathererTwo, NumberOfPaths);

    vector<vector<double> > results = gathererTwo.GetResultsSoFar();

    cout << "\nFor the Asian call price the results are \n";

    for (unsigned long i = 0; i < results.size(); i++)
    {
        for (unsigned long j = 0; j < results[i].size(); j++)
            cout << results[i][j] << " ";

        cout << "\n";
    }

    return EXIT_SUCCESS;
}
