#include "common.h"
#include "grainmesh.h"

using grain::GrainMesh;

int main(int argc, char** argv)
{
	GrainMesh gmsh;
	
	// Geerate stub tetrahedron 
	gmsh.makeStubTetra();

	// Check number of vertices and facets in tetrahedron
	if (gmsh.getVerticesCount() != 4)
		return 1;
	if (gmsh.getTrianglesCount() != 4)
		return 2;

    return 0;
}