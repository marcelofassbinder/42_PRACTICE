#ifndef SPELLBOOK_HPP
#define SPELLBOOK_HPP

#include <iostream>
#include <map>
#include <vector>
#include "ASpell.hpp"
#include "Fwoosh.hpp"
#include "Fireball.hpp"
#include "Polymorph.hpp"

class ASpell;
class SpellBook {

	private:
		std::map<std::string, ASpell *> _book;
		SpellBook(const SpellBook&);
		SpellBook& operator=(const SpellBook&);
	
	public:
		SpellBook();
		~SpellBook();

		void learnSpell(ASpell*);
		void forgetSpell(std::string const &spellName);
		ASpell* createSpell(std::string const &);
};

#endif