#include <ctime>
#include <cstdlib>
#include "abod.h"

vecnd frobeniusNorm(std::vector<listnd>& listset, int t, size_t n){
	vecnd frobeniusNorm(n);
	vecnd s_left = pointWiseIndependentVector(n);
	//std::cout << s_left << std::endl;
	vecnd s_right = pointWiseIndependentVector(n);

	for (size_t i = 0; i < n; i++)
	{
		frobeniusNorm[i] = 0;
	}
	//std::cout << frobeniusNorm <<std::endl;

	for(int i = 0; i < t; i++){

		vecnd ams_left(n);
		for (size_t i = 0; i < n; i++)
		{
		ams_left[i] = 0;
		}
		//std::cout << s_left<<std::endl;
		vecnd ams_right(n);
		for (size_t i = 0; i < n; i++)
		{
		ams_right[i] = 0;
		}

		listnd l = listset[i];
		//std::cout << "listnd size " << l.size() << std::endl;
		for(size_t j = 1; j < n; j++){
			size_t idx_1 = l[j].pointId();
			//std::cout << "index number: " << idx_1 << std::endl;
			size_t idx_2 = l[j -1].pointId();
			ams_left[idx_1] = ams_left[idx_2] + s_left[idx_2];
		}
		for(size_t j =n-1; j >= 1; j--){
			size_t idx_1 = l[j-1].pointId();
			size_t idx_2 = l[j].pointId();
			ams_right[idx_1] = ams_right[idx_2] + s_right[idx_2];
			//std::cout << "ams is " << ams_right[idx_1] << "s_right is " << s_right[idx_2]<< std::endl;
		}
		for(size_t k = 0; k < n; k++){
			frobeniusNorm[k] = frobeniusNorm[k] + ams_left[k]*ams_right[k];
			//std::cout <<" How Many time been here" << ams_left[k]*ams_right[k] << std::endl;
		}
		
	}
	//std::cout << frobeniusNorm <<std::endl;
	return frobeniusNorm;
}

vecnd pointWiseIndependentVector(size_t n){

	int k = 4;
	int m = 2;
	vecnd kWiseHash(n);

	std::srand(std::time(0));

	for(int i = 0; i < n; i++){

		vecnd coefficient(k);
  		vecnd seedX(n);
  	
    	//std::srand(std::time(0));
  		for(int i = 0; i < k; i++){
  		
  			coefficient[i] = rand()%100;
  			//std::cout << coefficient[i] << std::endl; 
  		}

  		for(int i = 0; i < n; i++){
  			//std::srand(std::time(0));
  			seedX[i] = rand()%100;
  			//std::cout << seedX[i] << std::endl; 
  			//std::cout << "0" << std::endl; 
  		}

		int tempSum = 0;

  		for(int j = 0; j < k; j++){
  			//std::cout <<"The co" <<coefficient[j]<< std::endl;
		    //std::cout <<"The seed"<<seedX[i] << std::endl; 
  			tempSum += coefficient[j]*pow(seedX[i], j);
  		    //std::cout <<"The sum"<< tempSum << std::endl; 
  		}

  		kWiseHash[i] = tempSum % MAX_PRIME % m;
  		//std::cout << tempSum << std::endl; 	
  	}
  	return kWiseHash;
}