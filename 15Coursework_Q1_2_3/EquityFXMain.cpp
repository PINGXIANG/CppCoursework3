#include <iostream>
#include <valarray>

#include "AntiThetic.h"
#include "ConvergenceTable.h"
#include "ExoticBSEngine.h"
#include "StatisticsMC.h"
#include "ParkMiller.h"
#include "PathDependentAsian.h"
#include "VarianceByWelford.h"
#include "SimpleVariance.h"

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

    cout << "\nd (dividend rate)\n";
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

    PathDependentArithmeticAsian theOption1(times, Expiry, thePayOff);
    PathDependentGeometricAsian theOption2(times, Expiry, thePayOff);

    StatisticsMean gatherer1;
    ConvergenceTable gathererOne(gatherer1);

    StatisticsMean gatherer1_;
    ConvergenceTable gathererOne_(gatherer1_);

    StatisticsWelfordSampleVariance gatherer2;
    ConvergenceTable gathererTwo(gatherer2);

    StatisticsWelfordSampleVariance gatherer2_;
    ConvergenceTable gathererTwo_(gatherer2_);

    StatisticsSimpleSampleVariance gatherer3;
    ConvergenceTable gathererThree(gatherer3);

    StatisticsSimpleSampleVariance gatherer3_;
    ConvergenceTable gathererThree_(gatherer3_);

    RandomParkMiller generator(NumberOfDates);

    AntiThetic GenTwo(generator);

    ExoticBSEngine theEngine1(theOption1, rParam, dParam, VolParam, GenTwo, Spot);

    theEngine1.DoSimulation(gathererOne, NumberOfPaths);
    vector<vector<double> > results1 = gathererOne.GetResultsSoFar();

    theEngine1.DoSimulation(gathererTwo, NumberOfPaths);
    vector<vector<double> > results2 = gathererTwo.GetResultsSoFar();

    theEngine1.DoSimulation(gathererThree, NumberOfPaths);
    vector<vector<double> > results3 = gathererThree.GetResultsSoFar();

    cout << "\nFor the Arithmetic Asian call price the results are \n";

    for (unsigned long i = 0; i < results1.size(); i++)
    {
        for (unsigned long j = 0; j < results1[i].size(); j++)
            cout << results1[i][j] << " ";

        cout << "\n";
    }

    cout << "\nFor the Arithmetic Asian call simulation (different sim) variance results are \n";

    for (unsigned long i = 0; i < results2.size(); i++)
    {
        for (unsigned long j = 0; j < results2[i].size(); j++)
            cout << results2[i][j] << " ";

        cout << "\n";
    }

    cout << "\nFor the Arithmetic Asian call simulation (different sim) Welford variance results are \n";

    for (unsigned long i = 0; i < results3.size(); i++)
    {
        for (unsigned long j = 0; j < results3[i].size(); j++)
            cout << results3[i][j] << " ";

        cout << "\n";
    }

    ExoticBSEngine theEngine2(theOption2, rParam, dParam, VolParam, GenTwo, Spot);

    theEngine2.DoSimulation(gathererOne_, NumberOfPaths);
    vector<vector<double> > results4 = gathererOne_.GetResultsSoFar();

    theEngine2.DoSimulation(gathererTwo_, NumberOfPaths);
    vector<vector<double> > results5 = gathererTwo_.GetResultsSoFar();

    theEngine2.DoSimulation(gathererThree_, NumberOfPaths);
    vector<vector<double> > results6 = gathererThree_.GetResultsSoFar();

    cout << "\nFor the Geometric Asian call price the results are \n";

    for (unsigned long i = 0; i < results4.size(); i++)
    {
        for (unsigned long j = 0; j < results4[i].size(); j++)
            cout << results4[i][j] << " ";

        cout << "\n";
    }

    cout << "\nFor the Geometric Asian call simulation (different sim) variance results are \n";

    for (unsigned long i = 0; i < results5.size(); i++)
    {
        for (unsigned long j = 0; j < results5[i].size(); j++)
            cout << results5[i][j] << " ";

        cout << "\n";
    }

    cout << "\nFor the Geometric Asian call simulation (different sim) Welford variance results are \n";

    for (unsigned long i = 0; i < results6.size(); i++)
    {
        for (unsigned long j = 0; j < results6[i].size(); j++)
            cout << results6[i][j] << " ";

        cout << "\n";
    }

    return EXIT_SUCCESS;
}
