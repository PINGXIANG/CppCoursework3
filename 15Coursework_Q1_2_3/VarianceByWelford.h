#pragma once

#include "StatisticsMC.h"

class StatisticsWelfordSampleVariance : public StatisticsMC {
public:
	void DumpOneResult(double result) override;
	std::vector<std::vector<double> > GetResultsSoFar() const override;
	StatisticsMC* clone() const override;

private:
	double RunningSum{ 0.0 };
	double WelfordSum{ 0.0 };
	unsigned long PathsDone{ 0UL };
};