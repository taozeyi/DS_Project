#include "abod.h"

vecnd frobeniusNorm(std::vector<listnd> listset, int t, size_t n){
	vecnd frobeniusNorm(n);
	for(int i = 0; i < t; i++){
		vecnd ams_left(n);
		vecnd ams_right(n);
		listnd l = listset[i];
		for(size_t j =1; j < n; j++){
			size_t idx_1 = l[j].pointId();
			size_t idx_2 = l[j -1].pointId();
			ams_left[idx_1] = ams_left[idx_2] + ams_left[idx_2];
		}
		for(size_t j =n-1; j > 1; j--){
			size_t idx_1 = l[j].pointId();
			size_t idx_2 = l[j +1].pointId();
			ams_right[idx_1] = ams_right[idx_2] + ams_right[idx_2];
		}
		for(size_t k = 0; k < n; k++){
			frobeniusNorm[k] = frobeniusNorm[k] + ams_left[k]*ams_right[k];
		}
	}

	return frobeniusNorm;
}