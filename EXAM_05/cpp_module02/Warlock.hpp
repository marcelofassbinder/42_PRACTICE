#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include "ATarget.hpp"
#include "ASpell.hpp"
#include "SpellBook.hpp"

class ASpell;
class SpellBook;
class ATarget;
class Warlock {

	private:
		SpellBook _spellBook;
		std::string _name;
		std::string _title;

		Warlock();
		Warlock(const Warlock&);
		Warlock& operator=(const Warlock&);
		
		public:
		Warlock(std::string name, std::string title);
		~Warlock();

		const std::string &getName() const;
		const std::string &getTitle() const;
		void	setTitle(const std::string &newTitle);
		void	introduce() const;
		void	learnSpell(ASpell *s);
		void	forgetSpell(std::string spellName);
		void	launchSpell(const std::string spellName, ATarget&);
};

#endif