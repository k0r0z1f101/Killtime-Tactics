#include "battle.h"

namespace controller
{
	BattleController::BattleController()
	{
		_currentTurn = {};
		_currentRound = {};
	}
	BattleController::~BattleController(){}

	void BattleController::RollInitiative()
	{
		_initiative = {};
		for(size_t i = {}; i < _actors.size(); ++i)
			_initiative.insert(pair<double, Actor>(_actors[i].RollInitiative(), _actors[i]));
	}

	void BattleController::StartCombat()
	{
		_startTime = system_clock::now();
		_currentRound = 1;
		_currentTurn = -1;
		StartRound();
		NextInitiative();
		cout << _currentInit.GetName() << endl;
		cout << _currentInit.GetActionPoints() << endl;
	}

	void BattleController::StartRound()
	{
		RollInitiative();
	}

	void BattleController::NextInitiative()
	{
		++_currentTurn;
		if(_currentTurn == int(_initiative.size()))
		{
			++_currentRound;
			StartRound();
			_currentTurn = {};
		}

		auto it = _initiative.rbegin();
		for(int i = {}; i < _currentTurn; ++i)
			++it;
		_currentInit = it->second;

		cout << "Round: " << _currentRound << endl;
		_actors[0].UseAttackAction(acOff_UnarmedMelee, _actors[1]);
	}

	void BattleController::UnitTest()
	{
		_actors.push_back(Actor("Jean"));
		_actors.push_back(Actor("Roger"));
		StartCombat();
	}
}
