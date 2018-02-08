#include "iotetgen.h"
#include <fstream>

int grain::readNodeFile(std::string filename, GrainMesh * mesh)
{
    std::ifstream fin(filename, std::ifstream::in);
    int pCount = 0;
    int trash = 0;
    fin >> pCount;
    fin >> trash;
    fin >> trash;
    fin >> trash;
    fin >> trash;
    std::vector<vec3d> newPoints(pCount);
    std::vector<char> newPLabels(pCount);
    for (int i = 0; i < pCount; i++)
    {
        fin >> trash
                >> newPoints[i].x
                >> newPoints[i].y
                >> newPoints[i].z
                >> newPLabels[i];
    }
    fin.close();
    mesh->setVertices(newPoints);
    mesh->setVerticesLabels(newPLabels);
    return 0;
}

int grain::readEleFile(std::string filename, GrainMesh *mesh)
{
    std::ifstream fin(filename, std::ifstream::in);
    int tCount = 0;
    int trash = 0;
    fin >> tCount;
    fin >> trash;
    fin >> trash;
    std::vector<vec4i> newTetra(tCount);
    std::vector<char> newTLabels(tCount);
    for (int i = 0; i < tCount; i++)
    {
        fin >> trash
                >> newTetra[i].x
                >> newTetra[i].y
                >> newTetra[i].z
                >> newTetra[i].w
                >> newTLabels[i];
    }
    fin.close();
    mesh->setTetra(newTetra);
    mesh->setTetraLabels(newTLabels);
    return 0;
}

int grain::saveNodeFile(std::string filename, GrainMesh *mesh)
{
    int mPointsCount = mesh->getVerticesCount();
    std::vector<vec3d>* mPoints = mesh->getVertices();
	std::vector<char>* mPointsLabels = mesh->getVerticesLabels();
    std::ofstream fout(filename);
    fout << mPointsCount <<  " " << 3 << " " << 0 << " " << 0 << " " << 0 << "\n";
    for (int i = 0; i < mPointsCount; i++)
    {
        fout << i << " "
             << mPoints->at(i).x << " "
             << mPoints->at(i).y << " "
             << mPoints->at(i).z << " "
             << (int) mPointsLabels->at(i) << "\n";
    }
    fout.close();
    return 0;
}

int grain::saveFaceFile(std::string filename, GrainMesh * mesh)
{
	int mTrianglesCount = mesh->getTrianglesCount();
	std::vector<vec3i>* mTriangles = mesh->getTriangles();
	std::vector<char>* mTrianglesLabels = mesh->getTrianglesLabels();
	std::ofstream fout(filename);
	fout << mTrianglesCount << " " << 1 << "\n";
	for (int i = 0; i < mTrianglesCount; i++)
	{
		fout << i << " "
			<< mTriangles->at(i).x << " "
			<< mTriangles->at(i).y << " "
			<< mTriangles->at(i).z << " "
			<< (int) mTrianglesLabels->at(i) << "\n";
	}
	fout.close();

	return 0;
}

int grain::saveEleFile(std::string filename, GrainMesh *mesh)
{
    int mTetraCount = mesh->getTetraCount();
	std::vector<vec4i>* mTetra = mesh->getTetra();
	std::vector<char>* mTetraLabels = mesh->getTetraLabels();
    std::ofstream fout(filename);
    fout << mTetraCount << " " << 4 << " " << 1 << "\n";
    fout.flush();
    for (int i = 0; i < mTetraCount; i++)
    {
        fout << i << " "
              << mTetra->at(i).x << " "
              << mTetra->at(i).y << " "
              << mTetra->at(i).z << " "
              << mTetra->at(i).w << " "
              << (int) mTetraLabels->at(i) << "\n";
    }
    fout.close();
    return 0;
}
