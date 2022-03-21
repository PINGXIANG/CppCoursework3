#pragma once

#include <valarray>

class RandomBase {
public:
	RandomBase(unsigned long Dimensionality);

	inline size_t GetDimensionality() const;

	virtual RandomBase* clone() const = 0;
	virtual void GetUniforms(std::valarray<double>& variates) = 0;
	virtual void Skip(unsigned long numberOfPaths) = 0;
	virtual void SetSeed(unsigned long Seed) = 0;
	virtual void Reset() = 0;

	virtual void GetGaussians(std::valarray<double>& variates);
	virtual void ResetDimensionality(size_t NewDimensionality);

private:
	size_t Dimensionality;
};

size_t RandomBase::GetDimensionality() const {
	return Dimensionality;
}
