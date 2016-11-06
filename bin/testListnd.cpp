#include "listnd.h"
#include <iostream>

int main()
{
	listnd lt(10);
	for(int i=0;i<10;i++)
	{
		lt.append(10-i);
	}
	for(int i=0;i<10;i++)
	{
		std::cout<<lt[i]<<" ";
	}
	std::cout<<std::endl;
	lt.sorted();
        for(int i=0;i<10;i++)
	{
		std::cout<<lt[i]<<" ";
	}
	std::cout<<std::endl;

	return 0;
}
