#include "VarianceByWelford.h"

using namespace std;

void StatisticsWelfordSampleVariance::DumpOneResult(double result) {
	if (PathsDone > 0)
	{
		WelfordSum += (result - (RunningSum / PathsDone)) * (result - ((RunningSum + result) / (PathsDone + 1)));
	}
	else
	{
		WelfordSum += (result - 0) * (result - ((RunningSum + result) / (PathsDone + 1)));
	}
	PathsDone++;
	RunningSum += result;
}

vector<vector<double> > StatisticsWelfordSampleVariance::GetResultsSoFar() const {
	vector<vector<double> > Results{ 1 };
	double welfordvar;
	if (PathsDone < 2)
	{
		welfordvar = 0;
	}
	else
	{
		welfordvar = (WelfordSum) / (PathsDone - 1);
	}

	Results[0].resize(1);
	Results[0][0] = welfordvar;
	return Results;
}

StatisticsMC* StatisticsWelfordSampleVariance::clone() const {
	return new StatisticsWelfordSampleVariance(*this);
}