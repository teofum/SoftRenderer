#include "internal.h"
#include "lib.h"

// Constructors + Destructor -------------------

triangleMesh::triangleMesh(const triangleMesh& other) {
	vertices = new vec3[other.vCount];
	tris = new triangle[other.tCount];

	std::copy(other.vertices, other.vertices + other.vCount, vertices);
	std::copy(other.tris, other.tris + other.tCount, tris);

	vCount = other.vCount;
	tCount = other.tCount;
}

triangleMesh::triangleMesh(triangleMesh&& other) noexcept {
	delete[] vertices;
	delete[] tris;
	vertices = std::exchange(other.vertices, nullptr);
	tris = std::exchange(other.tris, nullptr);
	vCount = std::exchange(other.vCount, 0);
	tCount = std::exchange(other.tCount, 0);
}

triangleMesh::~triangleMesh() {
	delete[] vertices;
	delete[] tris;
}

// Assignment operators ------------------------

triangleMesh& triangleMesh::operator=(const triangleMesh& other) {
	if (this == &other) return *this;

	if (vCount != other.vCount) {
		delete[] vertices;
		vertices = nullptr;
		vCount = 0;
		vertices = new vec3[other.vCount];
		vCount = other.vCount;
	}

	if (tCount != other.tCount) {
		delete[] tris;
		tris = nullptr;
		tCount = 0;
		tris = new triangle[other.tCount];
		tCount = other.tCount;
	}

	std::copy(other.vertices, other.vertices + vCount, vertices);
	std::copy(other.tris, other.tris + tCount, tris);
	return *this;
}

triangleMesh& triangleMesh::operator=(triangleMesh&& other) noexcept {
	if (this == &other) return *this;

	delete[] vertices;
	delete[] tris;
	vertices = std::exchange(other.vertices, nullptr);
	tris = std::exchange(other.tris, nullptr);
	vCount = std::exchange(other.vCount, 0);
	tCount = std::exchange(other.tCount, 0);
	return *this;
}