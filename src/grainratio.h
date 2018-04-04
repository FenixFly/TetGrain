#pragma once
#include <vector>
#include "grainmesh.h"

namespace grain
{
	class GrainRatio
	{
	private:
		grain::GrainMesh * mesh;
		std::vector<double>* ratios;
		double calcEdgeRatio(
			const vec3d point1, const vec3d point2,
			const vec3d point3, const vec3d point4);

	public:
		GrainRatio(grain::GrainMesh * mesh);
		std::vector<double>* getRatios();
		void calcRatio(int type = 0);
	};

}
