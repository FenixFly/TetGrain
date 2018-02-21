#pragma once
#include "common.h"
#include "grainmesh.h"

namespace grain
{
    int readNodeFile(std::string filename, GrainMesh * mesh);
	int readFaceFile(std::string filename, GrainMesh *mesh);
    int readEleFile(std::string filename, GrainMesh * mesh);
    int saveNodeFile(std::string filename, GrainMesh * mesh);
	int saveFaceFile(std::string filename, GrainMesh * mesh);
    int saveEleFile(std::string filename, GrainMesh * mesh);
}

