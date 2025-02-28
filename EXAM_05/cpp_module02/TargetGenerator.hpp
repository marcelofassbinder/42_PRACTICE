#ifndef TARGETGENERATOR_HPP
#define TARGETGENERATOR_HPP

#include <iostream>
#include "ATarget.hpp"
#include "Dummy.hpp"
#include "BrickWall.hpp"
#include <map>
#include <vector>

class ATarget;
class TargetGenerator {

	private:
		std::map<std::string, ATarget *> _book;
		TargetGenerator(const TargetGenerator&);
		TargetGenerator& operator=(const TargetGenerator&);
	
	public:
		TargetGenerator();
		virtual ~TargetGenerator();

		void learnTargetType(ATarget*);
		void forgetTargetType(std::string const &);
		ATarget* createTarget(std::string const &);
};

#endif