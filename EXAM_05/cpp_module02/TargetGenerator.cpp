#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}

TargetGenerator::TargetGenerator(const TargetGenerator &src) {(void) src;}

TargetGenerator &TargetGenerator::operator=(const TargetGenerator &src) {
	(void) src;
	return *this;
}

TargetGenerator::~TargetGenerator() {
	std::map<std::string, ATarget *>::iterator it;
	for (it = this->_book.begin(); it != this->_book.end(); it++) {
		delete it->second;
	}
	this->_book.clear();
}

void	TargetGenerator::learnTargetType(ATarget *t) {
	this->_book.emplace(t->getType(), t->clone());
}

void	TargetGenerator::forgetTargetType(std::string const &targetType) {
	std::map<std::string, ATarget *>::iterator it = this->_book.find(targetType);
	if (it != this->_book.end()) {
		delete it->second;
		this->_book.erase(targetType);
	}
}

ATarget* TargetGenerator::createTarget(std::string const &targetType) {
	
	std::map<std::string, ATarget *>::iterator it = this->_book.find(targetType);
	if (it != this->_book.end()) {
		return it->second;
	}
	return NULL;
}