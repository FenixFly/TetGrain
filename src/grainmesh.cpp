#include "grainmesh.h"

grain::GrainMesh::GrainMesh()
{

}

grain::GrainMesh::~GrainMesh()
{

}

int grain::GrainMesh::getVerticesCount()
{
    return vertices.size();
}

std::shared_ptr<std::vector<vec3d>> grain::GrainMesh::getVertices()
{
    return std::shared_ptr<std::vector<vec3d>>(&vertices);
}

std::shared_ptr<std::vector<char>> grain::GrainMesh::getVerticesLabels()
{
    return std::shared_ptr<std::vector<char>>(&verticesLabels);
}

int grain::GrainMesh::getTrianglesCount()
{
    return triangles.size();
}

std::shared_ptr<std::vector<vec3i>> grain::GrainMesh::getTriangles()
{
    return std::shared_ptr<std::vector<vec3i>>(&triangles);
}

std::shared_ptr<std::vector<char>> grain::GrainMesh::getTrianglesLabels()
{
    return std::shared_ptr<std::vector<char>>(&trianglesLabels);
}

int grain::GrainMesh::getTetraCount()
{
    return tetra.size();
}

std::shared_ptr<std::vector<vec4i>> grain::GrainMesh::getTetra()
{
    return std::shared_ptr<std::vector<vec4i>>(&tetra);
}

std::shared_ptr<std::vector<char>> grain::GrainMesh::getTetraLabels()
{
    return std::shared_ptr<std::vector<char>>(&tetraLabels);
}

void grain::GrainMesh::setVertices(std::vector<vec3d> &newVertices)
{
    vertices.clear();
    vertices = newVertices;
}

void grain::GrainMesh::setVerticesLabels(std::vector<char> &newLabels)
{
    verticesLabels.clear();
    verticesLabels = newLabels;
}

void grain::GrainMesh::setTriangles(std::vector<vec3i> &newTriangles)
{
    triangles.clear();
    triangles = newTriangles;
}

void grain::GrainMesh::setTrianglesLabels(std::vector<char> &newLabels)
{
    trianglesLabels.clear();
    trianglesLabels = newLabels;
}

void grain::GrainMesh::setTetra(std::vector<vec4i> &newTetra)
{
    tetra.clear();
    tetra = newTetra;
}

void grain::GrainMesh::setTetraLabels(std::vector<char> &newLabels)
{
    tetraLabels.clear();
    tetraLabels = newLabels;
}
