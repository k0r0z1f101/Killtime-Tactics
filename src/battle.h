#pragma once
#include "raylib.h"
#include "actor.h"

#include <random>
#include <chrono>
#include <map>

using namespace std::chrono;

using std::vector;
using std::map;
using std::pair;
using std::multimap;
using std::chrono::system_clock;

namespace controller
{
	class BattleController
	{
	private:
		vector<Actor> _actors;
		multimap<double,Actor> _initiative;
		Actor _currentInit;
		int _currentTurn;
		system_clock::time_point _startTime;
		int _currentRound;

	public:
		BattleController();
		BattleController(vector<Actor>& actors);
		~BattleController();

		void RollInitiative();
		void StartCombat();
		void StartRound();
		void NextInitiative();
		Actor& GetCurrentInitiative();

		void UnitTest();
	};
}
