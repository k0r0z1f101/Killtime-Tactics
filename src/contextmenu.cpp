#include "contextmenu.h"

namespace controller
{
	ContextMenu::ContextMenu(Vector3& pos, vector<OffensiveActions>& actions)
	{
		_pos = pos;
		_actions = actions;
		_age = system_clock::now();
	}
	ContextMenu::~ContextMenu()
	{

	}

	float ContextMenu::UpdateMenu()
	{
		system_clock::time_point now = system_clock::now();
		auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(now - _age).count();
		cout << "time elapsed: " << std::chrono::duration_cast<std::chrono::microseconds>(now - _age).count() << endl;
		return float(elapsed);
	}
}
