#include "VarianceByWelford.h"

using namespace std;


void StatisticsWelfordSampleVariance::DumpOneResult(double result) {
	PathsDone++;
	RunningSum += result;
	RunningSquareSum += result*result;
}

vector<vector<double> > StatisticsWelfordSampleVariance::GetResultsSoFar() const {
	vector<vector<double> > Results{ 1 };

	Results[0].resize(1);
	Results[0][0] = (RunningSquareSum - (RunningSum * RunningSum) / PathsDone) / (PathsDone-1);

	return Results;
}

StatisticsMC* StatisticsWelfordSampleVariance::clone() const {
	return new StatisticsWelfordSampleVariance(*this);
}