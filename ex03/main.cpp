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
	// --- Subject test ---
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

	// --- Test: full inventory ---
	separator("FULL INVENTORY TEST");
	{
		Character hero("hero");
		hero.equip(new Ice());
		hero.equip(new Ice());
		hero.equip(new Cure());
		hero.equip(new Cure());
		// This should print "inventory full"
		AMateria* extra = new Ice();
		hero.equip(extra);
		delete extra; // must clean up manually since equip failed
	}

	// --- Test: use with out-of-bounds / empty slot ---
	separator("INVALID USE TEST");
	{
		Character alice("alice");
		Character bob("bob");
		alice.use(0, bob); // slot 0 is empty
		alice.use(-1, bob);
		alice.use(5, bob);
	}

	// --- Test: unequip and floor cleanup ---
	separator("UNEQUIP / FLOOR TEST");
	{
		Character knight("knight");
		knight.equip(new Ice());
		knight.equip(new Cure());
		knight.unequip(0);
		knight.unequip(1);
		knight.unequip(0); // already empty, should do nothing
		// knight destructor should delete floor materias
	}

	// --- Test: deep copy of Character ---
	separator("DEEP COPY TEST");
	{
		Character original("original");
		original.equip(new Ice());
		original.equip(new Cure());

		Character copy(original); // copy constructor
		Character assigned("assigned");
		assigned = original;     // assignment operator

		Character target("target");
		original.use(0, target);
		copy.use(0, target);
		assigned.use(1, target);
	}

	// --- Test: unknown materia type ---
	separator("UNKNOWN MATERIA TEST");
	{
		MateriaSource src;
		src.learnMateria(new Ice());
		AMateria* m = src.createMateria("fire"); // unknown
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