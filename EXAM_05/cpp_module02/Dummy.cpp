#include "Dummy.hpp"

Dummy::Dummy() : ATarget("Target Practice Dummy"){}

Dummy::Dummy(const Dummy &src) {(void) src;}

Dummy &Dummy::operator=(const Dummy &src) {
	(void) src;
	return *this;
}

Dummy::~Dummy() {}

Dummy* Dummy::clone() {
	return new Dummy();
}
