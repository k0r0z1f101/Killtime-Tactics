#pragma once
#include "raylib.h"
#include "action.h"

#include <iostream>
#include <random>
#include <chrono>

using namespace std::chrono;

using std::vector;
using std::string;
using std::chrono::system_clock;

namespace controller
{
	static const unsigned int LIFESPAN = 5000000;

	class ContextMenu
	{
	private:
		Vector3 _pos;					//position at center of the carousel containing icons for the contextual menu
		vector<OffensiveActions> _actions;		//actions that will be converted to icons to compose the carousel
		system_clock::time_point _age;	//age in seconds of this contextual menu

	public:
		ContextMenu(Vector3& pos, vector<OffensiveActions>& actions);
		~ContextMenu();

		float UpdateMenu();
	};
}
