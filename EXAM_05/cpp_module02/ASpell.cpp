#include "ASpell.hpp"

ASpell::ASpell() {}

ASpell::ASpell(std::string name, std::string effects): _name(name), _effects(effects) {}

ASpell::ASpell(const ASpell &src) {(void) src;}

ASpell &ASpell::operator=(const ASpell &src) {
	(void) src;
	return *this;
}

ASpell::~ASpell() {}

const std::string &ASpell::getName() const {
	return this->_name;
}

const std::string &ASpell::getEffects() const {
	return this->_effects;
}

void	ASpell::launch(const ATarget &t) {
	t.getHitBySpell(*this);
}