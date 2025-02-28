#ifndef ASPELL_HPP
#define ASPELL_HPP

#include <iostream>
#include "ATarget.hpp"

class ATarget;
class ASpell {

	protected:
		std::string _name;
		std::string _effects;
	
	public:
		ASpell();
		ASpell(std::string name, std::string effects);
		ASpell(const ASpell&);
		ASpell& operator=(const ASpell&);
		virtual ~ASpell();

		const std::string &getName() const;
		const std::string &getEffects() const;
		virtual ASpell *clone() = 0;
		void	launch(const ATarget &t);
};

#endif