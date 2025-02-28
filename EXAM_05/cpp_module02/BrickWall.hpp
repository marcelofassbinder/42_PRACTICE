#ifndef BRICKWALL_HPP
#define BRICKWALL_HPP

#include <iostream>
#include "ATarget.hpp"

class BrickWall : public ATarget{

	public:
		BrickWall();
		BrickWall(const BrickWall&);
		BrickWall& operator=(const BrickWall&);
		~BrickWall();

		const std::string &getType() const;
		BrickWall *clone();
};

#endif