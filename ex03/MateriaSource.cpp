#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		_templates[i] = NULL;
	std::cout << "MateriaSource constructed" << std::endl;
}

MateriaSource::MateriaSource(MateriaSource const & other)
{
	for (int i = 0; i < 4; i++)
		_templates[i] = NULL;
	for (int i = 0; i < 4; i++)
	{
		if (other._templates[i])
			_templates[i] = other._templates[i]->clone();
	}
	std::cout << "MateriaSource copy constructed" << std::endl;
}

MateriaSource & MateriaSource::operator=(MateriaSource const & other)
{
	if (this == &other)
		return *this;
	for (int i = 0; i < 4; i++)
	{
		delete _templates[i];
		_templates[i] = NULL;
	}
	for (int i = 0; i < 4; i++)
	{
		if (other._templates[i])
			_templates[i] = other._templates[i]->clone();
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
		delete _templates[i];
	std::cout << "MateriaSource destroyed" << std::endl;
}

void MateriaSource::learnMateria(AMateria* m)
{
	if (!m)
		return;
	for (int i = 0; i < 4; i++)
	{
		if (_templates[i] == NULL)
		{
			_templates[i] = m;
			std::cout << "MateriaSource learned [" << m->getType() << "]" << std::endl;
			return;
		}
	}
	std::cout << "MateriaSource is full, cannot learn more" << std::endl;
	delete m;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_templates[i] && _templates[i]->getType() == type)
			return _templates[i]->clone();
	}
	std::cout << "MateriaSource: unknown type [" << type << "]" << std::endl;
	return NULL;
}