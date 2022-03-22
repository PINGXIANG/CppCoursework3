#pragma once

#include "PayOffBridge.h"

class VanillaOption {
public:
	VanillaOption(const PayOffBridge& ThePayOff_, double Expiry_);

	double GetExpiry() const;
	double OptionPayOff(double Spot) const;

private:
	double Expiry;
	PayOffBridge ThePayOff;
};
