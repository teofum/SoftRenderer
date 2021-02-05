#include "internal.h"
#include "lib.h"

std::ostream& operator<<(std::ostream& os, const vec3& vector) {
	os << "vec3(" << vector.x << ", " << vector.y << ", " << vector.z << ")";
	return os;
}

int main() {
	surface sf(20, 20);
	for (int i = 0; i < 20; i++) for (int j = 0; j < 20; j++)
		sf.putPixel(i, j, vec3(i / 20.0, j / 20.0, 0.0));

	vec3 value;
	for (int i = 0; i < 20; i++) for (int j = 0; j < 20; j++) {
		sf.getPixel(i, j, value);
		std::cout << value << std::endl;
	}

	return 0;
}