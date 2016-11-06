#include <vector>
#include "abod.h"

vecnd abod::fastVOA(std::vector<vecnd> dataset, int t, int s1,int s2){

	size_t data_szie = dataset.size();

	std::vector<listnd> listOfRandomProjection = randomProjection(dataset, t);

	vecnd firstMomentEst = firstMomentEstimator(listOfRandomProjection, t, data_szie);

	vecnd medianFrobNormal(data_szie);

	vecnd varience(data_szie);

	std::vector<vecnd> yVector;

	y.reserve(s2);

	for(int i = 0, i < s2; i++){
		yVector[i] = squaredSumOfFrobNorm (listOfRandomProjection, t, data_szie, s1);
	}



}

vecnd abod::squaredSumOfFrobNorm(std::vector<listnd> listset, int t, size_t n, int s1){
	for(int i = 0, i < s1, i++){
		vecnd temp = frobeniusNorm(listset, t, n);
		square += temp.square();
	}
	return (square/s1);
}