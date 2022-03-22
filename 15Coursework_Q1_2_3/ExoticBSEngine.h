#pragma once

#include <valarray>

#include "ExoticEngine.h"
#include "Random2.h"

class ExoticBSEngine : public ExoticEngine
{
public:
    ExoticBSEngine(const Wrapper<PathDependent>& TheProduct_,
        const Parameters& R_,
        const Parameters& D_,
        const Parameters& Vol_,
        const Wrapper<RandomBase>& TheGenerator_,
        double Spot_);

    virtual void GetOnePath(std::valarray<double>& SpotValues);
    virtual ~ExoticBSEngine() {}

private:
    Wrapper<RandomBase> TheGenerator;
    std::valarray<double> Drifts;
    std::valarray<double> StandardDeviations;
    double LogSpot;
    unsigned long NumberOfTimes;
    std::valarray<double> Variates;
};
