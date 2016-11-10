#include "listnd.h"
#include "vecnd.h"
#include <iostream>

int main()
{
	vecnd v(3);
	v[0]=1;v[1]=2;v[2]=3;
	std::cout<<v<<std::endl;
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
