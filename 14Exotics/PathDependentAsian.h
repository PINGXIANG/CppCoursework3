#pragma once

#include <valarray>

#include "PathDependent.h"
#include "PayOffBridge.h"

class PathDependentAsian : public PathDependent
{
public:

    PathDependentAsian(const std::valarray<double>& LookAtTimes_,
        double DeliveryTime_,
        const PayOffBridge& ThePayOff_);

    virtual unsigned long MaxNumberOfCashFlows() const;
    virtual std::valarray<double> PossibleCashFlowTimes() const;
    virtual unsigned long CashFlows(const std::valarray<double>& SpotValues,
        std::vector<CashFlow>& GeneratedFlows) const;
    virtual ~PathDependentAsian() {}
    virtual PathDependent* clone() const;

private:

    double DeliveryTime;
    PayOffBridge ThePayOff;
    unsigned long NumberOfTimes;
};
