#include "internal.h"
#include "lib.h"

std::ostream& operator<<(std::ostream& os, const vec3& vector) {
	os << "vec3(" << vector.x << ", " << vector.y << ", " << vector.z << ")";
	return os;
}

int main() {
	int w = 360, h = 240;

	surface sf(w, h);
	for (int i = 0; i < w; i++) for (int j = 0; j < h; j++)
		sf.putPixel(i, j, vec3(i / 60.0, j / 60.0, (j / 60)/4.0));

	ppmWriter writer("test");
	writer.write(sf);

	return 0;
}