#include "FightLogic.h"
#include "HeirsOfAnEnemy.h"
#include "LogicShopFunction.h"
#include "Logic.h"
#include "Sms.h"
#include "lpct.hpp"
#include "BattleLogic.h"
#include "Listgui.h"
#include "StateMachine.h"
#include "console.hpp"

#include <random>
#include <functional>
#include <ctime>

void ShowBattlelogText()
{
    FSL();
    std::cout << "\033[0;41m" << " Battlelog: " << "\033[0m" << std::endl;
    FSL();
}

void Attack(Hero& hero, Enemy* p_enemy, int damageIn)
{
    ShowBattlelogText();

	hero.attackEnemy(hero, p_enemy, damageIn);
	if (p_enemy->getHealth() <= 0 && hero.getHealth() > 0)
	{
		DSTgo();
		return;
	}
	p_enemy->attackHero(hero);
	sleep(1);
	FSL();

	DSTgo();
}


void SignalAttackReset()
{
    ShowBattlelogText();

    std::cout << " Special attack is still on cooldown!";

    sleep(1);
    DSTgo();
}

void NoEscape()
{
    ShowBattlelogText();

    sleep(1);
    lpct::prcolorln<std::string>(lpct::colors::magenta, " A magic barrier blocks your escape route,\n there is no way out!");
    FSL();
    sleep(1);
    DSTgo();
}

void TryEscape(Hero& hero, Enemy* p_enemy, bool& status)
{
    ShowBattlelogText();

    sleep(1);
    std::mt19937 mersenne(static_cast<unsigned int>(time(0)));
    int ch = 0 + mersenne() % 100;

    if (ch >= 80)
	{
        std::cout << " Successful escape!\n";
        DSTgo();
		status = false;
	}
	else
	{
        std::cout << " Escape failed!\n";
		p_enemy->attackHero(hero);
		DSTgo();
		status = true;
	}

    hero.resetSp = 2;

}

Enemy* Notification(Hero& hero, std::string loc)
{
  clrcon();

	std::cout << " The enemy is found!" << std::endl;
    std::mt19937 mersenne(static_cast<unsigned int>(time(0)));
	int chance = 0 + mersenne() % 100;

    if(loc == location_collection[0]) // {"Mysterious forest"}
    {
        if (chance >= 0 && chance < 29)
        {
            return new Slime(hero);
        }
        else if (chance >= 30 && chance < 59)
        {
            return new Goblin(hero);
        }
        else if (chance >= 60 && chance < 79 && hero.getDay() > 1)
        {
            return new FSlime(hero);
        }
        else if (chance >= 80 && chance < 97 && hero.getDay() > 2)
        {
            return new SlimeBoss(hero);
        }
        else if (chance >= 98 && hero.getDay())
        {
            return new RSlimeBoss(hero);
        }
        else
        {
            return new Goblin(hero);
        }
    }
    else if(loc == location_collection[1]) // {"Old castle"}
    {
        if (chance >= 0 && chance < 40)
        {
            return new Ghost(hero);
        }
        else if (chance >= 40 && chance < 80)
        {
            return new Skeleton(hero);
        }
        else if (chance >= 80)
        {
            return new Knight(hero);
        }
        else
        {
            return new Ghost(hero);
        }
    }
    else if(loc == location_collection[2]) // {"Sacred mountains"}
    {
        if (chance >= 0 && chance < 40)
        {
            return new StoneGolem(hero);
        }
        else if (chance >= 40 && chance < 80)
        {
            return new Angel(hero);
        }
        else if (chance >= 80)
        {
            return new FireSpirit(hero);
        }
        else
        {
            return new StoneGolem(hero);
        }
    }
    else if(loc == location_collection[3]) // {"Cave of time"}
    {
        return new GreatDragon(hero);
    }

	return new Goblin(hero);
}

void Solution(short& gch, Enemy* p_enemy, Hero& h)
{
    std::vector<std::string> menu_collection = { {"Attack"}, {"Special attack"}, {"Open inventory"}, {"Try to escape"}};

	FSL();
	p_enemy->showSprite();
	FSL();

	p_enemy->showStatus();
	FSL();
	h.showStatus();
	FSL();

	std::cout << "\n";
	int i = 1;
	for (auto& str : menu_collection)
	{
        if(str == menu_collection[1] && h.resetSp > 0)
        {
            lpct::prcolor<std::string>(lpct::colors::red, " [" + std::to_string(i) + "|" + str + "]");
            std::cout << (i % 4 == 0 ? "\n" : "");
        }
        else
        {
            std::cout <<  " [" << i << "|" << str << "]" << (i % 4 == 0 ? "\n" : " ");
        }
		i++;
	}

	std::cout << "\n Enter your choice:\n > ";

	gch = checkInput();
}

bool WinFight(Hero& hero, Enemy* p_enemy)
{
	Sms("You won this fight\n Congratulations!");
	hero.addGold(p_enemy->getGold());
	hero.lvlUp(p_enemy->getExp());

	return false;
}

void LoseFight(StateMachine* sm)
{
    clrcon();
    std::vector<std::string> lph {{"\t\t\t\t [=GAME-OVER=] "}, {"\t\t\t     You died in battle! "}, {"\t\t Don't give up hero, the world believes in you! "}};
    Footnote();
    for(auto& str : lph)
    {
        for(auto& ch : str)
        {
          lpct::prcolor<char>(lpct::colors::red, ch);
        }
        std::cout << std::endl;
    }

    sleep(2);

    sm->backMain();
}

enum class FightList
{
    fightATTACK = 1,
    fightSPECIAL = 2,
    fightINV = 3,
    fightRUN = 4,
};

void Fight(Hero& hero, std::string loc, StateMachine* sm)
{

    Enemy* p_enemy = Notification(hero, loc);

    bool confrontation = true;
	short getchoice;
    sm->add(confrontation);
    hero.resetSp = 2;

    while (confrontation)
	{
    clrcon();
		Solution(getchoice, p_enemy, hero);

		switch (getchoice)
		{
            case static_cast<int>(FightList::fightATTACK):
				Attack(hero, p_enemy, hero.getWeaponAttack());
				break;
            case static_cast<int>(FightList::fightSPECIAL):
                if(hero.resetSp > 0)
                    SignalAttackReset();
                else
                    Attack(hero, p_enemy, hero.getWeaponAttackS());
				break;
            case static_cast<int>(FightList::fightINV):
				Inventory(hero);
				break;
            case static_cast<int>(FightList::fightRUN):
                if(loc == location_collection[3])
                {
                    NoEscape();
                }
                else
                {
                    TryEscape(hero, p_enemy, confrontation);
                }
				break;
			default:
				ErrorMessage();
				break;
		}

		if (hero.getHealth() <= 0)
            LoseFight(sm);

		if (p_enemy->getHealth() <= 0 && hero.getHealth() > 0)
        {
            confrontation = WinFight(hero, p_enemy);
            hero.resetSp = 0;
        }
	}

    delete p_enemy;
}
