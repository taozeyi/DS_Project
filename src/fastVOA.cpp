#include <vector>
#include <math.h>
#include "abod.h"


/**
  * The fastVOA implementation
  * @para dataset input data set high dimension space N x M, N > 10^6
  * @para t
  * @para s1
  * @para s2
  * @return 
  */

vecnd fastVOA(std::vector<vecnd>& dataset, int t, int s1,int s2){

	size_t data_size = dataset.size();
	
	std::cout << "fastVOA handle the dataset size of "<< data_size<<std::endl; 

	std::vector<listnd> listOfRandomProjection = randomProjection(dataset, t);

	std::cout << "list of Random Projection finished" << std::endl;

	vecnd firstMomentEst = firstMomentEstimator(listOfRandomProjection, t, data_size);

	vecnd medianFrobNormal(data_size);

	vecnd varience(data_size);

	std::vector<vecnd> yVector;

	yVector.reserve(s2);

	for(int i = 0; i < s2; i++){
		yVector[i] = squaredSumOfFrobNorm (listOfRandomProjection, t, data_size, s1);
	}

	vecnd secondMomentEst = vectorMedian(yVector);

	for(size_t j = 0; j<data_size; j++){

		vecnd::value_type para_1 = (4*M_PI*M_PI)/(t*(t-1)*(data_size-1)*(data_size-2));

		vecnd::value_type para_2 = (2*M_PI)/(t-1);

		secondMomentEst[j] = secondMomentEst[j] * para_1 - firstMomentEst[j] *para_2;

		varience[j] = secondMomentEst[j] - firstMomentEst[j]*firstMomentEst[j];
	}

	return varience;
}
/**
  * Helper function
  *
  */

vecnd squaredSumOfFrobNorm(std::vector<listnd> listset, int t, size_t n, int s1){
	vecnd square(n);
	for(int i = 0; i < s1; i++){
		vecnd temp = frobeniusNorm(listset, t, n);
		square += temp.square();
	}
	return (square/s1);
}
/**
  * This method is taking the median value of a vector list,
  * Many idea can be done here, based on how you define the 
  * "median of vectors"
  * @para vectorset the input vector set
  * @return the vecnd the median value 
  */

vecnd vectorMedian(std::vector<vecnd> vectorset){
	return vectorset[0];
}