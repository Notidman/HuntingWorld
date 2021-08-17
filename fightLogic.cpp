#include "FightLogic.h"
#include "HeirsOfAnEnemy.h"
#include "LogicShopFunction.h"
#include "Logic.h"
#include "Sms.h"
#include "Color.h"
#include "BattleLogic.h"

#include <random>
#include <functional>
#include <ctime>

void Attack(Hero& hero, Enemy* p_enemy, int damageIn)
{
	FSL();
	SetColor(ConsoleColor::Black, ConsoleColor::Red);
	std::cout << " Battlelog:" << std::endl;
	SetColor(ConsoleColor::White, ConsoleColor::Black);
	FSL();

	Sleep(150);
	hero.AttackEnemy(hero, p_enemy, damageIn);
	if (p_enemy->GetHealth() <= 0 && hero.GetHealth() > 0)
	{
		DSTgo();
		return;
	}
	p_enemy->AttackHero(hero);
	Sleep(150);
	FSL();

	DSTgo();
}

void TryEscape(Hero& hero, Enemy* p_enemy, bool& status)
{
    std::mt19937 mersenne(static_cast<unsigned int>(time(0)));
	int ch = 1 + mersenne() % 100;

	if (ch >= 95)
	{
		Sms("Successful escape!");
		status = false;
	}
	else
	{
		Sms("Escape failed!");
		p_enemy->AttackHero(hero);
		DSTgo();
		status = true;
	}
}

Enemy* Notification(Hero& hero)
{
	system("cls");

	std::cout << " The enemy is found!" << std::endl;
    std::mt19937 mersenne(static_cast<unsigned int>(time(0)));
	int chance = 0 + mersenne() % 100;

#if 1
	if (chance >= 0 && chance < 40)
	{
        return new FSlime(hero);
	}
	else if (chance >= 40 && chance < 80)
	{
		return new Goblin(hero);
	}
	else if (chance >= 80)
	{
		return new SlimeBoss(hero);
	}
#endif
	return new Goblin(hero);
}

void Solution(short& gch, Enemy* p_enemy, Hero& h)
{
	std::vector<std::string> menu_collection = { {" Attack"}, {" Special attack"}, {" Open inventory"}, {" Try to escape"}};

	FSL();
    SetColor(p_enemy->getColor(), ConsoleColor::Black);
	p_enemy->showSprite();
    SetColor(ConsoleColor::White, ConsoleColor::Black);
	FSL();

	p_enemy->showStatus();
	FSL();
	h.showStatus();
	FSL();

	std::cout << "\n";
	int i = 1;
	for (auto& str : menu_collection)
	{
		std::cout << " " << i << ")" << str << " |" << (i % 4 == 0 ? "\n" : "  ");
		i++;
	}

	std::cout << "\n Enter your choice:\n > ";

	gch = checkInput();
}

bool WinFight(Hero& hero, Enemy* p_enemy)
{
	Sms("You won this fight\n Congratulations!");
	hero.AddGold(p_enemy->GetGold());
	hero.LvlUp(p_enemy->GetExp());

	return false;
}

void LoseFight()
{
	Sms("You died in battle!");
	Sms("It is sad =(");
	Sms("Try again!!!");
	DSTgo();

	exit(0);
}

void Fight(Hero& hero)
{
	enum FightList
	{
		fightATTACK = 1,
		fightSPECIAL = 2,
		fightINV = 3,
		fightRUN = 4,
	};

	Enemy* p_enemy = Notification(hero);

	bool fight = true;
	short getchoice;

	while (fight)
	{
		system("cls");
		Solution(getchoice, p_enemy, hero);

		switch (getchoice)
		{
			case FightList::fightATTACK:
				Attack(hero, p_enemy, hero.GetWeaponAttack());
				break;
			case FightList::fightSPECIAL:
                Attack(hero, p_enemy, hero.GetWeaponAttackS());
				break;
			case FightList::fightINV:
				Inventory(hero);
				break;
			case FightList::fightRUN:
				TryEscape(hero, p_enemy, fight);
				break;
			default:
				ErrorMessage();
				break;
		}

		if (hero.GetHealth() <= 0)
			LoseFight();

		if (p_enemy->GetHealth() <= 0 && hero.GetHealth() > 0)
			fight = WinFight(hero, p_enemy);
	}
}
