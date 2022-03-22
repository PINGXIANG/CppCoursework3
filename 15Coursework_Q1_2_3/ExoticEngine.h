#pragma once

#include <vector>

#include "Wrapper.h"
#include "Parameters.h"
#include "PathDependent.h"
#include "StatisticsMC.h"

class ExoticEngine {
public:
	ExoticEngine(const Wrapper<PathDependent>& TheProduct_, const Parameters& r_);
	virtual void GetOnePath(std::valarray<double>& SpotValues) = 0;
	void DoSimulation(StatisticsMC& TheGatherer, unsigned long NumberOfPaths);
	virtual ~ExoticEngine() {}
	double DoOnePath(const std::valarray<double>& SpotValues) const;

private:
	Wrapper<PathDependent> TheProduct;
	Parameters r;
	std::valarray<double> Discounts;
	mutable std::vector<CashFlow> TheseCashFlows;
};