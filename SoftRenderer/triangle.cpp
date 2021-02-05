#include "internal.h"
#include "lib.h"

// Constructors + Destructor -------------------

triangle::triangle() {
	vertices = new vec3*[3];
}

triangle::triangle(vec3* a, vec3* b, vec3* c) {
	vertices = new vec3*[3]{ a, b, c };
}

triangle::triangle(const triangle& other) {
	vertices = new vec3*[3];
	std::copy(other.vertices, other.vertices + 3, vertices);
}

triangle::triangle(triangle&& other) noexcept {
	delete[] vertices;
	vertices = std::exchange(other.vertices, nullptr);
}

triangle::~triangle() {
	delete[] vertices;
}

// Assignment operators ------------------------

triangle& triangle::operator=(const triangle& other) {
	if (this == &other) return *this;

	std::copy(other.vertices, other.vertices + 3, vertices);
	return *this;
}

triangle& triangle::operator=(triangle&& other) noexcept {
	if (this == &other) return *this;

	delete[] vertices;
	vertices = std::exchange(other.vertices, nullptr);
	return *this;
}

// Index operator ------------------------------

vec3* const triangle::operator[](int i) {
	return vertex(i);
}

// Additional methods --------------------------

vec3* const triangle::vertex(int i) const {
	return vertices[i];
}

vec3 triangle::edge(int a, int b) const {
	return *vertex(b) - *vertex(a);
}

vec3 triangle::normal() const {
	vec3 edge1 = *vertex(1) - *vertex(0);
	vec3 edge2 = *vertex(2) - *vertex(0);

	return edge1.cross(edge2).normalized();
}