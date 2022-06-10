#include "ability.h"

namespace controller
{
	Ability::Ability(array<int,int(AB_END)> abilities)
	{
		_abilities = abilities;

//		_skills = {};
//		for(size_t i = {}; i < SKILLS.size(); ++i)
//		{
//			vector<Skill> newSkillRow = {};
//			for(size_t j = {}; j < SKILLS[i].size(); ++j)
//			{
//				newSkillRow.push_back(Skill(SKILLS[i][j]));
//			}
//			_skills.push_back(newSkillRow);
//		}
	}
	Ability::~Ability()
	{

	}

	int& Ability::GetAbility(Abilities ability)
	{
		return _abilities[ability];
	}

	int Ability::GetAbilityLevel(Abilities ability)
	{
		std::cout << "ab " << _abilities[ability] << std::endl;
		return ceil(double(_abilities[ability] * 0.5)) - 1;
	}

}
