#pragma once

#include "Vanilla2.h"

double SimpleMonteCarlo3(
	const VanillaOption& TheOption,
	double Spot,
	double Vol,
	double r,
	unsigned long NumberOfPaths);
