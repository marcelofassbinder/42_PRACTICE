#ifndef POLYMORPH_HPP
#define POLYMORPH_HPP

#include <iostream>
#include "ASpell.hpp"


class Polymorph : public ASpell {

	public:
		Polymorph();
		Polymorph(const Polymorph&);
		Polymorph& operator=(const Polymorph&);
		~Polymorph();

		Polymorph *clone();
};

#endif