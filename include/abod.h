#ifndef _ABOD_H
#define _ABOD_H

#include <vector>

#include "vecnd.h"
#include "listnd.h"

std::vector<vecnd::value_type> fastVOA(std::vector<vecnd> dataset,
		int t, int s1,int s2);

std::vector<listnd> randomProjection(std::vector<vecnd> dataset,
		int t);

vecnd firstMomentEstimator(std::vector<listnd> listset,
		int t,long long n);

vecnd frobeniusNorm(std::vector<listnd> listset,
		int t,long long n);
#endif
