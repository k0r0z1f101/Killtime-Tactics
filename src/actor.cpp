#include "actor.h"

namespace controller
{

	Actor::Actor(string name)
	{
		_name = name;
		_actionPoints = {};
		_offensiveSkills = {};
		_defensiveSkills = {};
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

	DefensiveActions Actor::GetBestDefense()
	{
		unsigned int highest = {};
		unsigned int highestIndex = {};
		for(int i = {}; i < DA_END; ++i)
		{
			unsigned int abLvl = _abilities.GetAbilityLevel(defensiveActionsAbility[i]);
			abLvl += _defensiveSkills[i];
			highestIndex = highest < abLvl ? i : highestIndex;
			highest = highest < abLvl ? abLvl : highest;
		}
		return DefensiveActions(highestIndex);
	}

	unsigned int Actor::GetBestDefenseLevel()
	{
		unsigned int highest = {};
		for(int i = {}; i < DA_END; ++i)
		{
			unsigned int abLvl = _abilities.GetAbilityLevel(defensiveActionsAbility[i]);
			abLvl += _defensiveSkills[i];
			highest = highest < abLvl ? abLvl : highest;
		}
		return highest;
	}

	void Actor::TakeDamage(unsigned int damage, BodyPart part)
	{
		_health.TakeDamage(damage, part);
	}

	void Actor::UseAttackAction(OffensiveActions action, Actor& target)
	{
		//calculate attacker's offensive action associated skill
		unsigned int abLvl = _abilities.GetAbilityLevel(offensiveActionsAbility[action]);
		abLvl += _offensiveSkills[action];

		cout << "action: " << abLvl << endl;

		//roll attacker's attack
		vector<int> rollAttacker = RollDice(abLvl);
		unsigned int rollAttTotal = {};
		for (auto& n : rollAttacker)
			rollAttTotal += n;
		cout 	<< "Attacker: " << _name << endl
				<< "Roll total: " << rollAttTotal << endl;

		//find target's best defensive action and calculate associated skill
		DefensiveActions targetDef = target.GetBestDefense();
		unsigned int targetLvl = target.GetBestDefenseLevel();

		//roll target's defense
		vector<int> rollDefender = RollDice(targetLvl);
		unsigned int rollDefTotal = {};
		for (auto& n : rollDefender)
			rollDefTotal += n;
		cout 	<< "Defender: " << target.GetName() << endl
				<< "Roll total: " << rollDefTotal << endl;

		//calculate difference between both rolls
		int diff = rollAttTotal - rollDefTotal;
		if(diff < 0)
			return;

		//get a random body part if the attacker was not aiming
		BodyPart targetPart = BodyPart(rand() % BP_END);

		//apply damage to target
		target.TakeDamage(diff, targetPart);

		//apply any special effect to target

		//apply any special effect to attacker
	}

	void Actor::UseMoveAction(Vector3 endPos)
	{
		//move to end position one square at a time and check for traps and other
		_position = endPos; //temporary
	}

	vector<OffensiveActions> Actor::GetContextActions()
	{
		vector<OffensiveActions> offActions = {};
		for(int i = {}; i < OA_END; ++i)
			offActions.push_back(OffensiveActions(i));
		return offActions;
	}
}
