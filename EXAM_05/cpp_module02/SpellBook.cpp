#include "SpellBook.hpp"

SpellBook::SpellBook() {}

SpellBook::SpellBook(const SpellBook &src) {(void) src;}

SpellBook &SpellBook::operator=(const SpellBook &src) {
	(void) src;
	return *this;
}

SpellBook::~SpellBook() {
	std::map<std::string, ASpell *>::iterator it;
	for (it = this->_book.begin(); it != this->_book.end(); it++) {
		delete it->second;
	}
	this->_book.clear();
	std::cout << "SPELL BOOK DESTRUCTOR" << std::endl;
}

void	SpellBook::learnSpell(ASpell *s) {
	this->_book.emplace(s->getName(), s->clone());
}

void	SpellBook::forgetSpell(std::string const &spellName) {
	std::map<std::string, ASpell *>::iterator it = this->_book.find(spellName);
	if (it != this->_book.end()) {
		delete it->second;
		this->_book.erase(spellName);
	}
}

ASpell* SpellBook::createSpell(std::string const &spellName) {
	
	std::map<std::string, ASpell *>::iterator it = this->_book.find(spellName);

	if (it != this->_book.end()) {
		return it->second;
	}
	return NULL;
}