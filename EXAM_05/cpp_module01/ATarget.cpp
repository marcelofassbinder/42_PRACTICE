#include "ATarget.hpp"

ATarget::ATarget() {}

ATarget::ATarget(std::string type): _type(type) {}

ATarget::ATarget(const ATarget &src) {(void) src;}

ATarget &ATarget::operator=(const ATarget &src) {
	(void) src;
	return *this;
}

ATarget::~ATarget() {}

const std::string &ATarget::getType() const {
	return this->_type;
}

void	ATarget::getHitBySpell(const ASpell &spell) const {
	std::cout << this->_type << " has been " << spell.getEffects() << "!" << std::endl;
}

