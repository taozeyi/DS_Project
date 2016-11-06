#include "orca.h"
using namespace std;

struct CompareNeighbour{
	bool operator()(Neighbour const &n_1, Neighbour const &n_2){
		return n_1.distance < n_2.distance;
	}
};

struct CompareOutlier{
	bool operator()(Outlier const &o_1, Outlier const &o_2){
		return o_1.score > o_2.score;
	}
};

float Point::withDistance(Point& point){
	float sqrt_sum = 0.0f;
	float temp;
	int attr_size = point.attrs.size();

	for(int i = 0; i<attr_size; i++){
		temp = point.attrs[i] - attrs[i];
		sqrt_sum += temp*temp;
	}
	return sqrt(sqrt_sum);
}

void Outlier::print(){
	cout << "\tOutlier - id: " << pt.id << "; score: " <<  score <<"\n";
}


void k_nearestNeighbour(std::vector<Point>& dataset, Point& target_point, int k, float threshold, std::vector<Neighbour>& neighbours){
	int size = dataset.size();
	Point temp_point;
	Neighbour temp_neighbour;
	float distance;
	int current_neighbour_size = 0;
	CompareNeighbour comparableN;
	vector<Neighbour>::iterator last_neighbor;

	//initialized neighbours size with k
	neighbours.clear();
	neighbours.reserve(k);

	for(int i = 0; i < size; i++){

		temp_point = dataset[i];
		//if current point is the target point itself, keep going
		if(temp_point.id == target_point.id) continue;
		//calculate distance of two points
		distance = target_point.withDistance(temp_point);

		if(current_neighbour_size < k){
			//if neighbours is not full, make it full by adding points
			temp_neighbour.pt = temp_point;
			temp_neighbour.distance = distance;
			neighbours.push_back(temp_neighbour);
			//sort the neighbours from short distance to long
			std::push_heap(neighbours.begin(), neighbours.end(), comparableN);
			current_neighbour_size++;
		}
		else{
			//check the new point can be a member of neighbour
			if(distance <= neighbours.front().distance){
				//remove the last neighbour (the farthest neighbour)
				std::pop_heap(neighbours.begin(), neighbours.end(), comparableN);

				last_neighbor = (--neighbours.end());
				(*last_neighbor).pt = temp_point;
				(*last_neighbor).distance = distance;

				std::push_heap(neighbours.begin(), neighbours.end(), comparableN);
			}
			//neighbors are full, the smallest neighbor is less than threshold
			if(neighbours.front().distance < threshold){
				return;
			}
		}
	}
}

void oRca(std::vector<Point>& dataset, int k, int max_outlier_size, std::vector<Outlier>& outliers){
	int size = dataset.size();
	int current_outlier_size = 0;
	Outlier candidate;
	vector<Neighbour> nearestNeighbour;
	vector<Outlier> :: iterator last_ouliter;
	CompareOutlier comparableO;
	//control parameter
	float threshold = 0.0f;
	//initialize outlier with size max_outlier_number
	outliers.clear();
	outliers.reserve(max_outlier_size);


	for(int i = 0; i < size; i++){
		candidate.pt = dataset[i];
		cout << "I am here 1"<< endl;
		k_nearestNeighbour(dataset, candidate.pt, k, threshold, nearestNeighbour);
		cout << "I am here 2"<< endl;
		//define the score of candidate is the shortest distance
		candidate.score = nearestNeighbour.front().distance;

		cout <<"the front distance" << candidate.score << endl;
		if(current_outlier_size < max_outlier_size){
			cout << "being here "<< current_outlier_size << endl;
			candidate.neighbours = nearestNeighbour;
			outliers.push_back(candidate);
			std::push_heap(outliers.begin(), outliers.end(), comparableO);
			current_outlier_size++;
		}
		else{
			if(candidate.score >= outliers.front().score){
				candidate.neighbours = nearestNeighbour;
				std::pop_heap(outliers.begin(), outliers.end(), comparableO);
				last_ouliter = (--outliers.end());
				(*last_ouliter) = candidate;
				std::push_heap(outliers.begin(), outliers.end(), comparableO);
				threshold = outliers.front().score;
			}
		}

	}

	sort(outliers.begin(), outliers.end(), comparableO);
	
}