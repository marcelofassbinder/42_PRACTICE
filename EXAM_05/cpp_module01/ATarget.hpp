#ifndef ATARGET_HPP
#define ATARGET_HPP

#include <iostream>
#include "ASpell.hpp"

class ASpell;
class ATarget {

	protected:
		std::string _type;
	
	public:
		ATarget();
		ATarget(std::string type);
		ATarget(const ATarget&);
		ATarget& operator=(const ATarget&);
		virtual ~ATarget();

		const std::string &getType() const;
		virtual ATarget *clone() = 0;
		void	getHitBySpell(const ASpell &spell) const;
};

#endif