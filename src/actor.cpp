#include "actor.h"

namespace controller
{

	Actor::Actor(string name)
	{
		_name = name;
		_actionPoints = {};
	}

	Actor::~Actor()
	{

	}

	Ability& Actor::GetAbility()
	{
		return _abilities;
	}

	double Actor::RollInitiative()
	{
		vector<int> dice = RollDice(GetAbility().GetAbilityLevel(Agility));
		int total = {};
		for(size_t i = 0; i < dice.size(); ++i)
		{
			total += dice[i];
		}
		return double(total);
	}

	vector<int> Actor::RollDice(int level)
	{
		vector<int> rolls = {};
		for(int i = {}; i < DICE[level][0]; ++i)
		{
			rolls.push_back(1 + (rand() % DICE[level][1]));
		}
		return rolls;
	}

	string& Actor::GetName()
	{
		return _name;
	}

	int Actor::GetActionPoints()
	{
		int lowest = 100;
		int highest = {};
		for(int i = {}; i < AB_END; ++i)
		{
			lowest = lowest > _abilities.GetAbility(Abilities(i)) ? _abilities.GetAbility(Abilities(i)) : lowest;
			highest = highest < _abilities.GetAbility(Abilities(i)) ? _abilities.GetAbility(Abilities(i)) : highest;
		}
		return (_abilities.GetAbility(Speed) + lowest + highest);
	}

	Vector3& Actor::GetPosition()
	{
		return _position;
	}

	void Actor::UseAttackAction(OffensiveActions action)
	{
		//calculate attacker's offensive action associated skill
		int abLvl = _abilities.GetAbilityLevel(offensiveActionsAbility[action]);

		//roll attacker's attack

		//find target's best defensive action and calculate associated skill

		//roll target's defense

		//calculate difference between both rolls

		//apply damage to target

		//apply any special effect to target

		//apply any special effect to attacker
	}
}
