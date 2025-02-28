#ifndef FWOOSH_HPP
#define FWOOSH_HPP

#include <iostream>
#include "ASpell.hpp"


class Fwoosh : public ASpell {

	public:
		Fwoosh();
		Fwoosh(const Fwoosh&);
		Fwoosh& operator=(const Fwoosh&);
		~Fwoosh();

		Fwoosh *clone();
};

#endif