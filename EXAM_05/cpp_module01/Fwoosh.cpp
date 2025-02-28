#include "Fwoosh.hpp"

Fwoosh::Fwoosh() : ASpell("Fwoosh", "fwooshed") {}

Fwoosh::Fwoosh(const Fwoosh &src) {(void) src;}

Fwoosh &Fwoosh::operator=(const Fwoosh &src) {
	(void) src;
	return *this;
}

Fwoosh::~Fwoosh() {}

Fwoosh* Fwoosh::clone() {
	return new Fwoosh();
}
