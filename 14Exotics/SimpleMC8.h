#pragma once

#include "Vanilla3.h"
#include "Parameters.h"
#include "Random2.h"
#include "StatisticsMC.h"

void SimpleMonteCarlo6(
	const VanillaOption& TheOption,
	double Spot,
	const Parameters& Vol,
	const Parameters& r,
	unsigned long NumberOfPaths,
	StatisticsMC& gatherer,
	RandomBase& generator);
