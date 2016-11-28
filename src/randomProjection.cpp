#include <iostream>
#include <vector>
#include <memory>
#include <algorithm> 

#include "abod.h"
#include "listnd.h"
#include "vecnd.h"
#include "util.h"

std::vector<listnd> randomProjection(std::vector<vecnd>& dataset, int t)
{
	std::vector<listnd> L;
	size_t n=dataset[0].size();

	for(int i=0;i<t;i++)
	{
		vecnd normal=randomVector(n,0.0f,1.0f);

		normal.normalize();
		
		listnd lt(dataset.size());

		for(size_t j=0;j<dataset.size();j++)
		{
			lt[j]=item(j,dataset[j].dot(normal));
		}
		lt.sorted();
		L.push_back(lt);
	}

	return L;
}

