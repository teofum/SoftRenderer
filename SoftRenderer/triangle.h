#pragma once

#include "internal.h"

class triangle {
private:
	vec3** vertices;

public:
	// Constructors + Destructor -------------------

	triangle(vec3*, vec3*, vec3*);
	triangle(const triangle&);
	triangle(triangle&&) noexcept;
	~triangle();

	// Assignment operators ------------------------

	triangle& operator=(const triangle&);
	triangle& operator=(triangle&&) noexcept;

	// Index operator ------------------------------

	vec3* const operator[](int);

	// Additional methods --------------------------
	
	vec3* const vertex(int) const;
	vec3 edge(int, int) const;
	vec3 normal() const;
};