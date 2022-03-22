#include "SimpleVariance.h"

using namespace std;

StatisticsSimpleSampleVariance::StatisticsSimpleSampleVariance() : VectorOfPaths{ 0.0 } {
}

void StatisticsSimpleSampleVariance::DumpOneResult(double result) {
	VectorOfPaths.push_back(result);
}

vector<vector<double> > StatisticsSimpleSampleVariance::GetResultsSoFar() const {
	vector<vector<double> > Results{ 1 };

	double mean = accumulate(VectorOfPaths.begin(), VectorOfPaths.end(),decltype(VectorOfPaths)::value_type(0))/ VectorOfPaths.size();

	Results[0].resize(1);
	Results[0][0] = (VectorOfPaths[VectorOfPaths.size()] - mean) * (VectorOfPaths[VectorOfPaths.size()] - mean) / VectorOfPaths.size();

	return Results;
}

StatisticsMC* StatisticsSimpleSampleVariance::clone() const {
	return new StatisticsSimpleSampleVariance(*this);
}