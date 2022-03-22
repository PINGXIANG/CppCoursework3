#include <algorithm>

#include "PayOff1.h"

PayOff::PayOff(double Strike_, OptionType TheOptionType_) : Strike(Strike_), TheOptionType(TheOptionType_) {}

double PayOff::operator()(double spot) const {
	switch (TheOptionType) {
	case OptionType::call:
		return std::max(spot - Strike, 0.0);
	case OptionType::put:
		return std::max(Strike - spot, 0.0);
	default:
		throw("Unknown option type");
	}
}