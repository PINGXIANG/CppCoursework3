#include <valarray>

#include "PathDependent.h"

PathDependent::PathDependent(const std::valarray<double>& LookAtTimes_)
	: LookAtTimes(LookAtTimes_)
{}

const std::valarray<double>& PathDependent::GetLookAtTimes() const {
	return LookAtTimes;
}