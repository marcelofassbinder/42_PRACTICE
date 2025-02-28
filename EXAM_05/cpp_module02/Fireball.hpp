#ifndef FIREBALL_HPP
#define FIREBALL_HPP

#include <iostream>
#include "ASpell.hpp"


class Fireball : public ASpell {

	public:
		Fireball();
		Fireball(const Fireball&);
		Fireball& operator=(const Fireball&);
		~Fireball();

		Fireball *clone();
};

#endif