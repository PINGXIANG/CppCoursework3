#pragma once

#include "StatisticsMC.h"

class StatisticsWelfordSampleVariance : public StatisticsMC {
public:
	StatisticsWelfordSampleVariance();
	virtual void DumpOneResult(double result);
	virtual std::vector<std::vector<double> > GetResultsSoFar() const;
	virtual StatisticsMC* clone() const;

private:
	double RunningSum;
	double RunningSquareSum;
	unsigned long PathsDone;
};