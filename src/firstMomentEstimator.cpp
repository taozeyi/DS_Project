#include <vector>
#include "abod.h"
#include "vecnd.h"

vecnd firstMomentEstimator(std::vector<listnd>& listset, int t, size_t n){
	vecnd firstMoment(n);
	std::cout <<"the size of firstMoment "<< firstMoment.size()<<std::endl;
	for(int i = 0; i<t; i++){
		vecnd c_left(n);
		vecnd c_right(n);
		listnd l = listset[i];
		for(size_t j = 0; j < n; j++){
			size_t idx = l[j].pointId();
			c_left[idx] = j-1;
			c_right[idx] = n-1-c_left[idx];
		}
		for(size_t k = 0; k <n; k++){
			firstMoment[k] = firstMoment[k] + c_left[k]*c_right[k];
		}
	}
	vecnd::value_type temp = (2*M_PI)/(t*(n-1)*(n-2));
	return firstMoment*temp;
}