#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria(std::string const & type) : _type(type) 
{
    std::cout << "AMateria [" << _type "] constructed" << std::endl;
}

AMateria::AMateria(AMateria const & other) : _type(other._type)
{
	std::cout << "AMateria [" << _type << "] copy constructed" << std::endl;
}

AMateria & AMateria::operator=(AMateria const & other)
{
	(void)other;
	return *this;
}

AMateria::~AMateria()
{
	std::cout << "AMateria [" << _type << "] destroyed" << std::endl;
}

std::string const & AMateria::getType() const
{
	return _type;
}

void AMateria::use(ICharacter& target)
{
	(void)target;
	std::cout << "AMateria::use called (base)" << std::endl;
}
