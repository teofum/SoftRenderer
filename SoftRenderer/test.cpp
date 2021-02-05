#include "internal.h"
#include "lib.h"

std::ostream& operator<<(std::ostream& os, const vec3& vector) {
	os << "vec3(" << vector.x << ", " << vector.y << ", " << vector.z << ")";
	return os;
}

triangle test(vec3* v) {
	return triangle(v, v, v);
}

int main() {
	vec3 a(3, 2, 2);
	vec3 b(a + vec3(1, 1, -1));
	vec3 c;
	c = (a + vec3(1, 1, 1));

	triangle t(&a, &b, &c);
	triangle u(test(&a));
	triangle v(&c, &b, &a);
	v = test(&a);

	return 0;
}