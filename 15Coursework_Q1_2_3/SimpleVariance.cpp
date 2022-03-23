#include "SimpleVariance.h"

using namespace std;

void StatisticsSimpleSampleVariance::DumpOneResult(double result) {
	VectorOfPaths.push_back(result);
	PathsDone++;
}

vector<vector<double> > StatisticsSimpleSampleVariance::GetResultsSoFar() const {
	
	vector<vector<double> > Results{ 1 };
	double var;
	if (PathsDone < 2)
	{
		var = 0;
	}
	else
	{
		double squared_sum = 0;
		double sum = 0;
		for (double path : VectorOfPaths) {
			squared_sum += path * path;
			sum += path;
		}

		var = (squared_sum - (sum * sum) / PathsDone) / (PathsDone - 1);
	}

	Results[0].resize(1);
	Results[0][0] = var;
	return Results;
}

StatisticsMC* StatisticsSimpleSampleVariance::clone() const {
	return new StatisticsSimpleSampleVariance(*this);
}