#ifndef _ABOD_H
#define _ABOD_H

#include <vector>

#include "vecnd.h"
#include "listnd.h"

vecnd fastVOA(std::vector<vecnd> dataset, int t, int s1,int s2);

vecnd vectorMedian(std::vector<vecnd> vectorset); 

vecnd squaredSumOfFrobNorm(std::vector<listnd> listset, int t, size_t n, int s1);

std::vector<listnd> randomProjection(std::vector<vecnd> dataset, int t);

vecnd firstMomentEstimator(std::vector<listnd> listset, int t, size_t n);

vecnd frobeniusNorm(std::vector<listnd> listset, int t, size_t n);

vecnd pointWiseIndependentVector(size_t n);
#endif
