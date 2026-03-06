#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

static void separator(std::string const & label)
{
	std::cout << "\n========== " << label << " ==========" << std::endl;
}

int main()
{
	separator("SUBJECT TEST");
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* me = new Character("me");

		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		ICharacter* bob = new Character("bob");

		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;
	}

	separator("FULL INVENTORY TEST");
	{
		Character hero("hero");
		hero.equip(new Ice());
		hero.equip(new Ice());
		hero.equip(new Cure());
		hero.equip(new Cure());
		AMateria* extra = new Ice();
		hero.equip(extra);
		delete extra; 
	}

	separator("INVALID USE TEST");
	{
		Character alice("alice");
		Character bob("bob");
		alice.use(0, bob); 
		alice.use(-1, bob);
		alice.use(5, bob);
	}

	separator("UNEQUIP / FLOOR TEST");
	{
		Character knight("knight");
		knight.equip(new Ice());
		knight.equip(new Cure());
		knight.unequip(0);
		knight.unequip(1);
		knight.unequip(0);
	}

	separator("DEEP COPY TEST");
	{
		Character original("original");
		original.equip(new Ice());
		original.equip(new Cure());

		Character copy(original);
		Character assigned("assigned");
		assigned = original;

		Character target("target");
		original.use(0, target);
		copy.use(0, target);
		assigned.use(1, target);
	}

	separator("UNKNOWN MATERIA TEST");
	{
		MateriaSource src;
		src.learnMateria(new Ice());
		AMateria* m = src.createMateria("fire");
		if (m)
		{
			std::cout << "ERROR: should have returned NULL" << std::endl;
			delete m;
		}
		else
			std::cout << "Correctly returned NULL for unknown type" << std::endl;
	}

	separator("END");
	return 0;
}