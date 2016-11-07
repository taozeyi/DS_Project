#include <iostream>
#include <vector>
#include <algorithm>

#include "abod.h"
#include "vecnd.h"
#include "listnd.h"
#include "util.h"


using namespace std;

bool flag_generation =									false;
size_t selected_number_of_points =						10000;
int selected_dimension_of_point =						10;
int max_ouliter_number =								10;
char* file_path =										NULL;

void usage(){

	cerr << "Usage:\n" 
		<< "\tflag -g: Gaussian Randomly generated points for limited computational resources\n"
		<< "\t\t-m: Number of reference points to be generated\n"
		<< "\t\t-d: Number of dimensions of each point\n"
		<< "\tno flag: Loads data from filesystem\n"
		<< "\t\t-m: Number of reference points to be used in given dataset"
		<< "\t\t-d: Number of dimensions of each point, no larger than max entries numbers\n"
		<< "\t\t-r: file path\n";
	exit(1);

}

void GaussianMixtureGenerator(){

}
//parse command line arguements, modified anytime
void initialization(int argc, char** argv){
	char c;
	bool flag_n, flag_d, flag_k, flag_o, flag_r = false;
	while((c = getopt(argc, argv, "g: n: d: k: o: r:"))!= -1){
		switch(c){
			case 'g':
			//selective generation method for limited computation ability
				flag_generation = true;
				break;
			case 'n':
			//number of data picked from dataset
				selected_number_of_points = atoi(optarg);
				flag_n = true;
				break;
			case 'd':
			//selected dimension 
				selected_dimension_of_point = atoi(optarg);
				flag_d = true;
				break;
			case 'o':
			//number of outlier
				max_ouliter_number = atoi(optarg);
				flag_o = true;
				break;
			case 'r':
			//file reading path
				file_path = optarg;
				flag_r = true;
				break;
			case '?':
				if(optopt == 'n' || optopt == 'd' || optopt =='r'){
					cerr << "Flag -"<<(char)optopt << " requires an arguements.\n";
				}
				else if(isprint(optopt))
					cerr << "Unknown Flag: "<<(char)optopt <<".\n";
				else
					cerr << "Unknown Flag  " <<endl;
					usage();
			default:
				abort();
		}
	}
	if(flag_generation){
		if(!flag_n)
			cerr << "Number of expected data point not set. Using default n = " <<selected_number_of_points <<endl;
		if(!flag_d)
			cerr << "Number of expected data point dimension not set. Using default d = " << selected_dimension_of_point <<endl;
	}
	else{
		if(!flag_r)
			cerr << "No input file path found" <<endl;
			exit(1);
	}
}


int main (int argc, char** argv){
	initialization(argc, argv);
	if(flag_generation){
		GaussianMixtureGenerator();
	}
	else{


	}
}