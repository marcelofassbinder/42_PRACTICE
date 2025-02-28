#include "Polymorph.hpp"

Polymorph::Polymorph() : ASpell("Polymorph", "turned into a critter") {}

Polymorph::Polymorph(const Polymorph &src) {(void) src;}

Polymorph &Polymorph::operator=(const Polymorph &src) {
	(void) src;
	return *this;
}

Polymorph::~Polymorph() {}

Polymorph* Polymorph::clone() {
	return new Polymorph();
}
