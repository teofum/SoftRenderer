#pragma once

#include "internal.h"
#include "lib.h"

class writer {
protected:
	std::string filename;
	std::string getActualFilename() const;

public:
	writer(std::string filename)
		: filename(filename) { }

	virtual bool write(const surface& sf) const = 0;
	virtual std::string extension() const = 0;
};