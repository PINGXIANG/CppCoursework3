#pragma once

#include "StatisticsMC.h"

class StatisticsSimpleSampleVariance : public StatisticsMC {
public:
	void DumpOneResult(double result) override;
	std::vector<std::vector<double> > GetResultsSoFar() const override;
	StatisticsMC* clone() const override;

private:
	std::vector<double> VectorOfPaths;
	unsigned long PathsDone{ 0UL };
};