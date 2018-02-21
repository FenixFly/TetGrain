#include "common.h"
#include "grainmesh.h"
#include "iotetgen.h"

using grain::GrainMesh;

int main(int argc, char** argv)
{
	GrainMesh gmsh;
	gmsh.makeStubTetra();

    return 0;
}