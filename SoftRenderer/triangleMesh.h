#pragma once

#include "internal.h"
#include "lib.h"

class triangleMesh {
private:
	vec3* vertices;
	triangle* tris;
	int vCount, tCount;

public:
	// Constructors + Destructor -------------------

	triangleMesh(vec3* vertices, triangle* triangles, int vertexCount, int triangleCount) 
		:vertices(vertices), tris(triangles), vCount(vertexCount), tCount (triangleCount)
	{ }

	triangleMesh(const triangleMesh&);
	triangleMesh(triangleMesh&&) noexcept;
	~triangleMesh();

	// Assignment operators ------------------------

	triangleMesh& operator=(const triangleMesh&);
	triangleMesh& operator=(triangleMesh&&) noexcept;

	// Additional methods --------------------------

	int vertexCount() const { return vCount; }
	int triangleCount() const { return tCount; }
	triangle* const triangles() const { return tris; }
};