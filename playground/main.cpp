#include <iostream>
#include <vector>
#include <algorithm>
#include <stdint.h>
#include <unistd.h>
#include <fstream>
#include <sstream>
#include <string>
#include <climits>

#include "orca.h"
using namespace std;

bool flag_generation = false;
long long selected_number_of_points = 10000;
int selected_dimension_of_points = 10;
int k_nearestNeighbor = 5;
int max_ouliter_number = 10;
char* file_path = "kddcup_1.5M_znorm.csv";

void usage(){

}
void GaussianMixture(){

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
				selected_dimension_of_points = atoi(optarg);
				flag_d = true;
				break;
			case 'k':
			//k nearest neighbour
				k_nearestNeighbor = atoi(optarg);
				flag_k = true;
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
			cerr << "Number of expected data point dimension not set. Using default d = " << selected_dimension_of_points <<endl;
	}
	else{
		if(!flag_r)
			cerr << "No input file path found" <<endl;
			exit(1);
	}
}

bool readDataFromDisk(char* fileName, std::vector<Point>& dataset, long long& desired_point_size, int& desired_dimensions){
	
	int attr_size = 0;
	long long point_size = 0;
	int current_point_id = 0;
	int current_attr_position;
	bool read;
	Point point;

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
	point.attrs.resize(desired_dimensions);

	while(std::getline(input_file, line) && current_point_id < desired_point_size){

		std::istringstream iss(line);
		point.id = current_point_id;
		for(current_attr_position = 0; current_attr_position < desired_dimensions; current_attr_position++){

			read = iss >> point.attrs[current_attr_position];
			/*if(!read){
				//cout << "I should not in here" << endl;
				cerr << "File " << fileName<< " is corrupted." <<endl;
				exit(1);
			}*/
		}

		dataset[current_point_id] = point;
		current_point_id++;
	}

}

int main (int argc, char** argv){
	std::vector<Point> dataset;
	std::vector<Outlier> outliers;
	//initialization(argc, argv);
	if(flag_generation){
		GaussianMixture();
	}
	else{
		readDataFromDisk(file_path, dataset, selected_number_of_points, selected_dimension_of_points);

		oRca(dataset, k_nearestNeighbor, max_ouliter_number, outliers);

	}

	cout << "Number of Outliers:" << outliers.size() << endl;
	for (int i = 0; i < outliers.size (); i++){
		outliers [i].print ();
	}
}