#pragma once
#include "raylib.h"
#include "biography.h"
#include "race.h"
#include "skill.h"
#include "ability.h"
#include "health.h"
#include "inventory.h"
#include "condition.h"
#include "equipment.h"
#include "action.h"

#include <array>
#include <iostream>

using std::cout;
using std::endl;
using std::array;
using std::string;

namespace controller
{
	class Actor
	{
	private:
		string _name;
		int _actionPoints;
		Biography _biography;
		Race _race;
		Ability _abilities;
		Health _health;
		Inventory _inventory;
		Condition _condition;
		Equipment _equipment;
		vector<Action> _actions;
		//Movement _movement;

	public:
		Actor(string name = "");
		~Actor();

		string& GetName();
		Ability& GetAbility();

		double RollInitiative();
		vector<int> RollDice(int level);
		int GetActionPoints();
	};
}
