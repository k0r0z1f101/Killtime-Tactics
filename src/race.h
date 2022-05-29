#pragma once
#include "raylib.h"

namespace controller
{
	enum Races
	{
		NONE = -1,
		HUMAN = 0,
		LAST_RACE
	};
	class Race
	{
	private:
		Races _race;
	public:
		Race(Races race = HUMAN);
		~Race();

	};
}
