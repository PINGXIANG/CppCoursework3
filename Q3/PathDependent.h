#pragma once

#include <valarray>
#include <vector>

class CashFlow {
public:
	double Amount;
	unsigned long TimeIndex;

	CashFlow(unsigned long TimeIndex_ = 0UL, double Amount_ = 0.0)
		:TimeIndex{ TimeIndex_ }, Amount{ Amount_ } {};
};

class PathDependent {
public:
	PathDependent(const std::valarray<double>& LookAtTimes);

	const std::valarray<double>& GetLookAtTimes() const;

	virtual unsigned long MaxNumberOfCashFlows() const = 0;
	virtual std::valarray<double> PossibleCashFlowTimes() const = 0;
	virtual unsigned long CashFlows(const std::valarray<double>& SpotValues, std::vector<CashFlow>& GeneratedFlows) const = 0;
	virtual PathDependent* clone() const = 0;
	virtual ~PathDependent() {}

private:
	std::valarray<double> LookAtTimes;
};
