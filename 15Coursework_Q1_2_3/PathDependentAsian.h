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
        std::vector<CashFlow>& GeneratedFlows) const = 0;
    virtual ~PathDependentAsian() {}
    virtual PathDependent* clone() const = 0;

protected:

    double DeliveryTime;
    PayOffBridge ThePayOff;
    unsigned int NumberOfTimes;
};

class PathDependentArithmeticAsian : public PathDependentAsian
{
public:

    PathDependentArithmeticAsian(const std::valarray<double>& LookAtTimes_,
        double DeliveryTime_,
        const PayOffBridge& ThePayOff_);

    virtual unsigned long CashFlows(const std::valarray<double>& SpotValues,
        std::vector<CashFlow>& GeneratedFlows) const;
    virtual ~PathDependentArithmeticAsian() {}
    virtual PathDependent* clone() const;
};

class PathDependentGeometricAsian : public PathDependentAsian
{
public:

    PathDependentGeometricAsian(const std::valarray<double>& LookAtTimes_,
        double DeliveryTime_,
        const PayOffBridge& ThePayOff_);

    virtual unsigned long CashFlows(const std::valarray<double>& SpotValues,
        std::vector<CashFlow>& GeneratedFlows) const;
    virtual ~PathDependentGeometricAsian() {}
    virtual PathDependent* clone() const;
};
