#pragma once

#include "internal.h"

class surface {
private:
	int w, h, size;
	float* buffer;

public:
	// Constructor ---------------------------------

	surface(int, int);
	surface(const surface&);
	surface(surface&&) noexcept;
	~surface();

	// Assignment operators ------------------------

	surface& operator=(const surface&);
	surface& operator=(surface&&) noexcept;

	// Properties ----------------------------------

	const int getWidth() const { return w; }
	const int getHeight() const { return h; }

	// Graphics functions --------------------------

	void putPixel(int, int, const vec3&);
	void getPixel(int, int, vec3&) const;
};