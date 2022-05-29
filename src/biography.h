#pragma once
#include "raylib.h"

#include <iostream>

using std::string;

namespace controller
{
	class Biography
	{
	private:
		string _name;
		float _age;
	public:
		Biography(string name = "Generic Human", float age = 20.0f);
		~Biography();
	};
}
