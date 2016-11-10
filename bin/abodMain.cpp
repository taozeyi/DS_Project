#include <iostream>
#include <vector>
#include <algorithm>

#include <fstream>
#include <sstream>
#include <string>
#include <climits>

#include "abod.h"
#include "vecnd.h"
#include "listnd.h"
#include "util.h"


using namespace std;

bool flag_generation =									false;
int selected_number_of_points =						1000;
int selected_dimension_of_point =						10;
int max_ouliter_number =								10;
char* file_path =										NULL;
char* test_file = "../data/kddcup_1.5M_znorm.csv";

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

/**
  *
  *
  */

void readDataFromDisk(char* fileName, std::vector<vecnd>& dataset, int desired_point_size, int desired_dimensions){
	
	int attr_size = 0;
	int point_size = 0;
	int current_point_id = 0;
	int current_attr_position = 0;


	ifstream input_file(fileName);

	std::string line;

	if(!getline(input_file, line)){
		cerr << "Unable to read input file: " << fileName << endl;
		exit(1);
	}
	else{
		std::istringstream iss(line);
		if(!(iss >> point_size >> attr_size)){
			cerr << "Invalid Header format" << endl;
		}
	}

	dataset.resize(desired_point_size);


	while(std::getline(input_file, line) && current_point_id < desired_point_size){

		std::istringstream iss(line);
		//std::cout<<line<<endl;
		//vecnd temp(1);
		dataset[current_point_id]=std::move(vecnd(desired_dimensions));

		for(current_attr_position = 0; current_attr_position < desired_dimensions; current_attr_position++){
			//std::cout<<"true!"<<std::endl;
			iss >> dataset[current_point_id][current_attr_position];
			//std::cout<<"true!"<<std::endl;
			//std::cout<< temp[current_attr_position]<< " "<<std::endl;
			//temp[1] = 1.0f;
			//temp[2] = 2.0f;
			/*if(!iss&&!iss.eof()){
				//cout << "I should not in here" << endl;
				cerr << "File " << fileName<< " is corrupted." <<endl;
				exit(1);
			}*/
		}
		//std::cout<<"fuck!"<<std::endl;

		std::cout<<"data set size now"<<dataset.size()<<std::endl;
		//std::cout<<"vecnd size is "<< temp._size<<std::endl;
		std::cout<<dataset[0]<<std::endl;
		//std::cout<<temp<<std::endl;
		std::cout<<"insert point numb"<<current_point_id<<std::endl;
		//dataset[current_point_id] = std::move(temp);


		//dataset.push_back(std::move(temp));
		//dataset.emplace_back(temp);

		current_point_id++;
		std::cout<<"insert point numb"<<current_point_id<<std::endl;
	}

}  


int main (int argc, char** argv){
	//initialization(argc, argv);
	std::vector<vecnd> dataset;

	vecnd var;
	if(flag_generation){
		GaussianMixtureGenerator();
	}
	else{
		readDataFromDisk(test_file, dataset, selected_number_of_points, selected_dimension_of_point);
		//var = fastVOA(dataset, 10, 10, 10);
	}
	std::cout << var;
}