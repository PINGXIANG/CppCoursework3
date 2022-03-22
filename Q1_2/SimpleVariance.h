#pragma once

#include "StatisticsMC.h"
#include <numeric>

class StatisticsSimpleSampleVariance : public StatisticsMC {
public:
	StatisticsSimpleSampleVariance();
	virtual void DumpOneResult(double result);
	virtual std::vector<std::vector<double> > GetResultsSoFar() const;
	virtual StatisticsMC* clone() const;

private:
	std::vector<double> VectorOfPaths;
};