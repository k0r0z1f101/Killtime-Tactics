#include "health.h"

namespace controller
{
	Health::Health(array<int,int(BP_END)> health, array<Conditions,int(BP_END)> condition)
	{
		_health = health;
		_condition = condition;
	}
	Health::~Health(){};

	void Health::TakeDamage(int change, BodyPart part)
	{
		_health[part] += change;
		for(size_t i = {}; i < BP_END; ++i)
			cout << "part " << i << ": " << _health[i] << endl;
		//check part condition
		//check global health condition

		//bad conditions, limbs (arms, legs)
		//permanent conditions: amputated, destroyed, paralyzed, weakened
		//temporary conditions: broken, paralyzed, weakened
		//transitory conditions: bleeding, paralyzed, injured, weakened

		//limb disable conditions: injured, paralyzed, broken, amputated, destroyed


	}
}
