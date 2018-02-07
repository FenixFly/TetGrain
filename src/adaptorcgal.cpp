#include "adaptorcgal.h"

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



grain::AdaptorCGAL::AdaptorCGAL()
{
}

grain::AdaptorCGAL::~AdaptorCGAL()
{
}

int grain::AdaptorCGAL::importSurface()
{
	//Read image
	//if (!image.read(fname)) {
	//	std::cerr << "Error: Cannot read file " << fname << std::endl;
	//	return EXIT_FAILURE;
	//}
	return 0;
}

int grain::AdaptorCGAL::setupParameters()
{
	return 0;
}

int grain::AdaptorCGAL::runMeshing()
{
	
	const char* fname = "E:/data/elephant.off";
	// Create input polyhedron
	Polyhedron polyhedron;
	std::ifstream input(fname);
	input >> polyhedron;
	if (input.fail()) {
		std::cerr << "Error: Cannot read file " << fname << std::endl;
		return EXIT_FAILURE;
	}
	input.close();

	if (!CGAL::is_triangle_mesh(polyhedron)) {
		std::cerr << "Input geometry is not triangulated." << std::endl;
		return EXIT_FAILURE;
	}
	// Create domain
	Mesh_domain domain(polyhedron);

	// Mesh criteria (no cell_size set)
	Mesh_criteria criteria(facet_angle = 25, facet_size = 0.15, facet_distance = 0.008,
		cell_radius_edge_ratio = 3);

	// Mesh generation
	C3t3 c3t3 = CGAL::make_mesh_3<C3t3>(domain, criteria, no_perturb(), no_exude());
	// Output
	std::ofstream medit_file("E:/data/out1.mesh");
	c3t3.output_to_medit(medit_file);
	medit_file.close();
	// Set tetrahedron size (keep cell_radius_edge_ratio), ignore facets
	Mesh_criteria new_criteria(cell_radius_edge_ratio = 3, cell_size = 0.03);
	// Mesh refinement
	CGAL::refine_mesh_3(c3t3, domain, new_criteria);
	// Output
	medit_file.open("E:/data/out2.mesh");
	c3t3.output_to_medit(medit_file);


	return 0;
}

int grain::AdaptorCGAL::exportVolume()
{
	return 0;
}

double grain::AdaptorCGAL::getMeshingTime()
{
	return 0.0;
}
