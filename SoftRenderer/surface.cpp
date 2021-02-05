#include "internal.h"
#include "lib.h"

// Constructor ---------------------------------

surface::surface(int width, int height)
	: w(width), h(height) {
	size = w * h * 3;
	buffer = new float[size];
}

surface::surface(const surface& other) {
	buffer = new float[other.size];
	std::copy(other.buffer, other.buffer + other.size, buffer);

	w = other.w;
	h = other.h;
	size = other.size;
}

surface::surface(surface&& other) noexcept {
	w = std::exchange(other.w, 0);
	h = std::exchange(other.h, 0);
	size = std::exchange(other.size, 0);
	buffer = std::exchange(other.buffer, nullptr);
}

surface::~surface() {
	delete[] buffer;
}

// Assignment operators ------------------------

surface& surface::operator=(const surface& other) {
	if (this == &other) return *this;

	if (size != other.size) {
		delete[] buffer;
		buffer = nullptr;
		size = 0;
		buffer = new float[other.size];
		size = other.size;
	}

	if (w != other.w) w = other.w;
	if (h != other.h) h = other.h;
	std::copy(other.buffer, other.buffer + other.size, buffer);
	return *this;
}

surface& surface::operator=(surface&& other) noexcept {
	if (this == &other) return *this;

	delete[] buffer;

	w = std::exchange(other.w, 0);
	h = std::exchange(other.h, 0);
	size = std::exchange(other.size, 0);
	buffer = std::exchange(other.buffer, nullptr);
	return *this;
}

// Graphics functions --------------------------

void surface::putPixel(int x, int y, const vec3& color) {
	int i = (y * w + x) * 3;
	if (i < 0 || i > size) return;

	buffer[i] = color.x;
	buffer[i + 1] = color.y;
	buffer[i + 2] = color.z;
}

void surface::getPixel(int x, int y, vec3& color) const {
	int i = (y * w + x) * 3;
	if (i < 0 || i > size) return;

	color.x = buffer[i];
	color.y = buffer[i + 1];
	color.z = buffer[i + 2];
}