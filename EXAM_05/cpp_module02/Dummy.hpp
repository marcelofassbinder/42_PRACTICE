#ifndef DUMMY_HPP
#define DUMMY_HPP

#include <iostream>
#include "ATarget.hpp"

class Dummy : public ATarget{

	public:
		Dummy();
		Dummy(const Dummy&);
		Dummy& operator=(const Dummy&);
		~Dummy();

		const std::string &getType() const;
		Dummy *clone();
};

#endif