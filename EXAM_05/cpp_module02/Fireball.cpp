#include "Fireball.hpp"

Fireball::Fireball() : ASpell("Fireball", "burnt to a crisp") {}

Fireball::Fireball(const Fireball &src) {(void) src;}

Fireball &Fireball::operator=(const Fireball &src) {
	(void) src;
	return *this;
}

Fireball::~Fireball() {}

Fireball* Fireball::clone() {
	return new Fireball();
}
