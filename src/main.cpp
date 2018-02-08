#include "common.h"
#include "grainmesh.h"
#include "iotetgen.h"
#include "adaptorcgal.h"

using namespace grain;

int main()
{
    GrainMesh gmsh;
	AdaptorCGAL adaptor;
	adaptor.importSurface();
	adaptor.runMeshing();
	GrainMesh * res = adaptor.exportVolume();
	saveNodeFile("tst.node", res);
	saveEleFile("tst.ele", res);



    return 0;
}
