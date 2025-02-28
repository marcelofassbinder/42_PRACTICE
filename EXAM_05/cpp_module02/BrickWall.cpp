#include "BrickWall.hpp"

BrickWall::BrickWall() : ATarget("Inconspicuous Red-brick Wall"){}

BrickWall::BrickWall(const BrickWall &src) {(void) src;}

BrickWall &BrickWall::operator=(const BrickWall &src) {
	(void) src;
	return *this;
}

BrickWall::~BrickWall() {}

BrickWall* BrickWall::clone() {
	return new BrickWall();
}
