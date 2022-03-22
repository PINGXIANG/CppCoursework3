#include <valarray>
#include <numeric>

#include "PathDependentAsian.h"

PathDependentAsian::PathDependentAsian(const std::valarray<double>& LookAtTimes_,
    double DeliveryTime_,
    const PayOffBridge& ThePayOff_)
    :
    PathDependent(LookAtTimes_),
    DeliveryTime(DeliveryTime_),
    ThePayOff(ThePayOff_),
    NumberOfTimes(LookAtTimes_.size())
{
}

unsigned long PathDependentAsian::MaxNumberOfCashFlows() const
{
    return 1UL;
}

std::valarray<double> PathDependentAsian::PossibleCashFlowTimes() const
{
    std::valarray<double> tmp(1UL);
    tmp[0] = DeliveryTime;
    return tmp;
}

/*Arithmetic*/
PathDependentArithmeticAsian::PathDependentArithmeticAsian(const std::valarray<double>& LookAtTimes_,
    double DeliveryTime_,
    const PayOffBridge& ThePayOff_)
    :
    PathDependentAsian(LookAtTimes_, DeliveryTime_, ThePayOff_)
{
}

unsigned long PathDependentArithmeticAsian::CashFlows(const std::valarray<double>& SpotValues,
    std::vector<CashFlow>& GeneratedFlows) const
{
    double sum = SpotValues.sum();
    double mean = sum / NumberOfTimes;

    GeneratedFlows[0].TimeIndex = 0UL;
    GeneratedFlows[0].Amount = ThePayOff(mean);

    return 1UL;
}

PathDependent* PathDependentArithmeticAsian::clone() const
{
    /// <summary>
    ///  Have to clone in non abstructue child class.
    /// </summary>
    /// <returns></returns>
    return new PathDependentArithmeticAsian(*this);
}


/*Geometric*/
PathDependentGeometricAsian::PathDependentGeometricAsian(const std::valarray<double>& LookAtTimes_,
    double DeliveryTime_,
    const PayOffBridge& ThePayOff_)
    :
    PathDependentAsian(LookAtTimes_, DeliveryTime_, ThePayOff_)
{
}

unsigned long PathDependentGeometricAsian::CashFlows(const std::valarray<double>& SpotValues,
    std::vector<CashFlow>& GeneratedFlows) const
{
    double mean = std::accumulate(std::begin(SpotValues), std::end(SpotValues), 1.0, std::multiplies<double>());
    mean = pow(mean, 1.0 / NumberOfTimes);

    GeneratedFlows[0].TimeIndex = 0UL;
    GeneratedFlows[0].Amount = ThePayOff(mean);

    return 1UL;
}

PathDependent* PathDependentGeometricAsian::clone() const
{
    /// <summary>
    ///  Have to clone in non abstructue child class.
    /// </summary>
    /// <returns></returns>
    return new PathDependentGeometricAsian(*this);
}

