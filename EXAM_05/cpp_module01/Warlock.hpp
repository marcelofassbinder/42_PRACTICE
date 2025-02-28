#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include "ATarget.hpp"
#include "ASpell.hpp"
#include <map>

class ASpell;
class ATarget;
class Warlock {

	private:
		std::string _name;
		std::string _title;
		std::map<std::string, ASpell *> _spells;

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