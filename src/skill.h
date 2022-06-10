#pragma once
#include "raylib.h"

#include <iostream>
#include <random>

using std::vector;
using std::string;

namespace controller
{
	enum OffensiveSkills
	{
		skOff_UnarmedMelee = 0,
		OS_END
	};

	enum DefensiveSkills
	{
		skDef_UnarmedMelee = 0,
		DS_END
	};

//	enum Skills
//	{
//		MeleeWeapon = 0, Projectile, ComplexWeapon,	Magic,			//offensives
//		Block, Dodge, Reflex, Endurance,							//defensives
//		Athletics, Stealth, Acrobatics, Ride, Steal, Academic,		//utilities
//		Reasoning, Navigation, Perception, Focus,					//utilities
//		Communication, Persuasion, Deception,						//socials
//		SKILLS_END
//	};
//
//	static const vector<vector<string>> SKILLS = {
//			{ "Melee Weapon", "Block", "Athletics", "Projectile" }, 								//Strength
//			{ "Melee Weapon", "Dodge", "Stealth", "Acrobatics", "Projectile", "Ride", "Steal" },	//Agility
//			{ "Endurance", "Block" },																//Constitution
//			{ "Reflex", "Dodge", "Steal" },															//Speed
//			{ "Academic", "Reasoning", "Complex Weapon", "Navigation", "Communication" },			//Intelligence
//			{ "Perception", "Focus", "Projectile" },												//Wisdom
//			{ "Persuasion", "Deception", "Communication" },											//Charisma
//			{ "Endurance" }																			//Will
//	};

	enum SkillType
	{
		None = -1,
		Offensive = 0,
		Defensive,
		Utility,
		Social,
		ST_END
	};

	class Skill
	{
	private:
		string _name;
		int _training;
		vector<SkillType> _type;
	public:
		Skill(string name, int training = {}, vector<SkillType> type = { None });
		~Skill();

		int& GetTraining();
		vector<SkillType>& GetType();
	};
}
