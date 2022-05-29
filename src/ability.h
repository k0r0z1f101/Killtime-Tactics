#pragma once
#include "raylib.h"
#include "skill.h"

#include <array>
#include <math.h>
#include <random>

using std::cout;
using std::endl;
using std::array;
using std::string;
using std::vector;

namespace controller
{
	enum Abilities
	{
		Strength = 0,
		Agility = 1,
		Constitution,
		Speed,
		Intelligence,
		Wisdom,
		Charisma,
		Will,
		AB_END
	};
	static const int DICE_LEVEL = 14;
	static const int DICE_FORMAT = 2;
	static const int DICE[DICE_LEVEL][DICE_FORMAT] = {
			{ 1, 4 },  { 1, 6 },  { 1, 8 },  { 1, 10 }, { 1, 12 },	//1st tier, one attack per turn
			{ 2, 6 },  { 2, 8 },  { 2, 10 }, { 2, 12 },			//2nd tier, two attacks per turn
			{ 3, 8 },  { 3, 10 }, { 3, 12 },						//3rd tier, three attacks per turn
			{ 4, 10 }, { 4, 12 }								//4th tier, four attacks per turn
	};

	class Ability
	{
	private:
		array<int,int(AB_END)> _abilities;
		vector<vector<Skill>> _skills;
	public:
		Ability(array<int,int(AB_END)> abilities = { 2,2,2,2,2,2,2,2 });
		~Ability();

		int& GetAbility(Abilities ability);
		int GetAbilityLevel(Abilities ability);
	};
}
