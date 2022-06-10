#pragma once
#include "raylib.h"

#include "ability.h"
#include "equipment.h"
#include "health.h"

#include <iostream>

using std::string;

namespace controller
{
	enum OffensiveActions
	{
		acOff_UnarmedMelee = 0,
		OA_END
	};

	static const array<int,OA_END> offensiveActionsCost = { 1 };
	static const array<Abilities,OA_END> offensiveActionsAbility = { Strength };

	enum DefensiveActions
	{
		acDef_UnarmedMelee = 0,
		DA_END
	};

	static const array<int,DA_END> defensiveActionsCost = { 1 };
	static const array<Abilities,OA_END> defensiveActionsAbility = { Strength };

	enum UtilityActions
	{
		acUtil_Move = 0,
		UA_END
	};

	static const array<int,UA_END> utilityActionsCost = { 1 };
	static const array<int,UA_END> utilityActionsAbility = { Agility };

	class Action
	{
	private:
		string _name;	//name of the action
		int _cost;		//action points needed

	public:
		Action();
		~Action();

//		//Attack and Defense
//		void Attack_Melee_Unarmed(/*Actor& target,*/ BodyPart bodyPart);
//		void Attack_Melee_Weapon(Equipment& weapon);
//		void Attack_Projectile_Weapon(Equipment& weapon);
//		void Defend_Melee_Unarmed(BodyPart bodyPart);
//		void Defend_Block(Equipment& shield);
//		void Defend_Parry(Equipment& weapon);
//		void Defend_Intercept(BodyPart bodyPart);
//		void Defend_Evade();
//		void Counter_Weapon(Equipment& weapon);
//		void Counter_Unarmed(BodyPart bodyPart);
//
//		//Movement
//		void Move(/*Movement moveType, */Vector3& startPos, Vector3 endPos);
	};
}
