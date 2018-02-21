#pragma once
#include "common.h"
#include "grainmesh.h"

#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Mesh_triangulation_3.h>
#include <CGAL/Mesh_complex_3_in_triangulation_3.h>
#include <CGAL/Mesh_criteria_3.h>
#include <CGAL/Polyhedron_3.h>
#include <CGAL/boost/graph/helpers.h>
#include <CGAL/Polyhedral_mesh_domain_3.h>
#include <CGAL/make_mesh_3.h>
#include <CGAL/refine_mesh_3.h>
// Domain
typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef CGAL::Polyhedron_3<K> Polyhedron;
typedef CGAL::Polyhedral_mesh_domain_3<Polyhedron, K> Mesh_domain;
#ifndef CGAL_CONCURRENT_MESH_3
typedef CGAL::Parallel_tag Concurrency_tag;
#else
typedef CGAL::Sequential_tag Concurrency_tag;
#endif
// Triangulation
typedef CGAL::Mesh_triangulation_3<Mesh_domain, CGAL::Default, Concurrency_tag>::type Tr;
typedef CGAL::Mesh_complex_3_in_triangulation_3<Tr> C3t3;
// Criteria
typedef CGAL::Mesh_criteria_3<Tr> Mesh_criteria;
// To avoid verbose function and named parameters call
using namespace CGAL::parameters;



namespace grain
{
	class AdaptorCGAL
	{
	public:
		AdaptorCGAL();
		~AdaptorCGAL();
		int importSurface(grain::GrainMesh* gmsh);
		int setupParameters(double facet_angle, double face_size, double facet_distance, 
			double cell_radius_edge_ratio, double cell_size);
		int runMeshing();
		grain::GrainMesh* exportVolume();
		double getMeshingTime();
	private:
		//Parameters
		double _facet_angle = 30.0;
		double _facet_size = 0.15;
		double _facet_distance = 0.08;
		double _cell_radius_edge_ratio = 3.0;
		double _cell_size = 1.0;


		Polyhedron polyhedron;
		C3t3 c3t3;
	};
}