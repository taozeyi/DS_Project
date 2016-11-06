#ifndef ORCA_H
#define ORCA_H
#include "iostream"
#include "vector"
#include "math.h"
#include "algorithm"

struct Point{
	int id;
	std :: vector<float> attrs;
	float withDistance(Point& point);
};
typedef struct Point Point;

struct Neighbour{
	Point pt;
	float distance;
};

struct Outlier{
	public:
		Outlier (){};
		Outlier (Point pt);
		void print();

		Point pt;
		float score;
		std :: vector<Neighbour> neighbours;
};
typedef struct Outlier Outlier;

void k_nearestNeighbour(std::vector<Point>& dataset, Point& target_point, int k, float threshold, std::vector<Neighbour>& neighbours);
void oRca(std::vector<Point>& dataset, int k, int max_outlier_size, std::vector<Outlier>& outliers);

#endif