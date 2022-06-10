#pragma once
#include "raylib.h"
#include "condition.h"

#include <array>
#include <iostream>

using std::array;
using std::cout;
using std::endl;

namespace controller
{
	enum BodyPart
	{
		Head = 0,
		LeftArm,
		RightArm,
		Body,
		LeftLeg,
		RightLeg,
		BP_END
	};

	class Health
	{
	private:
		array<int,int(BP_END)> _health;
		array<Conditions,int(BP_END)> _condition;
	public:
		Health(array<int,int(BP_END)> health = {}, array<Conditions,int(BP_END)> condition = {});
		~Health();

		void TakeDamage(int change, BodyPart part);
	};
}
