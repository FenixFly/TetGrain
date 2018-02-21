/**
* @file   test2.cpp
* @brief  Test reading node and face files
*/

#include "common.h"
#include "grainmesh.h"
#include "iotetgen.h"
#include <iostream>

using namespace grain;

int main(int argc, char** argv)
{
	GrainMesh mesh;

	if (argc > 2)
	{
		readNodeFile(argv[1], &mesh);
		readFaceFile(argv[2], &mesh);
	}
	else
	{
	}
	std::cout << "Number of points in model: " << mesh.getVerticesCount() << "\n";
	std::cout << "Number of facets in surface: " << mesh.getTrianglesCount() << "\n";

	return 0;
}