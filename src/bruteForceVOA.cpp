#include "abod.h"

vecnd bruteForceVOA(std::vector<vecnd>& dataset, int t)
{
	size_t data_size = dataset.size();
	
	std::cout << "bruteForceVOA handle the dataset size of "<< data_size<<std::endl; 

	std::vector<listnd> listOfRandomProjection = randomProjection(dataset, t);

	std::cout << "list of Random Projection finished" << std::endl;

	vecnd firstMomentEst = firstMomentEstimator(listOfRandomProjection, t, data_size);

	std::cout << "firstMomentEstimator finished" << std::endl;

	vecnd secondMomentEst = bruteForceMOA2(listOfRandomProjection, t, data_size);
	
	std::cout << "Brute force second moment estimation  finished" << std::endl;

	vecnd varience(data_size);


	for(size_t j = 0; j<data_size; j++){

		varience[j] = secondMomentEst[j] - firstMomentEst[j]*firstMomentEst[j];
	}

	return varience;
}