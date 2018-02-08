#include "adaptorcgal.h"

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
	c3t3 = CGAL::make_mesh_3<C3t3>(domain, criteria, no_perturb(), no_exude());
	// Output
	std::ofstream medit_file("E:/data/out1.mesh");
	c3t3.output_to_medit(medit_file);
	medit_file.close();
	// Set tetrahedron size (keep cell_radius_edge_ratio), ignore facets
	//Mesh_criteria new_criteria(cell_radius_edge_ratio = 3, cell_size = 0.03);
	// Mesh refinement
	//CGAL::refine_mesh_3(c3t3, domain, new_criteria);
	// Output
	//medit_file.open("E:/data/out2.mesh");
	//c3t3.output_to_medit(medit_file);


	return 0;
}

grain::GrainMesh * grain::AdaptorCGAL::exportVolume()
{
	typedef typename C3t3::Cells_in_complex_iterator Cell_iterator;
	typedef typename C3t3::Facets_in_complex_iterator Facet_iterator;
	typedef typename Tr::Finite_vertices_iterator Finite_vertices_iterator;
	typedef typename Tr::Vertex_handle Vertex_handle;
	const Tr& trg = c3t3.triangulation();
	typedef typename Tr::Point Point_3;
	boost::unordered_map<Vertex_handle, int> V;

	std::cout << "Vertices count: " << c3t3.triangulation().number_of_vertices() << "\n";
	std::cout << "Tetra count: " << c3t3.number_of_cells() << "\n";
	//std::cout << "Faces count: " << c3t3.triangulation().number_of_finite_facets() << "\n";

	// Export vertices //
	std::vector<vec3d> vertices =
		std::vector<vec3d>(c3t3.triangulation().number_of_vertices() + 1);
	int inum = 0;

	for (Finite_vertices_iterator vit = trg.finite_vertices_begin();
		vit != trg.finite_vertices_end(); ++vit)
	{
		V[vit] = inum++;
		Point_3 p = vit->point();

		vertices[inum].x = p.x();
		vertices[inum].y = p.y();
		vertices[inum].z = p.z();
	}
	std::vector<char> verticesLabel =
		std::vector<char>(c3t3.triangulation().number_of_vertices() + 1);
	for (int i = 0; i < verticesLabel.size(); i++)
		verticesLabel[i] = 0;
	
	// Export tetra //
	inum = 0;
	std::vector<vec4i> tetra = std::vector<vec4i>(c3t3.number_of_cells());
	for (Cell_iterator cit = c3t3.cells_in_complex_begin();
		cit != c3t3.cells_in_complex_end(); ++cit)
	{
		tetra[inum].x = V[cit->vertex(0)];
		tetra[inum].y = V[cit->vertex(1)];
		tetra[inum].z = V[cit->vertex(2)];
		tetra[inum].w = V[cit->vertex(3)];
		inum++;
	}
	std::vector<char> tetraLabel = std::vector<char>(c3t3.number_of_cells());
	for (int i = 0; i < tetraLabel.size(); i++)
		tetraLabel[i] = 0;

	grain::GrainMesh * mesh = new grain::GrainMesh();
	mesh->setTetra(tetra);
	mesh->setTetraLabels(tetraLabel);
	mesh->setVertices(vertices);
	mesh->setVerticesLabels(verticesLabel);

	return mesh;
}

double grain::AdaptorCGAL::getMeshingTime()
{
	return 0.0;
}
