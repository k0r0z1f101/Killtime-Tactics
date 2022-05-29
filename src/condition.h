#pragma once
#include "raylib.h"

#include <random>

using std::vector;

namespace controller
{
	enum Conditions
	{
	};
	class Condition
	{
	public:
		Condition(vector<Conditions> conditions = {});
		~Condition();
	};
}
