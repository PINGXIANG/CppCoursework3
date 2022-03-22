#pragma once

class PayOff {
public:
	enum class OptionType {call, put};
	PayOff(double Strike_, OptionType TheOptionType_);
	double operator()(double Spot) const;

private:
	double Strike;
	OptionType TheOptionType;
};
