#include <vector>
#include "abod.h"

vecnd abod::firstMomentEstimator(std::vector<listnd> listset, int t, size_t n){
	vecnd firstMoment(n);
	for(int i = 0; i<t; i++){
		vecnd c_left(n);
		vecnd c_right(n);
		listnd l = listset[i];
		for(size_t j = 0; j < n, j++){
			size_t idx = l[j].pointID();
			c_left[idx] = j-1;
			c_right[idx] = n-1-c_left[idx];
		}
		for(size_t k = 0; k <n; k++){
			firstMoment[k] = firstMoment[k] + c_left[k]*c_right[k];
		}
	}
	return firstMoment*(2*m_pi)/(t*(n-1)*(n-2));
}