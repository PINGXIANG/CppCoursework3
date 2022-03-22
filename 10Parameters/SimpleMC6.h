#pragma once

#include "Vanilla3.h"
#include "Parameters.h"

double SimpleMonteCarlo5(
	const VanillaOption& TheOption,
	double Spot,
	const Parameters& Vol,
	const Parameters& r,
	unsigned long NumberOfPaths);
