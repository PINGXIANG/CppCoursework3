#pragma once

#include "Vanilla3.h"

double SimpleMonteCarlo4(
	const VanillaOption& TheOption,
	double Spot,
	double Vol,
	double r,
	unsigned long NumberOfPaths);
