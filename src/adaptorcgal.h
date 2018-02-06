#pragma once
#include <CGAL/config.h>
#include <CGAL/Cartesian.h>
#include <CGAL/Point_2.h>
#include <CGAL/Triangle_2.h>
#include <CGAL/Segment_3.h>

namespace grain
{
	class AdaptorCGAL
	{
	public:
		AdaptorCGAL();
		~AdaptorCGAL();
		int importSurface();
		int setupParameters();
		int runMeshing();
		int exportVolume();
		double getMeshingTime();
	private:

	};
}