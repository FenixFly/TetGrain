#include "grainratio.h"
#include <math.h>
#include <fstream>

inline double dist(double x1, double y1, double z1, double x2, double y2, double z2)
{
	return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2) + (z1 - z2)*(z1 - z2));
}

double grain::GrainRatio::calcEdgeRatio(
	const vec3d point1, const vec3d point2, 
	const vec3d point3, const vec3d point4)
{
	double max = 0.0;
	double min = INFINITY;

	double len1 = dist(
		point1.x, point1.y, point1.z,
		point2.x, point2.y, point2.z);

	if (len1 > max)
		max = len1;
	if (len1 < min)
		min = len1;

	double len2 = dist(
		point1.x, point1.y, point1.z,
		point3.x, point3.y, point3.z);

	if (len2 > max)
		max = len2;
	if (len2 < min)
		min = len2;

	double len3 = dist(
		point1.x, point1.y, point1.z,
		point4.x, point4.y, point4.z);

	if (len3 > max)
		max = len3;
	if (len3 < min)
		min = len3;

	double len4 = dist(
		point2.x, point2.y, point2.z,
		point3.x, point3.y, point3.z);

	if (len4 > max)
		max = len4;
	if (len4 < min)
		min = len4;

	double len5 = dist(
		point2.x, point2.y, point2.z,
		point4.x, point4.y, point4.z);

	if (len5 > max)
		max = len5;
	if (len5 < min)
		min = len5;

	double len6 = dist(
		point3.x, point3.y, point3.z,
		point4.x, point4.y, point4.z);

	if (len6 > max)
		max = len6;
	if (len6 < min)
		min = len6;

	return max / min;
}

grain::GrainRatio::GrainRatio(grain::GrainMesh * mesh)
{
	ratios = new std::vector<double>();
	this->mesh = mesh;
}

std::vector<double>* grain::GrainRatio::getRatios()
{
	return ratios;
}

void grain::GrainRatio::calcRatio(int type)
{
	int ratioSize = mesh->getTetraCount();

	ratios->clear();
	ratios = new std::vector<double>();
	ratios->reserve(ratioSize);

	std::vector<vec4i>* tetra = mesh->getTetra();
	std::vector<vec3d>* v = mesh->getVertices();

	for (int i = 0; i < ratioSize; i++)
	{
		int vert1 = tetra->at(i).x;
		int vert2 = tetra->at(i).y;
		int vert3 = tetra->at(i).z;
		int vert4 = tetra->at(i).w;

		double ratio = 0.0;
		if (type == 0)
			ratio = calcEdgeRatio(v->at(vert1), v->at(vert2), v->at(vert3), v->at(vert4));
		
		ratios->push_back(ratio);
	}
}
