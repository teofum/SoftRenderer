#include "internal.h"
#include "lib.h"

std::string writer::getActualFilename() const {
	std::string fn = filename;
	std::string serial = "";
	int i = 1;
	while (std::filesystem::exists(fn + serial + extension()))
		serial = "_" + std::to_string(i++);

	fn += serial + extension();
	return fn;
}