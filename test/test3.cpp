#include "common.h"
#include "grainmesh.h"
#include "grainratio.h"
#include "iotetgen.h"
#include <iostream>

using namespace grain;

int main(int argc, char** argv)
{
	grain::GrainMesh mesh;
	if (argc > 2)
	{
		std::cout << argv[0] << "\n";
		std::cout << argv[1] << "\n";
		std::cout << argv[2] << "\n";

		readNodeFile(argv[1], &mesh);
		readEleFile(argv[2], &mesh);
	}
	else
	{
		std::cout << "Choose node and element files to test ratio \n";
		return 1;
	}

	grain::GrainRatio ratio = grain::GrainRatio(&mesh);
    ratio.calcRatio(0);
	std::vector<double>* ratiosVec = ratio.getRatios();

	std::cout << "Grain quality \n";
	for (int i = 0; i < ratiosVec->size(); i++)
	{
		std::cout << "Tetra " << i
			<< " edge ratio " << ratiosVec->at(i) << "\n";
	}

	return 0;
}