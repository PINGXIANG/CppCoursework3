#include "SimpleVariance.h"

using namespace std;

void StatisticsSimpleSampleVariance::DumpOneResult(double result) {
	VectorOfPaths.push_back(result);
	PathsDone++;
}

vector<vector<double> > StatisticsSimpleSampleVariance::GetResultsSoFar() const {
	vector<vector<double> > Results{ 1 };

	double sum1 = 0;
	double sum2 = 0;
	for (double path : VectorOfPaths) {
		sum1 += path * path;
		sum2 += path;
	}

	double var = (sum1 - (sum2 * sum2) / PathsDone) / PathsDone;

	Results[0].resize(1);
	Results[0][0] = var;
	return Results;
}

StatisticsMC* StatisticsSimpleSampleVariance::clone() const {
	return new StatisticsSimpleSampleVariance(*this);
}