#include <cstdlib>
#include <valarray>

#include "Random2.h"
#include "Normals.h"

using namespace std;

void RandomBase::GetGaussians(std::valarray<double>& variates) {
	GetUniforms(variates);

	for (unsigned long i = 0; i < Dimensionality; i++) {
		double x = variates[i];
		variates[i] = InverseCumulativeNormal(x);
	}
}

void RandomBase::ResetDimensionality(unsigned long NewDimensionality) {
	Dimensionality = NewDimensionality;
}

RandomBase::RandomBase(unsigned long Dimensionality_) : Dimensionality{ Dimensionality_ } {
}