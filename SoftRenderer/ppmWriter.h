#pragma once

#include "internal.h"
#include "lib.h"

class ppmWriter : public writer {
public:
	ppmWriter(std::string filename)
		: writer(filename) { }

	bool write(const surface& sf) const;
	std::string extension() const { return ".ppm"; }
};