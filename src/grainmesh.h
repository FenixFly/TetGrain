#pragma once
#include "common.h"
namespace grain
{
class GrainMesh
{
public:
    GrainMesh();
    ~GrainMesh();
    int getVerticesCount();
    std::shared_ptr<std::vector<vec3d>> getVertices();
    std::shared_ptr<std::vector<char>> getVerticesLabels();
    int getTrianglesCount();
    std::shared_ptr<std::vector<vec3i>> getTriangles();
    std::shared_ptr<std::vector<char>> getTrianglesLabels();
    int getTetraCount();
    std::shared_ptr<std::vector<vec4i>> getTetra();
    std::shared_ptr<std::vector<char>> getTetraLabels();
    void setVertices(std::vector<vec3d> &newVertices);
    void setVerticesLabels(std::vector<char> &newLabels);
    void setTriangles(std::vector<vec3i> &newTriangles);
    void setTrianglesLabels(std::vector<char> &newLabels);
    void setTetra(std::vector<vec4i> &newTetra);
    void setTetraLabels(std::vector<char> &newLabels);
protected:
    std::vector<vec3d> vertices;
    std::vector<char> verticesLabels;
    std::vector<vec3i> triangles;
    std::vector<char> trianglesLabels;
    std::vector<vec4i> tetra;
    std::vector<char> tetraLabels;
};
}


