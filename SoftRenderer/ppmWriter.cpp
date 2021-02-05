#include "internal.h"
#include "lib.h"

bool ppmWriter::write(const surface& sf) const {
	std::ofstream ofs;
	std::string fn = getActualFilename();
	vec3 value;

	// Open file in text mode and write header
	ofs.open(fn);
	// Manual line end because \n inserts CR+LF line ending, shifting everything by one byte
	ofs << "P6\n" << sf.getWidth() << " " << sf.getHeight() << "\n255" << (char)0x0d;
	ofs.close();

	// We told the file it's a binary file in the header, so switch to binary mode and write data
	ofs.open(fn, std::ios::app | std::ios::binary);
	for (int y = 0; y < sf.getHeight(); y++)
		for (int x = 0; x < sf.getWidth(); x++) {
			sf.getPixel(x, y, value);
			
			// Convert float values to byte and write
			unsigned char r = (unsigned char)(value.x * 255);
			unsigned char g = (unsigned char)(value.y * 255);
			unsigned char b = (unsigned char)(value.z * 255);
			ofs << r << g << b;
		}
	ofs.close();

	return true;
}