#pragma once
#include "raylib.h"

#include "equipment.h"
#include "health.h"

#include <iostream>

using std::string;

namespace controller
{
	class Action
	{
	private:
		string _name;	//name of the action
		int _cost;		//action points needed

	public:
		Action();
		~Action();

		void Attack_Melee_Unarmed(BodyPart bodyPart);
		void Attack_Melee_Weapon(Equipment& weapon);
		void Attack_Projectile_Weapon(Equipment& weapon);
		void Defend_Block(Equipment& shield);
		void Defend_Parry(Equipment& weapon);
		void Defend_Intercept(BodyPart bodyPart);
		void Defend_Evade();
		void Counter_Weapon(Equipment& weapon);
		void Counter_Unarmed(BodyPart bodyPart);
	};
}
