#include "internal.h"
#include "lib.h"

std::ostream& operator<<(std::ostream& os, const vec3& vector) {
	os << "vec3(" << vector.x << ", " << vector.y << ", " << vector.z << ")";
	return os;
}

triangleMesh test(triangleMesh mesh) {
	return triangleMesh(mesh);
}

// Leak tester 2000 (patent pending)
int main() {
	vec3* verts = new vec3[3];
	triangle* tris = new triangle[5];
	for (int i = 1; i < 4; i++) verts[i - 1] = vec3(i, i * 2, i * 3);
	for (int i = 0; i < 5; i++) tris[i] = triangle(&(verts[0]), &(verts[1]), &(verts[2]));
	triangleMesh mesh(verts, tris, 3, 5);

	int i = 0;
	while (true) {
		vec3* a = new vec3[45];
		triangle* b = new triangle[34];
		triangleMesh copy(a, b, 45, 34);
		copy = test(mesh);
		if (++i % 100 == 0) std::cout << i << std::endl;
	}

	return 0;
}