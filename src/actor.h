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
		array<unsigned int, OS_END> _offensiveSkills;
		array<unsigned int, DS_END> _defensiveSkills;
		Health _health;
		Inventory _inventory;
		Condition _condition;
		Equipment _equipment;
		vector<Action> _actions;
		Vector3 _position;
		//Movement _movement;

	public:
		Actor(string name = "");
		~Actor();

		string& GetName();
		Ability& GetAbility();
		Vector3& GetPosition();

		double RollInitiative();
		vector<int> RollDice(int level);
		int GetActionPoints();
		void TakeDamage(unsigned int damage, BodyPart part);
		void UseAttackAction(OffensiveActions action, Actor& target);
		DefensiveActions GetBestDefense();
		unsigned int GetBestDefenseLevel();
		void UseMoveAction(Vector3 endPos);
	};
}
