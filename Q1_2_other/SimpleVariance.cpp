#include "SimpleVariance.h"

using namespace std;

StatisticsSimpleSampleVariance::StatisticsSimpleSampleVariance() : PathsDone { 0UL }{
}

void StatisticsSimpleSampleVariance::DumpOneResult(double result) {
	VectorOfPaths.push_back(result);
	PathsDone++;
}

vector<vector<double> > StatisticsSimpleSampleVariance::GetResultsSoFar() const {
	vector<vector<double> > Results{ 1 };

	double sum1 = 0;
	double sum2 = 0;
	for (int i = 0; i < VectorOfPaths.size(); i++) {
		sum1 += VectorOfPaths[i] * VectorOfPaths[i];
		sum2 += VectorOfPaths[i];
	}

	double var = (sum1 - (sum2 * sum2) / PathsDone) / (PathsDone);

	Results[0].resize(1);
	Results[0][0] = var;
	return Results;
}

StatisticsMC* StatisticsSimpleSampleVariance::clone() const {
	return new StatisticsSimpleSampleVariance(*this);
}


//vector<vector<double> > Results{ 1 };

//double mean = 0;
//for (int i = 0; i < VectorOfPaths.size(); i++)
//	mean += VectorOfPaths[i];
//mean /= PathsDone;

//double var_x_pathsdone = 0.0;
//for (int i = 0; i < VectorOfPaths.size(); i++)
//	var_x_pathsdone += (VectorOfPaths[i] - mean) * (VectorOfPaths[i] - mean);

//Results[0].resize(1);
//Results[0][0] = var_x_pathsdone / PathsDone;
//return Results;