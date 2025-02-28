#include "Warlock.hpp"

Warlock::Warlock() {}

Warlock::Warlock(std::string name, std::string title): _name(name), _title(title) {
	std::cout << name << ": This looks like another boring day." << std::endl;
}

Warlock::Warlock(const Warlock &src) {(void) src;}

Warlock &Warlock::operator=(const Warlock &src) {
	(void) src;
	return *this;
}

Warlock::~Warlock() {
	std::cout << this->_name << ": My job here is done!" << std::endl;
}

const std::string &Warlock::getName() const {
	return this->_name;
}

const std::string &Warlock::getTitle() const {
	return this->_title;
}

void	Warlock::setTitle(const std::string &newTtile) {
	this->_title = newTtile;
}

void	Warlock::introduce() const {
	std::cout << this->_name + ": I am " + this->_name + ", " + this->_title + "!" << std::endl;
}

void	Warlock::learnSpell(ASpell *s) {
	this->_spells.emplace(s->getName(), s);
}

void	Warlock::forgetSpell(std::string spellName) {
	std::map<std::string, ASpell *>::iterator it;

	it = this->_spells.find(spellName);
	if (it != this->_spells.end()) {
		delete it->second;
		this->_spells.erase(spellName);
	}
}

void	Warlock::launchSpell(const std::string spellName, ATarget&t) {
	std::map<std::string, ASpell *>::iterator it;

	for (it = this->_spells.begin(); it != this->_spells.end(); it++) {
		if (it->first == spellName)
			it->second->launch(t);
	}
}