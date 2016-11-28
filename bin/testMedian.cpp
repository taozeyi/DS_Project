#include <iostream>
#include "util.h"

int main()
{
	std::vector<vecnd> list;
	list.resize(15);
	for(int i=0;i<15;i++)
	{
		vecnd v(3);
		list[i]=v;
	}
	list[0][0]=20;list[0][1]=9;list[0][2]=12;
	list[1][0]=60;list[1][1]=0;list[1][2]=15;
	list[2][0]=40;list[2][1]=5;list[2][2]=26;
	list[3][0]=80;list[3][1]=8;list[3][2]=78;
	list[4][0]=100;list[4][1]=6;list[4][2]=93;
	list[5][0]=5;list[5][1]=4;list[5][2]=26;
	list[6][0]=5;list[6][1]=1;list[6][2]=84;
	list[7][0]=220;list[7][1]=3;list[7][2]=66;
	list[8][0]=400;list[8][1]=2;list[8][2]=109;
	list[9][0]=1000;list[9][1]=7;list[9][2]=25;
	list[10][0]=1000;list[10][1]=7;list[10][2]=25;
	list[11][0]=1000;list[11][1]=7;list[11][2]=25;
	list[12][0]=1000;list[12][1]=7;list[12][2]=25;
	list[13][0]=1000;list[13][1]=7;list[13][2]=25;
	list[14][0]=1000;list[14][1]=7;list[14][2]=25;

	std::cout<<median(list.begin(),list.end())<<std::endl;
	return 0;
}
