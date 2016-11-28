#include <iostream>
#include "util.h"

int main()
{
	std::vector<float> list(10);
	list[0]=20;
	list[1]=60;
        list[2]=40;
        list[3]=80;
        list[4]=100;
        list[5]=5;
        list[6]=5;
        list[7]=220;
        list[8]=400;
        list[9]=1000;

	std::cout<<median(list.begin(),list.end())<<std::endl;
	return 0;
}
