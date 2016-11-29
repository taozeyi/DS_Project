#include <cmath>
#include "abod.h"

vecnd bruteForceMOA2(std::vector<listnd>& listset,int t,size_t n)
{
	vecnd MOA2(n);
	for(int i=0;i<t;i++)
	{
		vecnd c_left(n);
		vecnd c_right(n);
		listnd l=listset[i];
		for(int i = 0; i<t; i++)
		{
			vecnd c_left(n);
			vecnd c_right(n);
			listnd l = listset[i];
			for(size_t j = 0; j < n; j++){
				size_t idx = l[j].pointId();
				c_left[idx] = j-1;
				c_right[idx] = n-1-c_left[idx];
		}
		for(size_t k = 0; k <n; k++)
		{
			MOA2[k] = MOA2[k] + pow(c_left[k]*c_right[k],2);
		}
	}
	vecnd::value_type temp = M_PI/(t*(n-1)*(n-2));
	return MOA2*temp;
	}
}
