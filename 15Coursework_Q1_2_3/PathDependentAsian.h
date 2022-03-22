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

    unsigned long MaxNumberOfCashFlows() const override;
    std::valarray<double> PossibleCashFlowTimes() const override;
    
    unsigned long CashFlows(const std::valarray<double>& SpotValues,
        std::vector<CashFlow>& GeneratedFlows) const final;
    
protected:
    PayOffBridge ThePayOff;
    unsigned int NumberOfTimes;

    virtual double CalculateMean(const std::valarray<double>& SpotValues) const = 0;

private:
    double DeliveryTime;
};

class PathDependentArithmeticAsian : public PathDependentAsian
{
public:
    PathDependentArithmeticAsian(const std::valarray<double>& LookAtTimes_,
        double DeliveryTime_,
        const PayOffBridge& ThePayOff_);

    ~PathDependentArithmeticAsian() override = default;
    PathDependent* clone() const override;

protected:
    double CalculateMean(const std::valarray<double>& SpotValues) const override;
};

class PathDependentGeometricAsian : public PathDependentAsian
{
public:
    PathDependentGeometricAsian(const std::valarray<double>& LookAtTimes_,
        double DeliveryTime_,
        const PayOffBridge& ThePayOff_);

    ~PathDependentGeometricAsian() override = default;
    PathDependent* clone() const override;

protected:
    double CalculateMean(const std::valarray<double>& SpotValues) const override;
};
