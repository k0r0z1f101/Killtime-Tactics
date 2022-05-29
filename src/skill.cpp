#include "skill.h"

namespace controller
{
	Skill::Skill(string name, int training, vector<SkillType> type)
	{
		_name = name;
		_training = training;
		_type = type;
	}
	Skill::~Skill()
	{

	}

	int& Skill::GetTraining()
	{
		return _training;
	}

	vector<SkillType>& Skill::GetType()
	{
		return _type;
	}
}
